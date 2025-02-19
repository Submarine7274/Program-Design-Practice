/*Wrapper class練習
=================
Wrapper class練習
=================
請設將範例程式加入相關的運算程式碼
程式功能要求說明如下:
(1)可以把第一個輸入的字串轉為整數加3後輸出，
(2)第二個輸入的整數轉為字串後加上一個"3"輸出

範例輸入
254 123
範例輸出
257
1233 */

import java.util.Scanner;

public class wrapperDemo {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String inputStr,outputStr;
		int inputInt,outputInt;
		inputStr=sc.next();
		inputInt=sc.nextInt();
        //
        outputInt = Integer.parseInt(inputStr) +3;
        outputStr = Integer.toString(inputInt) +"3";
        //
        System.out.println(outputInt);
		System.out.print(outputStr);
	}
}