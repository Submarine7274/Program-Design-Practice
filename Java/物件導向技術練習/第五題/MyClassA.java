public class MyClassA {
    private String name;
    private int hours;
    private int minutes;
    public MyClassA(String myName, int myHours, int myMinutes){
        this.name = myName;
        this.hours = myHours;
        this.minutes = myMinutes;
    }
    public MyClassA (int myHours, int myMinutes){
        this.name = "Alice";
        this.hours = myHours;
        this.minutes = myMinutes;
    }
    public void myPrint(){
        System.out.println(name);
    }
    public void setName(String newName){
        this.name = newName;
    }
    public void setHours(int newHours){
        this.hours = newHours;
    }
    public void setMinutes(int newMinutes){
        this.minutes = newMinutes;
    }
    public String getName(){
        return name;
    }
    public int getHours(){
        return hours;
    }
    public int getMinutes(){
        return  minutes;
    }
}