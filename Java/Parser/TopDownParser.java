import java.io.*;
import java.util.*;

public class TopDownParser {

    private static final String EPSILON = "L"; // 空字串符號
    private static final int MAX_STEPS = 5000; // 防止無窮迴圈的強制停止點

    static class Grammar {
        String startSymbol;
        Map<String, List<List<String>>> productions;
        Set<String> terminals;
        Set<String> nonTerminals;
        Map<String, Set<String>> firstSets;
        Map<String, Set<String>> followSets;
        Map<String, Map<String, List<String>>> parseTable;

        Grammar() {
            productions = new LinkedHashMap<>();
            terminals = new HashSet<>();
            nonTerminals = new HashSet<>();
            firstSets = new HashMap<>();
            followSets = new HashMap<>();
            parseTable = new HashMap<>();
        }
    }

    // --- 讀取文法 (與之前相同) ---
    public static Grammar readCFG(String filename) throws IOException {
        Grammar grammar = new Grammar();
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(filename), "UTF-8"));
        String line;
        
        Set<String> allSymbolsInRHS = new HashSet<>();
        String currentLhs = null; // 用來記錄當前正在處理的 LHS

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;

            String rhsPart = "";

            // 情況 1: 這一行有 '>'，代表新的規則開始
            if (line.contains(">")) {
                String[] parts = line.split(">");
                // 處理 LHS (去除前面的編號)
                String lhsRaw = parts[0].trim();
                String[] lhsTokens = lhsRaw.split("\\s+");
                currentLhs = lhsTokens[lhsTokens.length - 1]; // 取最後一個字當作 Non-terminal

                if (grammar.startSymbol == null) {
                    grammar.startSymbol = currentLhs;
                }

                grammar.nonTerminals.add(currentLhs);
                grammar.productions.putIfAbsent(currentLhs, new ArrayList<>());

                if (parts.length > 1) {
                    rhsPart = parts[1].trim();
                }
            } 
            // 情況 2: 這一行以 '|' 開頭，代表接續上一條規則
            else if (line.startsWith("|")) {
                if (currentLhs == null) {
                    continue; // 忽略沒有 LHS 的孤兒行
                }
                rhsPart = line.substring(1).trim(); // 去掉 '|'
            }
            else {
                continue; // 忽略不符合格式的行
            }

            // 解析 RHS (支援一行內還有多個 | 的情況)
            String[] alternatives = rhsPart.split("\\|");

            for (String alt : alternatives) {
                List<String> symbols = new ArrayList<>();
                String[] tokens = alt.trim().split("\\s+");

                for (String token : tokens) {
                    if (!token.isEmpty()) {
                        symbols.add(token);
                        allSymbolsInRHS.add(token);

                        if (!Character.isUpperCase(token.charAt(0)) && !token.equals(EPSILON)) {
                            grammar.terminals.add(token);
                        }
                    }
                }
                // 只有非空的規則才加入
                if (!symbols.isEmpty()) {
                    grammar.productions.get(currentLhs).add(symbols);
                }
            }
        }
        br.close();

        grammar.terminals.add("$");

        // 檢查未定義的符號
        for (String sym : allSymbolsInRHS) {
            if (Character.isUpperCase(sym.charAt(0)) && !grammar.nonTerminals.contains(sym) && !sym.equals(EPSILON)) {
                grammar.terminals.add(sym);
            }
        }

        return grammar;
    }

    // --- 新增：靜態檢查左遞迴 ---
    public static boolean checkLeftRecursion(Grammar grammar) {
        boolean foundProblem = false;
        for (String nt : grammar.nonTerminals) {
            for (List<String> rule : grammar.productions.get(nt)) {
                // 如果規則的第一個符號就是自己 (例如 E -> E + P)
                if (!rule.isEmpty() && rule.get(0).equals(nt)) {
                    System.err.println("【嚴重錯誤】偵測到直接左遞迴 (Direct Left Recursion):");
                    System.err.println("  規則: " + formatProduction(nt, rule));
                    System.err.println("  說明: LL(1) Parser 無法處理左遞迴，這會導致無窮迴圈。請修改文法 (例如改為右遞迴)。\n");
                    foundProblem = true;
                }
            }
        }
        return foundProblem;
    }

    // --- FIRST 集合計算 ---
    public static void computeFirstSets(Grammar grammar) {
        for (String nt : grammar.nonTerminals) grammar.firstSets.put(nt, new HashSet<>());
        boolean changed = true;
        while (changed) {
            changed = false;
            for (String lhs : grammar.productions.keySet()) {
                for (List<String> production : grammar.productions.get(lhs)) {
                    Set<String> currentFirst = new HashSet<>();
                    boolean allNullable = true;
                    if (production.isEmpty() || (production.size() == 1 && production.get(0).equals(EPSILON))) {
                        currentFirst.add(EPSILON);
                    } else {
                        for (String symbol : production) {
                            if (grammar.terminals.contains(symbol)) {
                                currentFirst.add(symbol);
                                allNullable = false;
                                break;
                            } else if (grammar.nonTerminals.contains(symbol)) {
                                Set<String> f = grammar.firstSets.get(symbol);
                                for (String s : f) if (!s.equals(EPSILON)) currentFirst.add(s);
                                if (!f.contains(EPSILON)) {
                                    allNullable = false;
                                    break;
                                }
                            }
                        }
                        if (allNullable) currentFirst.add(EPSILON);
                    }
                    if (grammar.firstSets.get(lhs).addAll(currentFirst)) changed = true;
                }
            }
        }
    }

    // --- FOLLOW 集合計算 ---
    public static void computeFollowSets(Grammar grammar) {
        for (String nt : grammar.nonTerminals) grammar.followSets.put(nt, new HashSet<>());
        grammar.followSets.get(grammar.startSymbol).add("$");
        boolean changed = true;
        while (changed) {
            changed = false;
            for (String lhs : grammar.productions.keySet()) {
                for (List<String> production : grammar.productions.get(lhs)) {
                    for (int i = 0; i < production.size(); i++) {
                        String symbol = production.get(i);
                        if (!grammar.nonTerminals.contains(symbol)) continue;
                        Set<String> targetFollow = grammar.followSets.get(symbol);
                        int initialSize = targetFollow.size();
                        Set<String> firstOfNext = new HashSet<>();
                        boolean nextIsNullable = true;
                        for (int j = i + 1; j < production.size(); j++) {
                            String next = production.get(j);
                            if (grammar.terminals.contains(next)) {
                                firstOfNext.add(next);
                                nextIsNullable = false;
                                break;
                            } else if (grammar.nonTerminals.contains(next)) {
                                Set<String> f = grammar.firstSets.get(next);
                                for (String s : f) if (!s.equals(EPSILON)) firstOfNext.add(s);
                                if (!f.contains(EPSILON)) {
                                    nextIsNullable = false;
                                    break;
                                }
                            }
                        }
                        targetFollow.addAll(firstOfNext);
                        if (nextIsNullable) targetFollow.addAll(grammar.followSets.get(lhs));
                        if (targetFollow.size() > initialSize) changed = true;
                    }
                }
            }
        }
    }

    // --- 建立 Parse Table (含詳細衝突解釋) ---
    public static boolean buildParseTable(Grammar grammar) {
        boolean hasConflict = false;
        for (String nt : grammar.nonTerminals) grammar.parseTable.put(nt, new HashMap<>());

        for (String lhs : grammar.productions.keySet()) {
            for (List<String> production : grammar.productions.get(lhs)) {
                Set<String> firstOfProduction = new HashSet<>();
                boolean allNullable = true;
                if (production.isEmpty() || (production.size() == 1 && production.get(0).equals(EPSILON))) {
                    firstOfProduction.add(EPSILON);
                } else {
                    for (String symbol : production) {
                        if (grammar.terminals.contains(symbol)) {
                            firstOfProduction.add(symbol);
                            allNullable = false;
                            break;
                        } else if (grammar.nonTerminals.contains(symbol)) {
                            Set<String> f = grammar.firstSets.get(symbol);
                            for (String s : f) if (!s.equals(EPSILON)) firstOfProduction.add(s);
                            if (!f.contains(EPSILON)) {
                                allNullable = false;
                                break;
                            }
                        }
                    }
                    if (allNullable) firstOfProduction.add(EPSILON);
                }

                for (String terminal : firstOfProduction) {
                    if (!terminal.equals(EPSILON)) {
                        if (addEntryToTable(grammar, lhs, terminal, production)) hasConflict = true;
                    }
                }
                if (firstOfProduction.contains(EPSILON)) {
                    for (String follow : grammar.followSets.get(lhs)) {
                        if (addEntryToTable(grammar, lhs, follow, production)) hasConflict = true;
                    }
                }
            }
        }
        return hasConflict;
    }

    // --- 寫入表格並回報衝突原因 ---
    private static boolean addEntryToTable(Grammar grammar, String nonTerminal, String terminal, List<String> production) {
        Map<String, List<String>> row = grammar.parseTable.get(nonTerminal);
        if (row.containsKey(terminal)) {
            List<String> existing = row.get(terminal);
            if (!existing.equals(production)) {
                System.err.printf("【LL(1) 表格衝突】Non-terminal [%s] 遇到輸入 [%s] 時有兩條路徑:\n", nonTerminal, terminal);
                System.err.println("  路徑 1 (原): " + formatProduction(nonTerminal, existing));
                System.err.println("  路徑 2 (新): " + formatProduction(nonTerminal, production));
                
                // 嘗試分析原因
                if (!existing.isEmpty() && !production.isEmpty() && existing.get(0).equals(production.get(0))) {
                     System.err.println("  >> 原因分析: 發現「共同前綴 (Common Prefix)」。需要提取左因子 (Left Factoring)。");
                } else {
                     System.err.println("  >> 原因分析: 文法具有歧義 (Ambiguity) 或 FIRST/FOLLOW 集合重疊。");
                }
                System.err.println();
                return true; // 發生衝突
            }
        } else {
            row.put(terminal, production);
        }
        return false;
    }

    private static String formatProduction(String lhs, List<String> rhs) {
        String rhsStr = (rhs.size() == 1 && rhs.get(0).equals(EPSILON)) ? "L" : String.join(" ", rhs);
        return lhs + " > " + rhsStr;
    }

    public static void printParseTable(Grammar grammar) {
        System.out.println("\nParse table:");
        List<String> terminalList = new ArrayList<>(grammar.terminals);
        Collections.sort(terminalList, (a, b) -> {
            if (a.equals("$")) return 1;
            if (b.equals("$")) return -1;
            return a.compareTo(b);
        });

        System.out.printf("%-10s", "");
        for (String t : terminalList) System.out.printf("%-20s", t);
        System.out.println();

        for (String nt : grammar.productions.keySet()) {
            System.out.printf("%-10s", nt);
            for (String t : terminalList) {
                Map<String, List<String>> row = grammar.parseTable.get(nt);
                if (row != null && row.containsKey(t)) {
                    List<String> prod = row.get(t);
                    String rhs = (prod.size() == 1 && prod.get(0).equals(EPSILON)) ? "L" : String.join(" ", prod);
                    System.out.printf("%-20s", nt + "->" + rhs);
                } else {
                    System.out.printf("%-20s", "");
                }
            }
            System.out.println();
        }
    }

    // --- Parser 執行 (含無窮迴圈保護) ---
    public static void parseString(Grammar grammar, String inputStr) {
        System.out.println("\nProcessing: " + inputStr);
        Queue<String> inputQueue = new LinkedList<>();
        String[] tokens = inputStr.trim().split("\\s+");
        for (String t : tokens) {
            if (!t.isEmpty()) inputQueue.add(t);
        }
        inputQueue.add("$");

        Stack<String> stack = new Stack<>();
        stack.push("$");
        stack.push(grammar.startSymbol);

        int steps = 0; // 步驟計數器

        while (!stack.isEmpty()) {
            steps++;
            if (steps > MAX_STEPS) {
                System.out.println("Error(Infinite Loop Detected)");
                System.out.println("  >> 原因: 推導步驟超過 " + MAX_STEPS + " 次。通常是因為文法中有左遞迴 (Left Recursion) 或空轉移迴圈。");
                return;
            }

            String top = stack.peek();
            String currentInput = inputQueue.peek();

            if (top.equals("$") && currentInput.equals("$")) {
                stack.pop();
                System.out.println("Accept");
                return;
            }

            if (grammar.terminals.contains(top)) {
                if (top.equals(currentInput)) {
                    stack.pop();
                    inputQueue.poll();
                } else {
                    System.out.println("Error(Expected token: " + top + ", but got: " + currentInput + ")");
                    return;
                }
            } else if (grammar.nonTerminals.contains(top)) {
                Map<String, List<String>> row = grammar.parseTable.get(top);
                if (row != null && row.containsKey(currentInput)) {
                    List<String> production = row.get(currentInput);
                    stack.pop();
                    String rhsStr = (production.size() == 1 && production.get(0).equals(EPSILON)) ? "L" : String.join(" ", production);
                    System.out.println(top + " > " + rhsStr);

                    if (!(production.size() == 1 && production.get(0).equals(EPSILON))) {
                        for (int i = production.size() - 1; i >= 0; i--) {
                            stack.push(production.get(i));
                        }
                    }
                } else {
                    System.out.println("Error(" + top + " vs. " + currentInput + ")");
                    System.out.println("  >> 原因: Parse Table 中 [" + top + ", " + currentInput + "] 為空。表示目前的輸入不符合文法預期。");
                    return;
                }
            } else {
                System.out.println("Error(Unknown symbol in stack: " + top + ")");
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("請輸入CFG檔名 (例如 grammar.txt): ");
            String filename = scanner.nextLine().trim();
            if (filename.isEmpty()) filename = "grammar.txt";

            Grammar grammar = readCFG(filename);

            // 1. 檢查左遞迴
            boolean hasLeftRecursion = checkLeftRecursion(grammar);
            
            computeFirstSets(grammar);
            computeFollowSets(grammar);
            
            // 2. 建立表格並檢查 LL(1) 衝突
            boolean hasConflict = buildParseTable(grammar);

            printParseTable(grammar);

            if (hasLeftRecursion || hasConflict) {
                System.out.println("\n【警告】文法驗證失敗 (發現左遞迴或衝突)。");
                System.out.println("Parser 仍然會嘗試執行，但結果極可能錯誤 (無窮迴圈或誤判)。");
            }

            while (true) {
                System.out.print("\n請輸入 Token string (輸入 'exit' 結束): ");
                String input = scanner.nextLine().trim();
                if (input.equalsIgnoreCase("exit")) break;
                if (!input.isEmpty()) {
                    parseString(grammar, input);
                }
            }

        } catch (IOException e) {
            System.err.println("讀取 CFG 錯誤: " + e.getMessage());
        }
    }
}