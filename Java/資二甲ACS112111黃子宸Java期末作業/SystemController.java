import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class SystemController {
    private boolean isLogin =false;
    private ArrayList<String[]> accountData = new ArrayList<>();
    public void getAllAccount(){
        File file = new File("admin.txt");
        if (!file.exists()) {
            System.out.println("Error: 檔案 admin.txt 不存在！");
            return;
        } 
        try(BufferedReader br =new BufferedReader(new FileReader(file))) {
            String line;
            while((line =br.readLine())!=null){
                String[] parts = line.split(" ");
                if(parts.length ==2){
                    accountData.add(parts);
                }
            }
            br.close();
        } catch (Exception e) {
            System.out.println("Error while loading account data.");
        }
        
    }
    public boolean login(){
        getAllAccount();
        Scanner sc =new Scanner(System.in);
        System.out.println("輸入帳號:");
        String inputAccount = sc.nextLine();
        System.out.println("輸入密碼:");
        String inputPassword = sc.nextLine();
        for(String[] account:accountData){
            if(account[0].equals(inputAccount) &&account[1].equals(inputPassword)){
                isLogin = true;
                System.out.println("成功登入");
                return isLogin;
            }
        }
        System.out.println("帳號或密碼錯誤");
        return false;
    }
    public void logout(){
        isLogin =false;
        System.out.println("成功登出");
    }
    public boolean checkVerifyCode(){
        Scanner sc= new Scanner(System.in);
        System.out.println("請輸入驗證碼AB12");
        String inputVerifyCode = sc.nextLine();
        if(inputVerifyCode.equals("AB12")){
            return true;
        }
        else{
            System.out.println("驗證碼錯誤");
            return false;
        }
    }
    public boolean getLogin(){
        return isLogin;
    }
}
