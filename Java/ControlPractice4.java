public class ControlPractice4 {
    public static void main(String[] args){
        int G, T, O, D;
        outerLoop:
        for(T = 0; T<=9; T++){
            
            for(O=0; O<=9; O++){
                if (O == T) continue;
                for(G=0; G<=9; G++){
                    if (G == T || G == O) continue;
                    for(D=0; D<=9; D++){
                        if (D == T || D == O || D == G) continue;
                        if((4 * (100 * T + 10 * O + O)) == (1000 * G + 100 * O + 10 * O + D) && 
                            !(T == 0 && O == 0 && G == 0 && D == 0)){
                            System.out.printf("T = %d O = %d G = %d D = %d",T,O,G,D);
                            break outerLoop;
                        }
                    }
                }
            }
        } 
    }
}
