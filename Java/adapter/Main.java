/*Class Main功能說明：
1.輸入字串
2.創建CountPrintBanner物件
3.呼叫printWeak()
4.呼叫printStrong()
5.創建PrintBanner物件
6.呼叫printWeak()
7.呼叫printStrong()*/
import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        Print cpb = new CountPrintBanner(input);
        for(int i =0; i<=4; i++){
            cpb.printWeak();
        }
        for(int i=0; i<=4; i++){
            cpb.printStrong();
        }
        Print p = new PrintBanner(input);
        p.printWeak();
        p.printStrong();
        sc.close();
    }
}