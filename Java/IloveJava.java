import java.util.Scanner;
public class IloveJava {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        System.out.printf("***%s***",
                            input.trim()
                            .replace("I", "i")
                            .replace("hate", "Love")
                            .replaceAll("(?i)java", "JAVA")
                            .replaceAll(" ",""));
        sc.close();
    }
}