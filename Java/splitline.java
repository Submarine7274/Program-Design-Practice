import java.util.Scanner;
public class splitline {
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        int firstSpace = input.indexOf(' ');
        int secondSpace = input.indexOf(' ', firstSpace +1);
        if(firstSpace != -1 && secondSpace != -1){
            String between = input.substring(firstSpace +1, secondSpace);
            String after = input.substring(secondSpace+1);
            System.out.println(between);
            System.out.print(after);
        }
        else{
            System.exit(0);
        }
        sc.close();
    }
}
