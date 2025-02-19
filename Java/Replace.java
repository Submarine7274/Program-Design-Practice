import java.util.Scanner;
public class Replace {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        String str3 = sc.nextLine();
        if(str1.indexOf(str2)>= 0){
            System.out.printf("%s", str1.replace(str2, str3));
        }
        else{
            System.out.printf("error");
            System.exit(0);
        }
        sc.close();
    }
}
