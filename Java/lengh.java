import java.util.Scanner;
public class lengh{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        System.out.printf("%d", line.length());
        sc.close();
    }
}