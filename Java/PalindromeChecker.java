import java.util.Scanner;

public class PalindromeChecker {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 提示輸入
        //System.out.println("Enter a 5-digit number:");
        int number = sc.nextInt();

        // 確保輸入的數字為5位
        if (number < 10000 || number > 99999) {
            System.out.println("The number is not a 5-digit number.");
        } else {
            // 判斷是否為迴文數
            if (isPalindrome(number)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }

        sc.close();
    }

    // 判斷是否為迴文數的方法
    public static boolean isPalindrome(int num) {
        int digit1 = num / 10000;           // 萬位數
        int digit2 = (num / 1000) % 10;     // 千位數
        int digit4 = (num / 10) % 10;       // 十位數
        int digit5 = num % 10;              // 個位數

        // 比較萬位與個位，千位與十位
        return digit1 == digit5 && digit2 == digit4;
    }
}
