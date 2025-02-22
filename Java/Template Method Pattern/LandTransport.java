public class LandTransport extends TransportProcessTemplate{
    public LandTransport() {
        capacity = 100;
    }
    @Override
    void Start(){
        System.out.println("Start transportation through land.");
    }
    @Override
    void Transporting(){
        System.out.println("Transporting through land...");
    }
    @Override
    void Arrive(){
        System.out.println("Arrived to destination by land.");
    }
}