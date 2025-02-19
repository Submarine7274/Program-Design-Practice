import java.util.Scanner;
public class StringSubString {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input =  sc.nextLine();
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.printf("%s", input.substring(x, y));
        sc.close();
    }
}