import java.util.Scanner;
public class EchoInput
{
    public static void main (String [] args){
        Scanner Keyin = new Scanner(System.in);
        String echo;

        echo = Keyin.next();

        System.out.println(echo); 
    }
}