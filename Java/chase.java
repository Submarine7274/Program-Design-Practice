import java.util.Scanner;
public class chase {
    public static void main (String[] args){
        double mySpeed = 1.0, hhSpeeed = 2.54 *30 /100;
        int itime = 0;
        Scanner sc = new Scanner(System.in);
        double distance = sc.nextDouble();
        double time = distance / (mySpeed - hhSpeeed);
        if(time - (int) time >0){
            itime = (int)(time +1);
        }
        System.out.print(itime);
    }
}
