
public class ControlPractice{
    public static void main(String[] args) {
        String term1 = "eec";
        String term2 = "cde";
        String term3 = "beb";
        int num1 = convert(term1);
        int num2 = convert(term2);
        int num3 = convert(term3);
        //System.out.println("eec ="+num1);
        //System.out.println("cde ="+num2);
        //System.out.println("beb ="+num3);
        //11C+X41 = 414 c=3
        for (int i = 0; i <=9; i++){
            int x1 = num1 + i;
            int x2 = (i*100) +num2;
            if((x1 +x2) == num3){
                System.out.print(i);
            }
        }
    }
    public static int convert(String words){
        int number = 0;
        for(int i = 0; i < words.length(); i++){
            char ch = words.charAt(i);
            switch(ch){
                case'b':
                number = number *10 +4;
                break;
                case'd':
                number = number *10 +0;
                break;
                case'e':
                number = number *10 +1;
                break;
                default:
                number = number *10 +0;
                break;
            }
        }
        return number; 
    }
}