import java.util.Scanner;
public class MyMain{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int score;
        score = sc.nextInt();
        if(score >= 90 && score <= 100){
            System.out.printf("A");
        }
        else if(score >= 80 && score <= 89){
            System.out.printf("B");
        }
        else if(score >= 70 && score <= 79){
            System.out.printf("C");
        }
        else if(score >= 60 && score <= 69){
            System.out.printf("D");
        }
        else if(score >= 50 && score <= 59){
            System.out.printf("E");
        }
        else if(score >= 0 && score <= 49){
            System.out.printf("Failed");
        }
        else {
            System.out.printf("OOR");
        }
    }
}