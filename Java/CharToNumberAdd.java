import java.util.Scanner;
public class CharToNumberAdd {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        if(sc.hasNext()){
            String line1 = sc.nextLine().toUpperCase();
            String line2 = sc.nextLine().toUpperCase();
            int number1 = convert(line1);
            int number2 = convert(line2);
            System.out.print(number1 + number2);
        }
        else{
            System.out.printf("Error");
        }
        sc.close();
    }
    public static int convert(String letters){
        int number = 0;
        for(int i = 0;i< letters.length();i++){
            char ch = letters.charAt(i);
            int digit = ch - 'A';  //來知道是第幾個字母
            if(digit >9){
                System.out.printf("Error");
                return 0;
            }
            else{
                number= number *10 +digit; //進位的概念
            }
        }
        return number;
    }
}
