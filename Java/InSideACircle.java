import java.util.Scanner; 
public class InSideACircle {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int x =sc.nextInt();
        int y = sc.nextInt();
        sc.close();
        if(Math.sqrt((x*x) + (y*y)) <=100 ){
            System.out.print("inside");
        }
        else{
            System.out.print("outside");
        }
    }
}
