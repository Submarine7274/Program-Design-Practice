public class MyClassA {
    public String name;
    protected int hours;
    private  int minutes;
    public MyClassA(String myName, int myHours, int myMinutes){
        this.name =myName;
        this.hours =myHours;
        this.minutes = myMinutes;
    }
    public void myPrint(){
        System.out.print(name);
    }
}
