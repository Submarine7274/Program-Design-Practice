import java.util.Scanner;

public class ControlPractice5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int b, d, e;
        boolean solution = false;
        
        while (sc.hasNextInt()) {
            b = sc.nextInt();
            d = sc.nextInt();
            e = sc.nextInt();
            if (b != d && b != e && e != d) {
                for (int c = 0; c <= 9; c++) {
                    int eec = 100 * e + 10 * e + c;
                    int cde = 100 * c + 10 * d + e;
                    int beb = 100 * b + 10 * e + b;
                    if (eec + cde == beb) {
                        System.out.print(c);
                        solution = true;
                        break;
                    }
                }
                if (!solution) {
                    System.out.print("-1");
                }
                break;
            }
        }
        sc.close();
    }
}