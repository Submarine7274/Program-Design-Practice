import java.util.Scanner;
public class gas{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int distance = sc.nextInt();
        double fuelEfficiency = sc.nextDouble();
        double fuelNeeded =((double) distance / fuelEfficiency);
        System.out.printf("%.2f", fuelNeeded);
    }
}