import java.util.Scanner;
public class Wrapper {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String inputStr,outputStr;
		int inputInt,outputInt;
		inputStr=sc.next();
		inputInt=sc.nextInt();
        outputInt = Integer.parseInt(inputStr)+3;
        outputStr = Integer.toString(inputInt)+"3";
        System.out.println(outputInt);
		System.out.print(outputStr);
    }
}
