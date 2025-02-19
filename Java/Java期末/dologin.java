import java.io.*;
import java.util.*;
public class dologin {
    public static void main(String[] args) {
        boolean loggedIn =false;
        try {
            Scanner sc = new Scanner(System.in);
            BufferedReader br = new BufferedReader(new FileReader("account.txt"));
            String[] fileinput = br.readLine().split("\s");
            int attempt = 0;
            while(!loggedIn){
                if(attempt < 3){
                    System.out.println("Account:");
                    String accountname = sc.nextLine();
                    System.out.println("Password:");
                    String password = sc.nextLine();
                    System.out.println("Verify_string:");
                    String Verify_string= sc.nextLine();
                    //System.out.println("Input_Verify_string:");
                     
                }
                
            }
            
        } catch (Exception e) {
            System.out.println("File open error.");
        }
        
            
            
            System.out.println("Error_wrong_account_password_or_verify_string");
            System.out.println("Login_success");
    }
}
