abstract class Shape{
    int size;
    Brush brush;

    Shape(String br) {
        if(br.trim().equals("ab")){
            this.brush = new Alphabate();
        }
        else if(br.trim().equals("no")){
            this.brush = new Number();
        }
        else{
            throw new IllegalArgumentException("Invalid brush type");
        }
    }
    abstract  void draw(int size);
}