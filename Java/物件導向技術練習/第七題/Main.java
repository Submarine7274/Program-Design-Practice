import  java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        int hours = sc.nextInt();
        int minutes = sc.nextInt();
        MyClassA a1 = new MyClassA(name, hours, minutes);
        String name2 = sc.next();
        int hours2 = sc.nextInt();
        int minutes2 = sc.nextInt();
        MyClassA a2 = new MyClassA(name2,hours2,minutes2);
        a1.equals(a2);
        sc.close();
    }
}
