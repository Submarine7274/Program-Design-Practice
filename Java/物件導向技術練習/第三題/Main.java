import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        int hour = sc.nextInt();
        int minutes = sc.nextInt();
        MyClassA a1 = new MyClassA(name,hour,minutes);
        a1.myPrint();
    }
}
