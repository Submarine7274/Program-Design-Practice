import java.util.Scanner;
public class CuttingPizza {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int cuts =0, slides;
        cuts = sc.nextInt();
        sc.close();
        slides = (((cuts +1) * cuts) /2) +1;
        System.out.print(slides);
    }
}
