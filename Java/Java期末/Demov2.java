
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Demov2 {
    public static boolean login = false;
    public static void main(String[] args) {
        while(!login){
            dologin();
        }
        while(login){
            mainmenu();
        }
    }
    public static void dologin(){
        int attempts = 0;
        String inputaccount, inputpassword, inputVerify_string;
        String useraccount ="", userpassword="", userVerify_string="";
        Scanner sc = new Scanner(System.in);
        File account = new File("account.txt");
        File config = new File("config.txt");
        try(BufferedReader bf = new BufferedReader(new FileReader("account.txt"))) {
            String line  = bf.readLine();
            String parts[] = line.split(" ");
            useraccount = parts[0];
            userpassword = parts[1];

        } catch (Exception e) {
            System.out.println("File not found: " + account.getAbsolutePath());
        }
         try (BufferedReader br = new BufferedReader(new FileReader("config.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim(); // 移除左右空白
                if (line.startsWith("verify_string:")) { // 確保匹配目標鍵值
                    String[] parts = line.split(": "); // 以冒號分割鍵值
                    if (parts.length == 2) {
                        userVerify_string = parts[1].trim(); // 回傳值並移除多餘空白
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading configuration file: " + e.getMessage());
        }
        System.out.println("Current working directory: " + new File(".").getAbsolutePath());
        while (attempts <3){
            System.out.println(useraccount+" "+userpassword+" "+userVerify_string);
            System.out.println("Account:");
            inputaccount = sc.next();
            System.out.println("Password:");
            inputpassword = sc.next();
            System.out.println("Verify_string:");
            inputVerify_string = sc.next();
            if(inputaccount.equals(useraccount)&&inputpassword.equals(userpassword)&&inputVerify_string.equals(userVerify_string)){
                System.out.println("Login_success");
                login =true;
                break;
            }
            else{
                System.out.println("Error_wrong_account_password_or_verify_string");
                attempts++;
            }
        }
        System.out.println("Too many failed attempts. Exiting...");
        sc.close();
        login = false; // 重設登入狀態
        return; // 回到 main 方法
    }
    public static void mainmenu() {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("****************************************\n" +
                    "1.Show_a 2.Show_p 3.Show_by_c 4.Search 5.Mod 6.Del 7.Add_cont \n" +
                    "8.Add_cat 9.Show_cat 10.Set_field 11.Set_page 12.Set_order 13.Set_sort\n" +
                    "14.Show_r 15.Opt 16.Show_acc 17.Add_acc 18.Del_acc 19.Mod_acc 20.Logout 99.Exit\n" +
                    "****************************************");
            System.out.println("Enter your choice:");
            int choice = sc.nextInt();
    
            if (choice == 20) { // Logout
                System.out.println("Logging out...");
                login = false;
                return;
            } else if (choice == 99) { // Exit
                System.out.println("Exiting the system...");
                System.exit(0);
            } else {
                System.out.println("You selected option: " + choice);
                // 添加其他功能的實現邏輯
            }
        }
    }
}
