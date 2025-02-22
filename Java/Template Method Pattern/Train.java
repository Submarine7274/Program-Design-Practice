public class Train extends LandTransport{
    public Train() {
        capacity = 400;
    }
    @Override
    void Start(){
        System.out.println("Start tranportation throught train.");
    }
    @Override
    void Transporting(){
        System.out.println("Transporting through train...");
    }
    @Override
    void Arrive(){
        System.out.println("Train arrived to destination.");
    }
}