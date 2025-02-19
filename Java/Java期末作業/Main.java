public class Main {
    public static void main(String[] args) {
        boolean loggin = false;
        SystemController sct = new SystemController();
        while(!loggin){
            if(sct.login() == true){
                loggin =true;
                break;
            }
        }
        while(loggin){
            System.out.println("");
        }
    }
}
