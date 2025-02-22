public class SeaTransport extends TransportProcessTemplate{
    public SeaTransport() {
        capacity = 200;
    }
    @Override
    void Start(){
        System.out.println("Start transportation through sea.");
    }
    @Override
    void Transporting(){
        System.out.println("Transporting through sea...");
    }
    @Override
    void Arrive(){
        System.out.println("Arrived to destination through sea.");
    }
}