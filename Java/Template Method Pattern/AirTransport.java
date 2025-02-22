public class AirTransport extends TransportProcessTemplate{
    public AirTransport() {
        capacity = 50;
    }
    @Override
    void Start(){
        System.out.println("Start transportation throught air.");
    }
    @Override
    void Transporting(){
        System.out.println("Transporting through air…");
    }
    @Override
    void Arrive(){
        System.out.println("Arrived to destination through air.");
    }
}
