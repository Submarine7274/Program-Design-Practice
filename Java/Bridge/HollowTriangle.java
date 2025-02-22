class HollowTriangle extends Shape {
    HollowTriangle(String br) {
        super(br);
    }
    @Override
    void draw(int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                if (j == 0 || j == 2 * i || i == size - 1) {
                    brush.print(i);
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}
