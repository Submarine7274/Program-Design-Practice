import java.util.Scanner;
public class RedeemCoupons{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int coupons = 0, candyBar = 0, gumball = 0, remain = 0;
        coupons = sc.nextInt();
        if (coupons > 10){
            candyBar = coupons / 10;
            gumball = (coupons % 10) / 3;
            remain = (coupons % 10) % 3;
        }
        else if(coupons > 3){
            candyBar = 0;
            gumball = coupons /3;
            remain = coupons %3;
        }
        else{
            candyBar = 0;
            gumball = 0;
            remain = coupons;
        }
        System.out.printf("%d %d %d", candyBar, gumball, remain);
    }
}