import java.util.Scanner;
public class mstime{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        long ms = sc.nextLong();
        long secs = ms / 1000;
        long mins = secs / 60;
        long hours = mins /60;
        long days = hours /24;
        hours = (hours - (24 * days)) %24;
        mins =( mins - (60 * hours)) %60;
        secs =(int) ((secs -(60 *mins)) %60);
        System.out.printf("%d %d %d %d", days, hours, mins, secs);
    }
}