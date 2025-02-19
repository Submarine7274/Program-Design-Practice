import java.util.Scanner;
public class ToLowerCase {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine().toLowerCase();
        System.out.printf("%s",str);
        sc.close();
    }
}
