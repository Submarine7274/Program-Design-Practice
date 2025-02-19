import java.util.Scanner;
public class IndexOf {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        System.out.printf("%d", str1.indexOf(str2));
        sc.close();
    }
}
