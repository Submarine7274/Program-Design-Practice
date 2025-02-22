/*請參考範例程式，
輸入一行字，
並將這行字全部轉成大寫後輸出，
換行後，全部轉成小寫後再輸出。 */
import java.util.Scanner;
public class StringProcessor02 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String lower = line.toLowerCase();
        String upper = line.toUpperCase();
        System.out.println(upper);
        System.out.print(lower);
        sc.close();
    }
}
