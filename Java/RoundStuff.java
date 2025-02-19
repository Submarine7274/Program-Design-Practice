/*請參考附件RoundStuffDemo.java
修改RoundStuff.java
使得RoundStuffDemo的程式能順利取得變數值，
計算半徑和邊長為輸入值的圓形面積和球體體積

範例輸入
1
範例輸出
A circle of radius 1 inches
has an area of 3.14159 square inches.
A sphere of radius 1 inches
has an volume of 1 cubic inches. */
public class RoundStuff
{
    static public double PI = 3.14159;

    /**
     Return the area of a circle of the given radius.
    */
    static public double area(double radius)
    {
        return (PI*radius*radius);
    }
    
    /**
     Return the volume of a sphere of the given radius.
    */
    static public double volume(double radius)
    {
        return ((4.0/3.0)*PI*radius*radius*radius);
    }
}