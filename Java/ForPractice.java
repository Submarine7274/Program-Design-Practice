import java.util.Scanner;
public class ForPractice {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        for(int levels = 1; levels <= number; levels++){
            for(int blanks=1; blanks <= (number - levels); blanks ++){
                System.out.print(" ");
            }
            for(int stars =1; stars <=(2*levels-1); stars++){
                System.out.print("*");
            }
            if(levels < number){
                System.out.println();
            }
        }
        sc.close();
    }
}
