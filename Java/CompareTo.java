import java.util.Scanner;
public class CompareTo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        if(str1.compareTo(str2)>0){
            System.out.printf("%s", str1);
        }
        else if(str1.compareTo(str2)==0){
            System.out.printf("0");
        }
        else{
            System.out.printf("%s", str2);
        }
        sc.close();
    }
}
