import java.util.Scanner;
public class SubString {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.printf("%s", str.substring(x,y));     // 包含x，不包含y(只到y-1的位置)
        sc.close();
    }
}