import java.util.Scanner;
public class horizontal_projecttile{
    float g = 9.8f;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        horizontal_projecttile re = new horizontal_projecttile();
        float x = sc.nextFloat();
        float y = sc.nextFloat();
        float result = re.horizontal_projecttile_function(x, y);
        System.out.printf("%.2f",result);
    }
    public  float  horizontal_projecttile_function(float x, float y){
        float R = x *( y * 2 / g);
        return R;
    }
}
