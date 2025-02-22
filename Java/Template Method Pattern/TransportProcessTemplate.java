public abstract class TransportProcessTemplate {
    int capacity;
    public final void Transport(int load){
        if(load >capacity){
            System.out.print("Overloaded. This transportation can not work.");
        }
        else{
            Start();
            Transporting();
            Arrive();
        }
    }
    abstract void Start();
    abstract void Transporting();
    abstract void Arrive();
}
