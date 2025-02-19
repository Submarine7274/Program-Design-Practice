import java.util.Scanner;
public class CharAt {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int i = sc.nextInt();
        //System.out.printf("%d", str.length());
        if(i <= (str.length()-1)){
            System.out.printf("%s", str.charAt(i));
        }
        else{
            System.out.print("error");
        }
        sc.close();
    }
}