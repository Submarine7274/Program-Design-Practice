import java.util.Scanner;
public class minute {
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int sec = 0, min = 0, hour = 0, day = 0;
        sec = sc.nextInt();
        if(sec >60){
            min = sec /60;
            if(min > 60){
                hour = min / 60;
                min = min %60;
                if(hour >24){
                    day = hour / 24;
                    hour = hour % 24;
                }
            }
        }
        System.out.print(min);
    }
}
