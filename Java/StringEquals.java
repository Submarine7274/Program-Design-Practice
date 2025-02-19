import java.util.Scanner;
public class StringEquals {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        if(str1.equals(str2)){
            System.out.printf("1");
        }
        else{
            System.out.printf("0");
        }
        sc.close();
    }
}
