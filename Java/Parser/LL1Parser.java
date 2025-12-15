import java.io.*;
import java.util.*;

public class LL1Parser {

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
            if (lastLHS == null)
                throw new RuntimeException("Grammar format error: '|' without previous LHS");

            List<String> rhs = new ArrayList<>();
            for (int i = 2; i < tokens.length; i++)
                rhs.add(tokens[i]);

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
            if (arrowIndex == -1)
                throw new RuntimeException("Missing > in grammar line: " + line);

            List<String> rhs = new ArrayList<>();
            for (int i = arrowIndex + 1; i < tokens.length; i++)
                rhs.add(tokens[i]);

            productions.add(new Production(id, lhs, rhs));
        }
    }
    br.close();

    // 蒐集 terminals
    for (Production p : productions) {
        for (String s : p.rhs) {
            if (!s.equals("L") && !nonTerminals.contains(s))
                terminals.add(s);
        }
    }
    terminals.add("$");
}


    /* ===================== FIRST ===================== */

    static void computeFirst() {
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

                if (p.rhs.get(0).equals("L")) {
                    f.add("L");
                } else {
                    for (String sym : p.rhs) {
                        f.addAll(withoutLambda(first.get(sym)));
                        if (!first.get(sym).contains("L")) break;
                    }
                }
                if (f.size() > before) changed = true;
            }
        } while (changed);
    }

    static Set<String> withoutLambda(Set<String> s) {
        Set<String> r = new HashSet<>(s);
        r.remove("L");
        return r;
    }

    /* ===================== FOLLOW ===================== */

    static void computeFollow() {
        for (String nt : nonTerminals)
            follow.put(nt, new HashSet<>());

        follow.get(startSymbol).add("$");

        boolean changed;
        do {
            changed = false;
            for (Production p : productions) {
                List<String> rhs = p.rhs;
                for (int i = 0; i < rhs.size(); i++) {
                    String B = rhs.get(i);
                    if (!nonTerminals.contains(B)) continue;

                    Set<String> f = follow.get(B);
                    int before = f.size();

                    if (i + 1 < rhs.size()) {
                        String beta = rhs.get(i + 1);
                        f.addAll(withoutLambda(first.get(beta)));
                        if (first.get(beta).contains("L"))
                            f.addAll(follow.get(p.lhs));
                    } else {
                        f.addAll(follow.get(p.lhs));
                    }
                    if (f.size() > before) changed = true;
                }
            }
        } while (changed);
    }

    /* ===================== Parse Table ===================== */

    static void buildParseTable() {
        for (String nt : nonTerminals)
            parseTable.put(nt, new HashMap<>());

        for (Production p : productions) {
            Set<String> predict = new HashSet<>();

            if (p.rhs.get(0).equals("L")) {
                predict.addAll(follow.get(p.lhs));
            } else {
                for (String s : p.rhs) {
                    predict.addAll(withoutLambda(first.get(s)));
                    if (!first.get(s).contains("L")) break;
                }
            }

            for (String t : predict)
                parseTable.get(p.lhs).put(t, p);
        }
    }

    /* ===================== Parser ===================== */

    static void parse(List<String> input) {
        Stack<String> stack = new Stack<>();
        stack.push("$");
        stack.push(startSymbol);

        int idx = 0;
        System.out.println("\nApplying rules:");

        while (!stack.isEmpty()) {
            String top = stack.peek();
            String lookahead = input.get(idx);

            if (terminals.contains(top)) {
                if (top.equals(lookahead)) {
                    stack.pop();
                    idx++;
                } else {
                    System.out.println("Error(Expected token)");
                    return;
                }
            } else {
                Production p = parseTable.get(top).get(lookahead);
                if (p == null) {
                    System.out.println("Error(Non-terminal vs. Terminal)");
                    return;
                }
                stack.pop();
                System.out.println(p);
                if (!p.rhs.get(0).equals("L")) {
                    for (int i = p.rhs.size() - 1; i >= 0; i--)
                        stack.push(p.rhs.get(i));
                }
            }
        }
        System.out.println("Accept");
    }

    /* ===================== 主程式 ===================== */

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("CFG filename: ");
        readCFG(sc.nextLine());

        computeFirst();
        computeFollow();
        buildParseTable();

        /* 印 Parse Table */
        List<String> termList = new ArrayList<>(terminals);
        termList.remove("$");
        Collections.sort(termList);
        termList.add("$");

        System.out.println("\nParse Table:");
        System.out.print("\t");
        for (String t : termList) System.out.print(t + "\t");
        System.out.println();

        for (String nt : nonTerminals) {
            System.out.print(nt + "\t");
            for (String t : termList) {
                Production p = parseTable.get(nt).get(t);
                System.out.print((p == null ? "" : p.id) + "\t");
            }
            System.out.println();
        }

        /* 重複輸入 token string */
        while (true) {
            System.out.print("\nToken string (or exit): ");
            String line = sc.nextLine();
            if (line.equalsIgnoreCase("exit")) break;

            List<String> input = new ArrayList<>();
            if (line.startsWith("@")) {
                BufferedReader br = new BufferedReader(new FileReader(line.substring(1)));
                String l;
                while ((l = br.readLine()) != null)
                    input.addAll(Arrays.asList(l.split("\\s+")));
                br.close();
            } else {
                input.addAll(Arrays.asList(line.split("\\s+")));
            }
            parse(input);
        }
    }
}
