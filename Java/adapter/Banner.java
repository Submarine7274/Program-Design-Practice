/*Class Banner 說明:
Banner 有一個private String string
Banner 有一個Method public Banner (String string)
Banner 有一個Method public void showWithParen() 輸出"(string)"
Banner 有一個Method public void showWithAster() 輸出"*string*" */
public class Banner {
    private  String string;
    public Banner(String string){
        this.string = string;
    }
    public void showWithParen(){
        System.out.println("(" + string +")");
    }
    public void showWithAster(){
        System.out.println("*" + string + "*");
    }
}
