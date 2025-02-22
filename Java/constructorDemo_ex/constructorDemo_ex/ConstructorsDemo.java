import java.util.Scanner;

public class ConstructorsDemo
{
    public static void main(String[] args)
    {
        System.out.println("Please Inpute Your  birthday:month day year");

        Scanner sc =new Scanner(System.in);
       int month,day,year; 
       month=sc.nextInt();
       day=sc.nextInt();
       year=sc.nextInt();

        Date myBirthday = new Date(month,day,year);
       

        System.out.println("Your birthday is " + myBirthday + ".");

     }
}
