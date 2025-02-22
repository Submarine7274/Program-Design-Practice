public class Car extends LandTransport{
    public Car() {
        capacity = 4;
    }
    @Override
    void Start(){
        System.out.println("Start transportation through car.");
    }
    @Override
    void Transporting(){
        System.out.println("Transporting through car...");
    }
    @Override
    void Arrive(){
        System.out.println("Arrived to destination through car.");
    }
}