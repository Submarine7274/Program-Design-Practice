import java.math.BigInteger;
import java.util.Scanner;
public class Factorial{
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long num = 0;
    BigInteger result =BigInteger.ONE;
    num = sc.nextLong();
    if(num < 0){
        System.out.printf("out of border");
    }
    else{
        for(long i = 2; i <= num; i++){
            result = result.multiply(BigInteger.valueOf(i));
        }
    }
    System.out.println(result);       //Java的long用%d格式就好，我後面改成BigInteger了
}
}