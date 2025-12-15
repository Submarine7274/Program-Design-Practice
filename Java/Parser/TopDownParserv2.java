import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TopDownParserv2{
    private static final String lambda = "L";
    static class Production {
        int id;
        String lhs;
        List<String> rhs;

        public Production(int id, String lhs, List<String> rhs) {
            this.id = id;
            this.lhs = lhs;
            this.rhs = rhs;
        }

        @Override
        public String toString() {
            return id + ": " + lhs + " -> " + String.join(" ", rhs);
        }
    }
    static class Grammar {
        String startSymbol;
        Map<String, List<Production>> productions;//所有的規則Map
        Set<String> terminals;//terminal的集合
        Set<String> nonTerminals;// non-Terminal的集合
        
        Map<String, Set<String>> firstSets;
        Map<String, Set<String>> followSets;
        Map<Integer,Set<String>> predictSets;
        Map<String, Map<String, Production>> parseTable;
        
        boolean hasConflict = false; //檢查CFG本身有沒有衝突

        public Grammar() {
            productions = new LinkedHashMap<>();
            terminals = new HashSet<>();
            nonTerminals = new LinkedHashSet<>(); //用LinkedHashSet是為了保持順序
            firstSets = new HashMap<>();
            followSets = new HashMap<>();
            predictSets = new TreeMap<>();
            parseTable = new HashMap<>();
        }
    }

    public static Grammar readCFG(String filename) throws IOException{
        Grammar grammar = new Grammar();
        //FileInputStream開檔 InputStreamReader換成char以及指定編碼UTF-8 BufferedReader可以用readLine()
        BufferedReader br = new BufferedReader(new  InputStreamReader(new FileInputStream(filename)));
        String line;//半夜別打Line
        String currentLhs = null;//判斷目前lhs
        while((line = br.readLine())!= null){//br有讀到一行
            line =line.trim();//清除前後空白
            if (line.isEmpty()) continue;//空行進入下一個迴圈
            int currentId = -1;
            String[] splitBy2 = line.split("\\s+", 2); // 先切數字跟其他部分
            if(splitBy2.length >0 && splitBy2[0].matches("\\d+")){//切兩部分後是有東西的 而且第一個東西是數字
                currentId = Integer.parseInt(splitBy2[0]);//把字串的數字轉成數字並當成目前的行號
                if(splitBy2.length >1){
                    line = splitBy2[1].trim();//把line去掉前面數字部分與空白
                }
                else{
                    continue;//只有數字沒有內容
                }
            }
            else{
                currentId = -1;//如果出現沒有編號的規則
            }

            String rhs  = "";//處理規則部分
            if(line.contains(">")){//有>表示是規則的第一行
                String[] parts = line.split(">");//用>當切割點 左邊是規則名 右邊是衍伸物
                currentLhs = parts[0].trim();//目前lhs就是>的左邊
                if (grammar.startSymbol == null) {//沒有startSymbol的話 那第一個rule就是startSymbol
                    grammar.startSymbol = currentLhs;
                }
                grammar.nonTerminals.add(currentLhs);//把這個規則加到文法的non-nonTerminals裡
                grammar.productions.putIfAbsent(currentLhs, new ArrayList<>());//原本沒有這個規則的話 建立一個List準備放其他規則
                if(parts.length >1){//避免array找到失敗的位置 是預防只有S > 的狀況
                    rhs = parts[1].trim();
                }
            }
            else if(line.startsWith("|")){//如果是|開頭 代表是同個lhs的另一種衍伸規則
                if (currentLhs == null) continue; //如果之前沒讀到Lhs卻出現|的情況
                rhs = line.substring(1).trim();//把|去掉 剩下的就是rhs
            }
            String dealWithRhs = rhs;//來處理rhs
            List<String> symbols = new ArrayList<>();//建一個List把rhs的東西放進去
            String[] tokens = dealWithRhs.trim().split("\\s+");//把目前rhs去除前後空白 中間用空白分割 都當成一個token
            for(String token : tokens){//整理tokens
                if(!token.isEmpty()){//理論上不會有Empty 防禦而已
                    symbols.add(token);//把這個token放進去List裡面
                    if(!Character.isUpperCase(token.charAt(0))&&!token.equals(lambda)){//不是大寫開頭的也不是L
                        grammar.terminals.add(token);//放到terminal裡面
                    }
                }
            }
            if(!symbols.isEmpty()){//一樣是防禦
                Production prod = new Production(currentId,currentLhs, symbols);//建立一個Production物件 有ID以及他有甚麼符號
                grammar.productions.get(currentLhs).add(prod);//把這個Production 放到目前的lhs 然後放到grammar的productions的maps
            }

        }
        br.close();//關掉buffer reader 
        grammar.terminals.add("$");
        return grammar;
    }

    public static void findAllFirstSets(Grammar grammar){
        for(String nt: grammar.nonTerminals){//每個non-terminal都先給一個空的set
            grammar.firstSets.put(nt, new HashSet<>());
        }
        boolean changed =true;//一有更動就繼續迴圈的變數
        while(changed){
            changed = false;//先假設已經不會更動了
            for(String lhs:grammar.nonTerminals){//看grammar裡面所有的non-terminal
                if(findNewFirstSetsOfLhs(grammar,lhs)){
                    changed =true;
                }
            }
        }
    }
    private static Set<String> findAFirstSet(Grammar grammar,List<String> sequence){
        Set<String> result = new HashSet<>();
        boolean allderiveLambda = true;//如果整串規則全部衍伸成lambda的情況
        if(sequence.isEmpty()||(sequence.size()==1 &&sequence.get(0).equals(lambda))){//如果是空序列或者是Lambda
            result.add(lambda);
            return result;
        }
        for(String symbol: sequence){//看完整個序列裡面的符號
            if(grammar.terminals.contains(symbol)){//遇到terminal的情況
                result.add(symbol);//放到結果中 這是其中一個first set
                allderiveLambda = false;//不是全部都衍伸成lambda了
                break;
            }
            else if(grammar.nonTerminals.contains(symbol)){//遇到non-terminal
                Set<String> firstOfSym = grammar.firstSets.get(symbol);//那就去找non-terminal的first set
                if (firstOfSym == null) firstOfSym = new HashSet<>();//防禦上一句失敗的情況 基本上不會出現
                for(String s :firstOfSym){//把所有這個Symbol的first set看一遍
                    if(!s.equals(lambda)){//把不是Lambda的通通加進來
                        result.add(s);
                    }
                }
                if(!firstOfSym.contains(lambda)){//如果這個Symbol的first set沒有Lambda 表示一定有東西成為first set
                    allderiveLambda =false;
                    break;
                }
            }
            //如果還是有Lambda 就要繼續看序列中下一個符號了
        }
        if(allderiveLambda){
            result.add(lambda);
        }
        return result;
    }

    private static boolean findNewFirstSetsOfLhs(Grammar grammar, String lhs){
        boolean isChanged =false;
        List<Production> rules = grammar.productions.get(lhs);//拿出這個lhs所有的規則
        if(rules ==null ){return false;}//如果non-terminal沒有定義規則 基本上不會出現
        for(Production prod:rules){
            Set<String> isAFirstSet = findAFirstSet(grammar, prod.rhs);//把右邊的規則丟進去找First set 存到List裡面
            if(grammar.firstSets.get(lhs).addAll(isAFirstSet)){//把找到的所有first set 放到grammar的first set裡面
                isChanged = true;
            }
        }
        return isChanged;
    }
    private static Set<String> findAFollowSet_firstSetWithOutLambda(Grammar grammar, List<String> beta){
        Set<String>firstOfBeta = findAFirstSet(grammar, beta);//follow set是找後面那個字的first set
        Set<String> result = new HashSet<>(firstOfBeta);//把前面函式找到的放進去result
        result.remove(lambda);//這邊不會包含L
        return result;
    }
    private static boolean findNewFollowSetOfLhs(Grammar grammar, String lhs){
        boolean isChanged = false;
        List<Production> rules = grammar.productions.get(lhs);//把這個lhs的規則放到list裡面
        for(Production prod : rules){//把所有rule看過
            List<String> rhs = prod.rhs;//先提取出rhs就好
            for(int i = 0;i<rhs.size();i++){
                String symbol = rhs.get(i);//等等要比對的symbol
                if(!grammar.nonTerminals.contains(symbol)){//如果是terminal的話 就跳出這次迴圈 只需要考慮non-terminal
                    continue;
                }
                Set<String> targetFollow = grammar.followSets.get(symbol);//這個non-terminal的follow set
                int initialSize = targetFollow.size();//等等藉由比較size大小來決定有沒有新的follow set

                List<String> beta = new ArrayList<>();
                if(i +1< rhs.size()){//有後續的符號
                    beta = rhs.subList(i+1, rhs.size());//beta就是i+1字串到剩下的字串
                }
                Set<String>firstOfBeta = findAFirstSet(grammar, beta);//這裡會包含L
                targetFollow.addAll(findAFollowSet_firstSetWithOutLambda(grammar, beta));//這裡不包含L 函式會把L去掉
                if(firstOfBeta.contains(lambda)||beta.isEmpty()){//如果beta的first set有lambda 或者beta字串後面是空的
                    targetFollow.addAll(grammar.followSets.get(lhs));//那就要把那個lhs的follow set也放進去target的 follow set
                }
                if(targetFollow.size()>initialSize){//如果這個follow set的size比一開始大 代表有更動
                    isChanged = true;
                }
            }
        }
        return isChanged;
    }
    public static void findAllFollowSets(Grammar grammar){
        for(String nt: grammar.nonTerminals){//對所有的nonterminal 建立一個hashset
            grammar.followSets.put(nt, new HashSet<>());
        }
        if(grammar.startSymbol!= null){//把start symbol的follow set加上$
            grammar.followSets.get(grammar.startSymbol).add("$");
        }
        boolean isChanged = true;
        while(isChanged){
            isChanged = false;//預設這輪沒有更動
            for(String lhs: grammar.nonTerminals){
                if(findNewFollowSetOfLhs(grammar, lhs)){
                    isChanged =true;
                }
            }
        }
    }
    public static void findAllPredictSets(Grammar grammar){
        for(String lhs:grammar.productions.keySet()){//所有的lhs就是production的key
            for(Production prod: grammar.productions.get(lhs)){//所有的規則
                Set<String> predict = new HashSet<>();
                Set<String> firstOfRhs = findAFirstSet(grammar, prod.rhs);//先找這個規則rhs的first set
                for(String s :firstOfRhs){//除了lambda以外的first set都放到predict set裡面
                    if(!s.equals(lambda)){
                        predict.add(s);
                    }
                }
                if(firstOfRhs.contains(lambda)){
                    Set<String> follow = grammar.followSets.get(lhs);
                    if(follow !=null){//防禦性
                        predict.addAll(follow);
                    }
                }
                grammar.predictSets.put(prod.id,predict);
            }
        }
    }
    public static void buildParseTable(Grammar grammar){
        for(String nt :grammar.nonTerminals){//把所有的non-terminal放進去HashMap裡面
            grammar.parseTable.put(nt, new HashMap<>());
        }
        grammar.hasConflict =false;//初始化衝突的flag
        for(String lhs: grammar.productions.keySet()){//所有的lhs
            for(Production prod: grammar.productions.get(lhs)){//這個lhs的所有production
                Set<String> predict = grammar.predictSets.get(prod.id);
                if(predict ==null){//防禦性
                    continue;
                }
                
            }
        }
    }
    public static void main(String[] args){//main
        Scanner sc = new Scanner(System.in);//等等要讀輸入指令
        try {
            String filename = "";
            while(true){
                System.out.println("請輸入CFG檔名(包含副檔名.txt)");//提示
                filename = sc.nextLine().trim();//讀檔名
                if(!filename.isEmpty()){//有輸入檔名
                    break;//可以滾了
                }
                System.out.println("我需要那個酷酷的檔名");
            }
            System.out.println("正在讀取 " + filename + " ...");
            Grammar grammar = readCFG(filename);

            System.out.println("\n讀取結果驗證如下");
            System.out.println("起始符號: " + grammar.startSymbol);
            System.out.println("Non-Terminals: " + grammar.nonTerminals);
            System.out.println("Terminals: " + grammar.terminals);

            System.out.println("\n規則列表 (含行號)");
            for (String lhs : grammar.productions.keySet()) {// 遍歷這個 LHS 底下的所有規則
                for (Production prod : grammar.productions.get(lhs)) {
                    String rhsString = String.join(" ", prod.rhs);//把 RHS 的 List 轉成字串 (用空白隔開)
                    System.out.println("(" + prod.id + ") " + lhs + " -> " + rhsString);
                }
            }
            System.out.println("\nFIRST Sets");
            findAllFirstSets(grammar);
            for (String nt : grammar.nonTerminals) {
                System.out.println("FIRST(" + nt + ") = " + grammar.firstSets.get(nt));
            }
            System.out.println("\nFOLLOW Sets");
            findAllFollowSets(grammar); 
            for (String nt : grammar.nonTerminals) {
                System.out.println("FOLLOW(" + nt + ") = " + grammar.followSets.get(nt));
            }
            System.out.println("\nPREDICT Sets (含規則 ID)");
            findAllPredictSets(grammar);
            for (Map.Entry<Integer, Set<String>> entry : grammar.predictSets.entrySet()) {
                int id = entry.getKey();
                Set<String> pSet = entry.getValue();
                System.out.println("PREDICT(" + id + ") = " + pSet);
            }
            sc.close();
        } catch (IOException e) {
            System.err.println("I/O錯誤: " + e.getMessage());
            sc.close();
        }
    }
}
