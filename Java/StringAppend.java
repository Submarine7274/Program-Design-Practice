import java.util.Scanner;
public class StringAppend {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String encryptedText = sc.nextLine();
        StringBuffer scb = new StringBuffer();
        for(int i = 0; i < encryptedText.length(); i += 3){
            scb.append(encryptedText.charAt(i));
        }
        System.out.printf("%s", scb.toString());
        sc.close();
    }
}
