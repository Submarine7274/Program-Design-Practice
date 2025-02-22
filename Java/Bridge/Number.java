public class Number implements Brush {
    @Override
    public void print(int i) {
        char ch = (char) ('1' + (i % 10));
        System.out.print(ch);
    }
}
