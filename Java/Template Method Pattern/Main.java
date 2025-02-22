import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //System.out.println("Enter transport type (1-Land, 2-Sea, 3-Air, 4-Car, 5-Train):");
        int transportType = sc.nextInt();
        
        //System.out.println("Enter load:");
        int load = sc.nextInt();

        TransportProcessTemplate tpt;

        switch (transportType) {
            case 1->{
                tpt = new LandTransport();
                tpt.Transport(load);
            }
            case 2->{
                tpt = new SeaTransport();
                tpt.Transport(load);
            }
                
            case 3->{
                tpt = new AirTransport();
                tpt.Transport(load);
            }
                
            case 4->{
                tpt = new Car();
                tpt.Transport(load);
            }
                
            case 5->{
                tpt = new Train();
                tpt.Transport(load);
            }
            default->
                System.out.println("Invalid transport type.");
        }
    }
}