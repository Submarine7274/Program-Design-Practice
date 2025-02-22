class Alphabate implements Brush {
    @Override
    public void print(int i) {
        char ch = (char) ('A' + (i % 26));
        System.out.print(ch);
    }
}