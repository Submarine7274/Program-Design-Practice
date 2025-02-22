import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Calculator calculator = new Calculator();

        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int a = Integer.parseInt(parts[0]);
        String operator = parts[1];
        int b = Integer.parseInt(parts[2]);

        switch (operator) {
            case "+":
                calculator.setStrategy(new Add());
                break;
            case "-":
                calculator.setStrategy(new Minus());
                break;
            case "*":
                calculator.setStrategy(new Multiply());
                break;
            case "/":
                calculator.setStrategy(new Divide());
                break;
            default:
                System.out.println("Error operator");
                return;
        }

        int result = calculator.execute(a, b);
        System.out.println(result);
        scanner.close();
    }
}