/*Class PrintBannernner 說明:
PrintBanner 繼承 Banner
PrintBanner 實作 Print
PrintBanner 有一個Method public PrintBanner(String string)
PrintBanner 有一個Method public void printWeak() 輸出"(string)"
PrintBanner 有一個Method public void printStrong() 輸出"*string*" */
public class PrintBanner extends Banner implements Print{
    public PrintBanner(String string){
        super(string);
    }
    @Override
    public void printWeak(){
        showWithParen();
    }
    @Override
    public void printStrong(){
        showWithAster();
    }
}