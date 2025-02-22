import java.util.Scanner;
public class Narcissisticnumber {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        sc.close();
        int original =number;
        int isnarcissisticnumber = 0;
        int digits = String.valueOf(number).length();
        while(number >0){
            int digit = number %10;
            isnarcissisticnumber += Math.pow(digit, digits);
            number /=10;
        }
        if(original == isnarcissisticnumber){
            System.out.print("YES");
        }
        else{
            System.out.print("NO");
        }
    }
}
