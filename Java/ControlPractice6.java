import java.util.Scanner;
public class ControlPractice6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a,b,c,d,e,g,h,i;
        boolean solution = false;
        while(sc.hasNextInt()){
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            d = sc.nextInt();
            e = sc.nextInt();
            for(g=0; g<=9; g++){
                for(h=0;h<=9;h++){
                    if(g == h){
                        continue;
                    }
                    for(i = 0;i<=9;i++){
                        if(g == h ||g == i|| h == i){
                            continue;
                        }
                        int abc = 100*a+10*b+c;
                        int gch = 100*g+10*c+h;
                        int eeid = 1000*e+100*e+10*i+d;
                        if(abc +gch ==eeid){
                            System.out.println(g);
                            System.out.println(h);
                            System.out.print(i);
                            solution = true;
                        }
                    }
                }
            }
            if(!solution){
                System.out.println(-1);
            }
        }
    }
}
