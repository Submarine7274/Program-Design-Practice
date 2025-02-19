import java.util.Scanner;
public class Stringoutput {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        System.out.printf("Hello %s, how are you. %s is a undergraduate student.", name, name);
        sc.close();
    }
}
