import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        int hours = sc.nextInt();
        int minutes = sc.nextInt();
        MyClassA a1 = new MyClassA(name, hours, minutes);
        a1.myPrint();
        sc.close();
    }
}
