public class Car {
    public int speed =0, mileage =0;
    public String color = "NoColor", brand = "NoBrand";

    public Car(){
    speed = 0; 
    mileage = 0;
    color = "NoColor"; 
    brand = "NoBrand";
    }
    public Car(int cspeed){
        this(cspeed,0,"NoColor","NoBrand");
    }
    public Car(String cbrand){
        this(0,0,"NoColor",cbrand);
    }
    public Car(String ccolor, String cbrand){
        this(0,0,ccolor,cbrand);
    }
    public Car(int cspeed,int cmileage,String ccolor,String cbrand){
        speed = cspeed; 
        mileage = cmileage;
        color = ccolor; 
        brand = cbrand;
    }
    public int getSpeed(){
        return speed;
    }
    public int getMileage(){
        return mileage;
    }
    public String getColor(){
        return color;
    }
    public String getBrand(){
        return brand;
    }
    public boolean setSpeed(int sspeed){
        speed = sspeed;
        return true;
    }
    public boolean setMileage(int smileage){
        mileage = smileage;
        return true;
    }
    public boolean setColor(String scolor){
        color = scolor;
        return true;
    }
    public boolean setBrand(String sbrand){
        brand = sbrand;
        return true;
    }
    public boolean setCar(String scolor,String sbrand){
        color = scolor;
        brand = sbrand;
        return true;
    }
    public boolean setCar(int sspeed,int smileage,String scolor,String sbrand){
        speed = sspeed;
        mileage = smileage;
        color = scolor;
        brand = sbrand;
        return true;
    }
    public boolean setColor(String scolor,String sbrand){
        color = scolor;
        brand = sbrand;
        return true;
    }
    public boolean setColor(int sspeed,int smileage,String scolor,String sbrand){
        speed = sspeed;
        mileage = smileage;
        color = scolor;
        brand = sbrand;
        return true;
    }
}
