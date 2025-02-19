import java.util.Scanner;
public class tax {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        float income = sc.nextFloat();
        float tax = 0.00f;
        if(income < 15000){
            tax = 0.00f;
        }
        else if(income >=15000 && income <30000){
            tax = (income - 15000) * 0.05f;
        }
        else if(income >=30000){
            tax = (15000 * 0.05f) + ((income-30000) *0.1f);
        }
        System.out.printf("%.2f", tax);
        sc.close();
    }
}