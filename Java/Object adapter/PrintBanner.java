/*Class PrintBannernner 說明:
PrintBanner 繼承 Print
PrintBanner 有一個 private Banner banner
PrintBanner 有一個Method public PrintBanner(String string)
PrintBanner 有一個Method public void printWeak() 輸出"(string)"
PrintBanner 有一個Method public void printStrong() 輸出"*string*" */
public class PrintBanner extends Print {
    private  Banner banner;
    public PrintBanner(String string){
        this.banner =new Banner(string);
    }
    public void printWeak(){
        banner.showWithParen();
    }
    public void printStrong(){
        banner.showWithAster();
    }
}