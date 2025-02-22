import java.util.Scanner;
public class ScoreAdjustment {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int students = sc.nextInt();
        int corrects [] = new int[students];
        for(int i = 0; i < students; i++){
            corrects[i] = sc.nextInt();
        }
        for(int i = 0; i < students; i++){
            
            if(i < students-1){
                System.out.println(Adjust(corrects[i]));
            }
            else{
                System.out.print(Adjust(corrects[i]));
            }
            
        }
        sc.close();
    }
    public static int Adjust(int correct){
        if(correct <=10){
            correct*=6;
        }
        else if(correct <=20&&correct >=11){
            correct= (correct-10) *2 + 60;
        }
        else if(correct <=40&&correct >=21){
            correct= (correct-20) *1 + 80;
        }
        else if(correct >=40){
            correct = 100;
        }
        return correct;
    }
}
