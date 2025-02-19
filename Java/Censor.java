import java.util.Scanner;
public class Censor{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String output = input.replaceAll("#.*?#", "");//正則表達式.代表任意字符(除了換行)，*表示零或多個字元，？表示匹配最少字符
        System.out.println(output);
        sc.close();
    }
}