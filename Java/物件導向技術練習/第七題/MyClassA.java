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
    public MyClassA(MyClassA copied){
        this.name = copied.name;
        this.hours = copied.hours;
        this.minutes = copied.minutes;
    }
    public void myPrint(){
        System.out.println(name);
    }
    public boolean equals(MyClassA other){
        if(this.name.equals(other.name)&&(this.hours == other.hours)&&(this.minutes ==other.minutes)){
            System.out.println("true");
            return true;
        }
        else{
            System.out.println("false");
            return false;
        }
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
