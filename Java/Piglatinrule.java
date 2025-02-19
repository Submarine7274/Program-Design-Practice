import java.util.Scanner;
public class Piglatinrule{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String firstName = sc.next().toLowerCase();
        String lastName = sc.next().toLowerCase();
        String pigLatinFirstName = firstName.substring(1) + firstName.charAt(0) + "ay";
        String pigLatinLastName = lastName.substring(1) + lastName.charAt(0) + "ay";
        String pigLatinName = capitalize(pigLatinFirstName) + " " + capitalize(pigLatinLastName);
        System.out.printf(pigLatinName);
    }
    private static String capitalize (String str){
        if(str.length() == 0){
            return str;
        }
        else {
            return str.substring(0,1).toUpperCase() + str.substring(1);
        }
    }
}