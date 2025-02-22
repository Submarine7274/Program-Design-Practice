public class PrintWithStar extends PrintProcessTemplate {
    void printHeader(){
        System.out.println("*********");
    }
    void printBody() {
        if (times <= 0) {
            System.out.println("Error: times must be greater than 0");
            return; 
        }
            switch (number % 5) {
                case 1:
                    System.out.println("*       *");
                    System.out.println("*    *  *");
                    System.out.println("*    *  *");
                    System.out.println("*    *  *");
                    System.out.println("*    *  *");
                    System.out.println("*    *  *");
                    System.out.println("*       *");
                    break;
                case 2:
                    System.out.println("*       *");
                    System.out.println("*  ***  *");
                    System.out.println("*    *  *");
                    System.out.println("*  ***  *");
                    System.out.println("*  *    *");
                    System.out.println("*  ***  *");
                    System.out.println("*       *");
                    break;
                case 3:
                    System.out.println("*       *");
                    System.out.println("*  ***  *");
                    System.out.println("*    *  *");
                    System.out.println("*  ***  *");
                    System.out.println("*    *  *");
                    System.out.println("*  ***  *");
                    System.out.println("*       *");
                    break;
                case 4:
                    System.out.println("*       *");
                    System.out.println("*  * *  *");
                    System.out.println("*  * *  *");
                    System.out.println("*  ***  *");
                    System.out.println("*    *  *");
                    System.out.println("*    *  *");
                    System.out.println("*       *");
                    break;
                case 0:
                    System.out.println("*       *");
                    System.out.println("*  ***  *");
                    System.out.println("*  *    *");
                    System.out.println("*  ***  *");
                    System.out.println("*    *  *");
                    System.out.println("*  ***  *");
                    System.out.println("*       *");
                    break;
                default:
                    System.out.println("error");
                    break;
            }
    }
    void printFooter(){
        System.out.println("*********");
    }
}
