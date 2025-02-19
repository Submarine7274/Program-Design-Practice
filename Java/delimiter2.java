import java.util.Scanner;
public class delimiter2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("#|\\n");
        String st1 = sc.next();
        String st2 = sc.next();
        String st3 = sc.next();
        System.out.println(st1);
        System.out.println(st2);
        System.out.println(st3);
        sc.close();
    }
}
