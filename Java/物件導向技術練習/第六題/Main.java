import  java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        int hours = sc.nextInt();
        int minutes = sc.nextInt();
        MyClassA a1 = new MyClassA(name, hours, minutes);
        MyClassA a2 = new MyClassA(a1);
        a1.myPrint();
        a2.myPrint();
        sc.close();
    }
}
