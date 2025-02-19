import java.util.Scanner;
public class Systemout {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();
        System.out.printf("You are %d years old.", age);
        sc.close();
    }
}