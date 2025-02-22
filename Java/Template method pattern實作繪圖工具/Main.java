import  java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintProcessTemplate dpp;
        int brush = sc.nextInt();
        int times = sc.nextInt();
        switch(brush){
            case 1:
            dpp = new PrintWithStar();
            dpp.print(times);
            break;
            case 2:
            dpp = new PrintWithQuestionMark();
            dpp.print(times);
            break;
            case 3:
            dpp = new PrintWithAtSign();
            dpp.print(times);
            break;
            case 4:
            dpp = new PrintWithPlus();
            dpp.print(times);
            break;
            default:
            System.out.println("wrong brush");
            break;
        }
        sc.close();
    }
}
