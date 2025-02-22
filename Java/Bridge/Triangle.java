public class Triangle extends Shape{
    Triangle(String br) {
        super(br);
    }
    @Override
    void draw(int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                brush.print(i);
            }
            System.out.println();
        }
    }
}
