import java.util.Scanner;
public class Longnumber{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long number = sc.nextLong();
        if(String.valueOf(number).length() >= 11 && String.valueOf(number).length() <= 19){
            int lastdigit = (int) (number % 10);
            System.out.print(lastdigit);
        }
        sc.close();
    }
}