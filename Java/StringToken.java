import java.util.Scanner;
import java.util.StringTokenizer;
public class StringToken {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        StringTokenizer st = new StringTokenizer(input, ",");
        String lastname = st.hasMoreTokens()? st.nextToken().trim() : "None";
        String firsttname = st.hasMoreTokens()? st.nextToken().trim() : "None";
        String middlename = st.hasMoreTokens()? st.nextToken().trim() : "None";
        String output = "Hello ";
        if(!firsttname.equals("None")){
            output += firsttname +" ";
        }
        if(!middlename.equals("None")){
            output += middlename +" ";
        }
        if(!lastname.equals("None")){
            output += lastname;
        }
        System.out.print(output);
    }
}
