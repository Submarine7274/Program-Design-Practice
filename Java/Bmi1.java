import java.text.DecimalFormat;
import java.util.Scanner;

public class Bmi1 {
    public static void main(String[] args) {
        float weight = 0, height = 0, result = 0;
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.1f");

        System.out.print("請輸入您的身高（米）：");
        height = sc.nextFloat();
        System.out.print("請輸入您的體重（公斤）：");
        weight = sc.nextFloat();

        if (height > 0) {
            result = weight / (height * height);
            String formattedBmi = df.format(result);
            System.out.printf("您的BMI是：%s\n", formattedBmi);
        } else {
            System.out.println("身高不能為零或負數。");
        }
    }
}
