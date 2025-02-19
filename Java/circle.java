import java.util.Scanner;
public class circle {
    public static void main(String [] args){
        int x=0, y=0;
        double judge = 0;
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        y = sc.nextInt();
        judge = Math.sqrt((x*x) + (y*y));
        if(judge <= 100){
            System.out.print("inside");
        }
        else{
            System.out.print("outside");
        }
    }
}
