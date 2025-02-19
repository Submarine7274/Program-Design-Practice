public class RoundStuff
{
    public double PI = 3.14159;

    /**
     Return the area of a circle of the given radius.
    */
    public double area(double radius)
    {
        return (PI*radius*radius);
    }
    
    /**
     Return the volume of a sphere of the given radius.
    */
    public double volume(double radius)
    {
        return ((4.0/3.0)*PI*radius*radius*radius);
    }
}