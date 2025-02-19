import java.util.Scanner;

public class AddIntDemo{
    public static void main(String[] args){
        Scanner keyin = new Scanner(System.in);
        int a=0, b=0;
        int result=0;
        a = keyin.nextInt();
        b = keyin.nextInt();
        result = a +b;
        System.out.printf("%d", result);
    }
}
