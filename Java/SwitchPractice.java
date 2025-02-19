import java.util.Scanner;
public class SwitchPractice {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StringBuilder str = new StringBuilder();
        String line = sc.nextLine();
        for(char ch: line.toCharArray()){
            if (ch == ' '){
                continue;
            }
            switch(ch){
                case 'a': case'b': case 'c': case 'd': case 'e':
                str.append(Character.toUpperCase(ch)).append(" ");
                break;
                default:
                str.append("Z").append(" ");
                break;
            }
        }
        if(str.length() >0){
            str.setLength(str.length()-1);
        }
        System.out.print(str.toString());
        sc.close();
    }
}
