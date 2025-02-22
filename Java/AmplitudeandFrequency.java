import java.util.Scanner;

public class AmplitudeandFrequency {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int amplitude = sc.nextInt();
        int frequency = sc.nextInt();
        
        if (amplitude == 0 || frequency == 0) {
            System.out.print("X");
        }
        else{
            for (int i = 1; i <= frequency; i++){
                if(i > 1){
                    System.out.printf("%n");
                }
                for(int k = 1; k <= amplitude; k++){
                    for(int j = 1; j <= k; j++){
                        System.out.printf("%d",k);
                    }
                    System.out.printf("%n");
                }

                for(int l = amplitude - 1; l >= 1; l--){
                    for(int j = 1; j <= l; j++){
                        System.out.printf("%d",l);
                    }
                    if (!(i == frequency && l == 1)) {
                        System.out.printf("%n");
                    }
                }   
            }
        }
        
        sc.close();
    }
}
