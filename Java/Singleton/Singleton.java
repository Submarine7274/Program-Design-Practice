/*Class Singleton 說明：
1.宣告classname type variable 須為private，
2.宣告classname type variable須為static ，
3.constructor 須為private，
4.呼叫constructor時，需輸出"already created object" 5.getInstance 須為public(命題時規定function name 名稱為getInstance)，
6.getInstance須為static(命題時規定function name 名稱為getInstance)。
Class Main 說明：
1.輸出"start."
2.使用Singleton.getInstance()創建兩個物件obj1與obj2
3.如果obj1 == obj2，則輸出"obj1 and obj2 are the same object"
4.如果obj1 != obj2，則輸出"obj1 and obj2 are not the same object"
5.最後輸出"End." */
class Singleton {
    private static Singleton instance = null;
    private Singleton() {
        System.out.println("already created object");
    }
    public static synchronized Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton(); 
        }
        return instance; 
    }
}