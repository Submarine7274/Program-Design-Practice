class Square extends Shape {
    Square(String br) {
        super(br);
    }

    @Override
    void draw(int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                brush.print(i);
            }
            System.out.println();
        }
    }
}
