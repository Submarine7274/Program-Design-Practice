import java.util.Scanner;
public class Addint {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.printf("%d add %d are %d.", x, y, x+y);
        sc.close();
    }
}
