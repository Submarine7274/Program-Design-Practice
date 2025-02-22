import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Demo {

    private static final String ACCOUNT_FILE = "account.txt"; // 帳號檔案
    private static final String VERIFY_STRING = "12345"; // 固定驗證字串
    private static final int MAX_ATTEMPTS = 3; // 最大嘗試次數

    public static void main(String[] args) {
        try {
            if (doLogin()) {
                System.out.println("****************************************");
                System.out.println("1.Show_a 2.Show_p 3.Show_by_c 4.Search 5.Mod 6.Del 7.Add_cont");
                System.out.println("8.Add_cat 9.Show_cat 10.Set_field 11.Set_page 12.Set_order 13.Set_sort");
                System.out.println("14.Show_r 15.Opt 16.Show_acc 17.Add_acc 18.Del_acc 19.Mod_acc 20.Logout 99.Exit");
                System.out.println("****************************************");
            }
        } catch (IOException e) {
            System.out.println("Error reading account file: " + e.getMessage());
        }
    }

    public static boolean doLogin() throws IOException {
        Scanner input = new Scanner(System.in);
        int attempts = 0;

        while (attempts < MAX_ATTEMPTS) {
            System.out.println("Account:");
            String account = input.nextLine();
            System.out.println("Password:");
            String password = input.nextLine();
            System.out.println("Verify_string:" + VERIFY_STRING);
            System.out.println("Input_Verify_string:");
            String verifyInput = input.nextLine();

            if (verifyInput.equals(VERIFY_STRING) && isAccountValid(account, password)) {
                System.out.println("Login_success");
                return true;
            } else {
                System.out.println("Error_wrong_account_password_or_verify_string");
                attempts++;
            }
        }

        System.out.println("Too many failed attempts. Exiting system.");
        return false;
    }

    private static boolean isAccountValid(String account, String password) throws IOException {
        File file = new File(ACCOUNT_FILE);
        if (!file.exists()) {
            System.out.println("Account file not found!");
            return false;
        }

        Scanner fileScanner = new Scanner(file);
        while (fileScanner.hasNextLine()) {
            String[] accountData = fileScanner.nextLine().split(" ");
            if (accountData.length == 2) {
                if (accountData[0].equals(account) && accountData[1].equals(password)) {
                    return true;
                }
            }
        }

        return false;
    }
}
