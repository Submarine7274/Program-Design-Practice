import  java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String brushType = sc.nextLine();
        String shapeType = sc.nextLine();
        int size = sc.nextInt();
        Shape shape;
        switch (shapeType) {
            case "tr":
                shape = new Triangle(brushType);
                break;
            case "htr":
                shape = new HollowTriangle(brushType);
                break;
            case "sq":
                shape = new Square(brushType);
                break;
            case "hsq":
                shape = new HollowSquare(brushType);
                break;
            default:
                throw new IllegalArgumentException("Invalid shape type");
        }
        shape.draw(size);
    }
}