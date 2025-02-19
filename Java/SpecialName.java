import java.util.Scanner;
public class SpecialName{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String firstName = sc.next().toLowerCase();
        String lastName = sc.next().toLowerCase();
        firstName = capitalize((firstName.substring(1)+firstName.charAt(0)+"ay"));
        lastName = capitalize((lastName.charAt((lastName.length()-1))+(lastName.substring(0,(lastName.length()-1)))+"er"));
        System.out.printf("%s %s", firstName, lastName);
        sc.close();
    }
    private static String capitalize(String str){
        if(str.length() == 0){
            return str;
        }
        else{
            return str.substring(0,1).toUpperCase() + str.substring(1);
        }
    }
}