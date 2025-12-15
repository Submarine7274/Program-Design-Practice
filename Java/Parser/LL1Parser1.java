import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class LL1Parser1 {
    
    static class Production {
        int id;
        String lhs;
        List<String> rhs;

        Production(int id, String lhs, List<String> rhs) {
            this.id = id;
            this.lhs = lhs;
            this.rhs = rhs;
        }

        public String toString() {
            return id + ": " + lhs + " -> " + String.join(" ", rhs);
        }
    }

    static List<Production> productions = new ArrayList<>();
    static Set<String> nonTerminals = new LinkedHashSet<>();
    static Set<String> terminals = new HashSet<>();
    static Map<String, Set<String>> first = new HashMap<>();
    static Map<String, Set<String>> follow = new HashMap<>();
    static Map<String, Map<String, Production>> parseTable = new HashMap<>();
    static String startSymbol;

    /* ===================== CFG 讀取 ===================== */
    static void readCFG(String filename) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        String line;
        String lastLHS = null;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;

            // 先用空白切
            String[] tokens = line.split("\\s+");
            int id = Integer.parseInt(tokens[0]); // 第一個一定是編號

            // 情況 1： continuation production
            if (tokens[1].equals("|")) {
                if (lastLHS == null) throw new RuntimeException("Grammar format error: '|' without previous LHS");
                List<String> rhs = new ArrayList<>();
                for (int i = 2; i < tokens.length; i++) rhs.add(tokens[i]);
                productions.add(new Production(id, lastLHS, rhs));
            }
            // 情況 2： normal production
            else {
                String lhs = tokens[1];
                nonTerminals.add(lhs);
                if (productions.isEmpty()) startSymbol = lhs;
                lastLHS = lhs;

                // 找 >
                int arrowIndex = -1;
                for (int i = 0; i < tokens.length; i++) {
                    if (tokens[i].equals(">")) {
                        arrowIndex = i;
                        break;
                    }
                }
                if (arrowIndex == -1) throw new RuntimeException("Missing > in grammar line: " + line);

                List<String> rhs = new ArrayList<>();
                for (int i = arrowIndex + 1; i < tokens.length; i++) rhs.add(tokens[i]);
                productions.add(new Production(id, lhs, rhs));
            }
        }
        br.close();

        // 蒐集 terminals
        for (Production p : productions) {
            for (String s : p.rhs) {
                if (!s.equals("L") && !nonTerminals.contains(s)) terminals.add(s);
            }
        }
        terminals.add("$");
    }

    /* ===================== FIRST ===================== */
    static void computeFirst() {
        // 初始化 First 集合
        for (String t : terminals) {
            first.put(t, new HashSet<>(Collections.singleton(t)));
        }
        for (String nt : nonTerminals) {
            first.put(nt, new HashSet<>());
        }

        boolean changed;
        do {
            changed = false;
            for (Production p : productions) {
                Set<String> f = first.get(p.lhs);
                int before = f.size();
                
                Set<String> rhsFirst = computeRHSFirst(p.rhs);
                
                // 加入 First(alpha) - {L}
                f.addAll(withoutLambda(rhsFirst));
                
                // 如果 alpha 可空，則加入 L
                if (rhsFirst.contains("L")) {
                    f.add("L");
                }

                if (f.size() > before) changed = true;
            }
        } while (changed);
    }
    
    // 計算 RHS (alpha) 的 First 集合 (包含 L)
    static Set<String> computeRHSFirst(List<String> rhs) {
        Set<String> result = new HashSet<>();
        if (rhs.get(0).equals("L")) {
            result.add("L");
            return result;
        }

        boolean allNullable = true;
        for (String sym : rhs) {
            Set<String> symFirst = first.getOrDefault(sym, Collections.emptySet());
            result.addAll(withoutLambda(symFirst));
            
            if (!symFirst.contains("L")) {
                allNullable = false;
                break;
            }
        }
        
        if (allNullable) {
            result.add("L");
        }
        return result;
    }

    static Set<String> withoutLambda(Set<String> s) {
        Set<String> r = new HashSet<>(s);
        r.remove("L");
        return r;
    }

    /* ===================== FOLLOW ===================== */
    /* ===================== FOLLOW (修正版) ===================== */
static void computeFollow() {
    // 1. 初始化：所有非終結符的 Follow 集合都是空的 Set
    for (String nt : nonTerminals) {
        // 使用 computeFirst 初始化時確保了所有 First 集合存在
        // 這裡需要確保 follow 集合也存在
        follow.put(nt, new HashSet<>()); 
    }
    
    // 2. 規則 1：將 $ 加入起始符號的 Follow 集合
    follow.get(startSymbol).add("$");
    
    boolean changed;
    
    // 3. 規則 2 & 3：重複迭代直到不再有變化
    do {
        changed = false;
        for (Production p : productions) { // 對於 A -> alpha B beta
            List<String> rhs = p.rhs;
            
            for (int i = 0; i < rhs.size(); i++) {
                String B = rhs.get(i);
                
                if (!nonTerminals.contains(B)) continue; // 只有 B 是非終結符才計算

                Set<String> f = follow.get(B);
                int before = f.size();
                
                boolean betaIsNullable = true; // 追蹤 Beta 是否可空
                
                // (a) Beta = rhs.subList(i + 1, rhs.size())
                if (i + 1 < rhs.size()) {
                    List<String> beta = rhs.subList(i + 1, rhs.size());
                    
                    // 計算 First(Beta) - {L}
                    for (String sym : beta) {
                        Set<String> symFirst = first.getOrDefault(sym, Collections.emptySet());
                        f.addAll(withoutLambda(symFirst)); // 規則 2
                        
                        // 檢查 Beta 是否可空
                        if (!symFirst.contains("L")) {
                            betaIsNullable = false;
                            break;
                        }
                    }
                } 
                
                // (b) 如果 Beta 可空 (或 Beta 不存在，即 B 是最後一個符號)，則加入 Follow(A)
                if (betaIsNullable) { // 規則 3
                    f.addAll(follow.get(p.lhs));
                }
                
                if (f.size() > before) changed = true;
            }
        }
    } while (changed);
}


    /* ===================== Parse Table (修正邏輯) ===================== */
    static boolean hasConflict = false;
    static void buildParseTable() {
        for (String nt : nonTerminals) parseTable.put(nt, new HashMap<>());
        hasConflict = false; // 重設衝突標誌

        // 

        for (Production p : productions) {
            Set<String> predict = new HashSet<>();
            List<String> rhs = p.rhs;
            boolean rhsIsNullable = false; 

            if (rhs.get(0).equals("L")) {
                rhsIsNullable = true; // A -> L
            } else {
                rhsIsNullable = true;
                // 計算 First(rhs) - {L}
                for (String s : rhs) {
                    Set<String> sFirst = first.getOrDefault(s, Collections.emptySet());
                    predict.addAll(withoutLambda(sFirst));
                    
                    if (!sFirst.contains("L")) {
                        rhsIsNullable = false; // 遇到不可空的符號就停止
                        break;
                    }
                }
            }

            // 如果 rhs 可空，則加入 Follow(A)
            // Predict(A -> alpha) = (First(alpha) - {L}) ∪ (如果 alpha 可空，Follow(A))
            if (rhsIsNullable) {
                predict.addAll(follow.get(p.lhs));
            }

            // 填表 + 偵測衝突
            for (String t : predict) {
                Map<String, Production> row = parseTable.get(p.lhs);
                if (row.containsKey(t)) {
                    Production old = row.get(t);
                    System.out.println(
                        "LL(1) Conflict detected!\n" +
                        "Non-terminal: " + p.lhs + "\n" +
                        "Terminal: " + t + "\n" +
                        "Production " + old.id + " conflicts with Production " + p.id + "\n"
                    );
                    hasConflict = true;
                } else {
                    row.put(t, p);
                }
            }
        }

        if (hasConflict) {
            System.out.println("Grammar is NOT LL(1). Parse table has conflicts.\n");
        } else {
            System.out.println("Grammar is LL(1). Parse table constructed successfully.\n");
        }
    }

    /* ===================== Parser ===================== */
    static void parse(List<String> input) {
        Stack<String> stack = new Stack<>();
        stack.push("$");
        stack.push(startSymbol);

        int idx = 0;
        List<Integer> appliedRules = new ArrayList<>();

        System.out.println("\n--- Start Parsing ---");
        System.out.println("Stack\t\tInput\t\tAction");
        
        while (!stack.isEmpty()) {
            String top = stack.peek();
            
            // ===== 輸出當前狀態 =====
            String stackStr = String.join(" ", stack.stream().collect(Collectors.toList()));
            String inputStr = String.join(" ", input.subList(idx, input.size()));
            System.out.printf("%s\t%s\t", stackStr, inputStr);
            
            // ===== 安全取得 lookahead =====
            String lookahead;
            if (idx < input.size()) lookahead = input.get(idx);
            else lookahead = "$";
            
            // ===== top 是 terminal =====
            if (terminals.contains(top)) {
                if (top.equals(lookahead)) {
                    stack.pop();
                    idx++;
                    System.out.println("Match " + top);
                } else {
                    System.out.println("Error(Expected " + top + " but got " + lookahead + ")");
                    printRules(appliedRules);
                    return;
                }
            }
            // ===== top 是 non-terminal =====
            else {
                if (!parseTable.containsKey(top)) {
                    System.out.println("Error(Non-terminal " + top + " not found in table)");
                    printRules(appliedRules);
                    return;
                }
                
                Production p = parseTable.get(top).get(lookahead);
                
                if (p == null) {
                    System.out.println("Error(" + top + " vs. " + lookahead + " - No Rule)");
                    printRules(appliedRules);
                    return;
                }

                appliedRules.add(p.id);
                System.out.println("Apply Rule " + p.id + ": " + p.lhs + " -> " + String.join(" ", p.rhs));
                
                stack.pop();
                
                // 推入 RHS (反序)
                if (!p.rhs.get(0).equals("L")) {
                    for (int i = p.rhs.size() - 1; i >= 0; i--) {
                        stack.push(p.rhs.get(i));
                    }
                }
            }
        }
        
        System.out.println("--- End Parsing ---");
        printRules(appliedRules);
        System.out.println("Accept");
    }

    static void printRules(List<Integer> rules) {
        System.out.print("\nApplied Rules: ");
        for (int r : rules) System.out.print(r + " ");
        System.out.println();
    }

    /* ===================== 主程式 ===================== */
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("CFG filename: ");
        
        try {
            readCFG(sc.nextLine());
        } catch (FileNotFoundException e) {
            System.err.println("Error: File not found.");
            return;
        } catch (Exception e) {
            System.err.println("Grammar reading error: " + e.getMessage());
            return;
        }

        System.out.println("\n--- Computing First and Follow Sets ---");
        computeFirst();
        // 為了確保 Follow 集合計算正確，將 First 集合的輸出放在這裡
        System.out.println("\nFirst Sets:");
        for (String nt : nonTerminals) System.out.println(nt + ": " + first.get(nt));
        
        computeFollow();
        System.out.println("\nFollow Sets:");
        for (String nt : nonTerminals) System.out.println(nt + ": " + follow.get(nt));
        
        System.out.println("\n--- Building Parse Table ---");
        buildParseTable();

        // ===== 印 Parse Table（助教格式）=====
        List<String> termList = new ArrayList<>(terminals);
        termList.remove("$");
        Collections.sort(termList);
        termList.add("$");

        System.out.println("\n--- LL(1) Parse Table ---");
        // 表頭
        System.out.print("\t");
        for (String t : termList) System.out.print(t + "\t");
        System.out.println();

        // 每一列
        for (String nt : nonTerminals) {
            System.out.print(nt + "\t");
            for (String t : termList) {
                Production p = parseTable.get(nt).get(t);
                if (p == null) System.out.print("0\t"); // 0 代表 Error/Empty
                else System.out.print(p.id + "\t");
            }
            System.out.println();
        }
        System.out.println();

        /* 重複輸入 token string */
        while (true) {
            System.out.print("\nToken string (space-separated, or @filename, or exit): ");
            String line = sc.nextLine();
            if (line.equalsIgnoreCase("exit")) break;

            List<String> input = new ArrayList<>();
            if (line.startsWith("@")) {
                try {
                    //BufferedReader br = new new BufferedReader(new FileReader(line.substring(1)));
                    BufferedReader br = new BufferedReader(new FileReader(line.substring(1)));
                    String l;
                    while ((l = br.readLine()) != null) input.addAll(Arrays.asList(l.split("\\s+")));
                    br.close();
                } catch (FileNotFoundException e) {
                    System.err.println("Error: Input file not found.");
                    continue;
                }
            } else {
                input.addAll(Arrays.asList(line.split("\\s+")));
            }
            
            // 過濾空字串
            input.removeIf(String::isEmpty);

            if (!hasConflict) {
                parse(input);
            } else {
                System.out.println("Cannot parse: Grammar is NOT LL(1).");
            }
        }
        sc.close();
    }
}