import java.util.Scanner;
public class coin {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int value;
        //sc = sc.useDelimiter("\n");
        int x = sc.nextInt();
        sc.nextLine();
        int y = sc.nextInt();
        sc.nextLine();
        value = x + 5*y;
        System.out.printf("%d", value);
    }
}
