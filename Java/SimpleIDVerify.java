import java.util.Scanner;
public class SimpleIDVerify {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String id = sc.nextLine();
        if( (id.length() == 10) && 
        ((id.charAt(1) =='1')||(id.charAt(1)=='2')) && 
        ((id.charAt(0)>='A') && (id.charAt(0) <= 'Z'))){
            System.out.printf("1");
        }
        else{
            System.out.printf("0");
        }
        sc.close();
    }
}
