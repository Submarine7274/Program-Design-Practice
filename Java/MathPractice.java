/*
請設計一個程式，一個double數X
程式會自動輸出X的平方根，
如我X不能被平方，則輸出"NaN"
提示:Math類別中有許多static的方法可以幫助我門處理數學運算問題

範例輸入
4.84
範例輸出
2.2 */
import java.util.Scanner;
public class MathPractice{
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    double number = sc.nextDouble();
    double result = Math.sqrt(number);

    if(Double.isNaN(result)){
        System.out.println("NaN");
    }
    else{
        System.out.print(result);
    }
    }
}