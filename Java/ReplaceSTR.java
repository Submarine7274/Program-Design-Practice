import java.util.Scanner;
public class ReplaceSTR {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        String str3 = sc.nextLine();
        str1 = str1.replaceAll("(?i)"+str2,str3);
        System.out.printf("%s", str1);
        sc.close();
    }
}