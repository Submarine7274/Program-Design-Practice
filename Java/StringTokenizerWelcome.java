import java.util.Scanner;
import java.util.StringTokenizer;

public class StringTokenizerWelcome {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        //System.out.println("請輸入姓名格式: 姓氏, 名字, 中間名(如果沒有請輸入None)");

        String inputLine = keyboard.nextLine();
        String delimiters = ", "; // 逗號和空格為分隔符號
        StringTokenizer nameFactory = new StringTokenizer(inputLine, delimiters);

        // 初始化變數，預設為 "None"
        String lastName = "None";
        String firstName = "None";
        String middleName = "None";

        if (nameFactory.hasMoreTokens()) lastName = nameFactory.nextToken();
        if (nameFactory.hasMoreTokens()) firstName = nameFactory.nextToken();
        if (nameFactory.hasMoreTokens()) middleName = nameFactory.nextToken();

        // 將 "None" 替換為空字串
        if (middleName.equalsIgnoreCase("None")) middleName = "";
        if (lastName.equalsIgnoreCase("None")) lastName = "";
        if (firstName.equalsIgnoreCase("None")) firstName = "";

        // 去除多餘空白並拼接非空字串
        String result = String.join(" ", firstName.trim(), middleName.trim(), lastName.trim()).trim().replaceAll("\\s+", " ");

        System.out.print("Hello " + result);
    }
}
