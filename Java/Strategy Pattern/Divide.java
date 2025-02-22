class Divide implements IStrategy {
    public int calculate(int a, int b) {
        if (b == 0) {
            throw new ArithmeticException("Can't divide 0");
        }
        return a / b;
    }
}