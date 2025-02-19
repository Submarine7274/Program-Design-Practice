import java.util.Scanner;
public class delimiter{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        Scanner s1c = new Scanner(s1);
        s1c.useDelimiter(s2 +"|\\n");
        while(s1c.hasNext()){
            System.out.println(s1c.next());
        }
    }
}