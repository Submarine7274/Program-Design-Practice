/*nextDouble的應用II
由鍵盤輸入1個最多到小數點第14位的小數，代表酸鹼中和後氫氧離子莫爾濃度，請計算出中和後溶液的ph值並輸出到小數點以下第2位
[註：ph = 14 + log(氫氧離子莫爾濃度)，log可以使用JAVA內建的Math.log()函式(需import java.lang.Math)]
範例輸入
0.1

範例輸出
13.00 */

import java.util.Scanner;

public class PH2{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double mol = sc.nextDouble();
        double phnumber = Math.log10(mol)+14;
        System.out.printf("%.2f",phnumber);
        sc.close();
    }
}