import java.math.BigInteger;
import java.util.Scanner;

public class Fractorial {
    private int n;
    private BigInteger result;
    public Fractorial(int n){
        this.n = n;
        this.result = BigInteger.ONE;
    }
    public void calculator(){
        result = BigInteger.ONE;
        for(int i = 2; i <=n; i++){
            result = result.multiply(BigInteger.valueOf(i));
        }
    }
    public BigInteger getResult(){
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        if(number < 0){
            System.out.print("error");
        }
        else{
            Fractorial f = new Fractorial(number);
            f.calculator();
            System.out.print(f.getResult());
        }
        sc.close();
    }
}
