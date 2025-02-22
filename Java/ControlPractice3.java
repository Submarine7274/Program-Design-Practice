public class ControlPractice3 {
    public static void main(String[] args){
        for(int e = 0; e<=9; e++){
            for(int h = 0; h <=9; h++){
                int abc =5*100 + 4 *10 +3;
                int gch = 6*100 + 3*10 +h;
                int eeid = e*1000+ e*100+ 8*10 +0;
                if ((abc +gch) == eeid){
                    System.out.println(e);
                    System.out.print(h);
                }
            }
        }
    }
}
