import  java.util.Scanner;
public class StrEqual {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        if(str1.equals(str2)){
            System.out.print("1");
        }
        else{
            System.out.print("0");
        }
    }
}
