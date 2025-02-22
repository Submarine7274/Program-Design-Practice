import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentManeger stm = new StudentManeger();
        SystemController sct = new SystemController();
        while (!sct.getLogin()) {
            sct.login();
        }
        if (sct.getLogin()) {
            while (sct.getLogin()) {
                System.out.println("輸入 1 查看學生");
                System.out.println("輸入 2 新增學生");
                System.out.println("輸入 3 更新學生");
                System.out.println("輸入 4 刪除學生");
                System.out.println("輸入 5 登出");

                int command = -1;
                while (true) {
                    System.out.println("請輸入指令: ");
                    try {
                        command = Integer.parseInt(sc.nextLine()); // 使用 nextLine() 讀取，並手動轉換
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("輸入錯誤！請輸入數字。");
                    }
                }
                switch (command) {
                    case 1:
                        stm.showAllStudent();
                        break;
                    case 2:
                        if (sct.checkVerifyCode()) {
                            stm.addStudent();
                        } else {
                            System.out.println("驗證碼錯誤，操作失敗！");
                        }
                        break;
                    case 3:
                        if (sct.checkVerifyCode()) {
                            stm.modifyStudent();
                        } else {
                            System.out.println("驗證碼錯誤，操作失敗！");
                        }
                        break;
                    case 4:
                        if (sct.checkVerifyCode()) {
                            stm.deleteStudent();
                        } else {
                            System.out.println("驗證碼錯誤，操作失敗！");
                        }
                        break;
                    case 5:
                        sct.logout();
                        break;
                    default:
                        System.out.println("錯誤指令，請重新輸入");
                        break;
                }
            }
        } else {
            System.out.println("登入失敗");
        }
        sc.close();
    }
}
