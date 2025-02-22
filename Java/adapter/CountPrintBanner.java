/*Class CountPrintBanner 說明:
CountPrintBanner 繼承 Banner
CountPrintBanner 實作 Print
CountPrintBanner 有一個Method public CountPrintBanner(String string)
CountPrintBanner 有一個Method public void printWeak()
CountPrintBanner 有一個Method public void printStrong() */
public class CountPrintBanner extends Banner implements Print {
    public CountPrintBanner(String string){
        super(string);
    }
    public void printWeak(){
        showWithParen();
    }
    public void printStrong(){
        showWithAster();
    }
}
