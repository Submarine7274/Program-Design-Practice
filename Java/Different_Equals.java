import java.util.Arrays;
import java.util.Scanner;

public class Different_Equals {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 提示輸入
        //System.out.println("Enter 5 to 10 floating-point numbers, separated by spaces:");
        String input = sc.nextLine();

        // 將輸入的字串拆解為浮點數陣列
        String[] inputArray = input.split(" ");
        if (inputArray.length < 5 || inputArray.length > 10) {
            System.out.println("Please enter between 5 and 10 numbers.");
            return;
        }

        double[] numbers = new double[inputArray.length];
        for (int i = 0; i < inputArray.length; i++) {
            numbers[i] = Double.parseDouble(inputArray[i]);
        }

        // 排序：由大到小
        Arrays.sort(numbers); // 預設為由小到大排序
        reverseArray(numbers); // 將排序後的陣列反轉

        // 輸出結果
        System.out.print("Large to small: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i]);
            if (i < numbers.length - 1) {
                System.out.print(" ");
            }
        }

        sc.close();
    }

    // 自定義方法：反轉陣列
    public static void reverseArray(double[] array) {
        int start = 0;
        int end = array.length - 1;
        while (start < end) {
            double temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }
}
