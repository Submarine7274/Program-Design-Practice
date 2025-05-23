
import java.util.Scanner;

/**
Class with static methods for circles and spheres.
*/
public class RoundStuff2
{
    public static final double PI = 3.14159;
    public static int invocationCount =0;


    /**
     Return the area of a circle of the given radius.
    */
    public static double area(double radius)
    {
        invocationCount++;
        return (PI*radius*radius);
    }
    
    /**
     Return the volume of a sphere of the given radius.
    */
    public static double volume(double radius)
    {
        invocationCount++;
        return ((4.0/3.0)*PI*radius*radius*radius);
    }

    public static void main(String[] args)
    {
        Scanner keyboard = new Scanner(System.in);
        //System.out.println("Enter radius:");
        double radius = keyboard.nextDouble( );
                      
        System.out.println("A circle of radius " 
                                      + radius + " inches");
        System.out.println("has an area of " +
             RoundStuff2.area(radius) + " square inches.");
        System.out.println("A sphere of radius " 
                                      + radius + " inches");
        System.out.println("has an volume of " +
             RoundStuff2.volume(radius) + " cubic inches.");
        System.out.print("The method invocation count =" +
             invocationCount);
    }
}