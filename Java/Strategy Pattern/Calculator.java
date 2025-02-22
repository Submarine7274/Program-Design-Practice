class Calculator {
    private IStrategy strategy;

    public void setStrategy(IStrategy strategy) {
        this.strategy = strategy;
    }

    public int execute(int a, int b) {
        return strategy.calculate(a, b);
    }
}