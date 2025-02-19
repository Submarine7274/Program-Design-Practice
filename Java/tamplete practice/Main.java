import java.util.Scanner;
abstract class TransportProcessTemplate{
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
/*Class AirTransport
繼承TransportProcessTemplate
Int capacity = 50
實作start()：輸出 "Start transportation throught air."
實作transporting()：輸出 " Transporting through air…"
實作arrive()：輸出 "Arrived to destination through air." */

class AirTransport extends TransportProcessTemplate{
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
        System.out.print("Arrived to destination through air.");
    }
}
/*Class LandTransport
繼承TransportProcessTemplate
Int capacity = 100
實作start()：輸出 " Start tranportation throught land."
實作transporting()：輸出 " Transporting through land..."
實作arrive()：輸出 "Arrived to destination by air." */
class LandTransport extends TransportProcessTemplate{
    public LandTransport() {
        capacity = 100;
    }
    @Override
    void Start(){
        System.out.println("Start tranportation throught land.");
    }
    @Override
    void Transporting(){
        System.out.println("Transporting through land...");
    }
    @Override
    void Arrive(){
        System.out.print("Arrived to destination by air.");
    }
}
/*Class SeaTransport
繼承TransportProcessTemplate
Int capacity = 200
實作start():輸出 "Start tranportation throught sea."
實作transporting():輸出 " Transporting through sea..."
實作arrive():輸出 "Arrived to destination." */
class SeaTransport extends TransportProcessTemplate{
    public SeaTransport() {
        capacity = 200;
    }
    @Override
    void Start(){
        System.out.println("Start tranportation throught sea.");
    }
    @Override
    void Transporting(){
        System.out.println("ransporting through sea...");
    }
    @Override
    void Arrive(){
        System.out.print("Arrived to destination through sea.");
    }
}
/*Class Car
繼承 LandTransport
int capacity = 4
實作start()：輸出 "Start tranportation throught car."
實作transporting()：輸出 " Transporting through car..."
實作arrive()：輸出 "Car arrived to destination." */
class Car extends TransportProcessTemplate{
    public Car() {
        capacity = 4;
    }
    @Override
    void Start(){
        System.out.println("Start tranportation throught car.");
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
/*Class Train
繼承 LandTransport
int capacity = 400
實作start()：輸出 "Start tranportation throught train."
實作transporting()：輸出 " Transporting through train..."
實作arrive()：輸出 "Train arrived to destination." */
class Train extends TransportProcessTemplate{
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
        System.out.print("Train arrived to destination.");
    }
}
/*Main class 為主class
包含進入點 main() metohd
main() metohd內需要創建一個TransportProcessTemplate的物件 tpt
從鍵盤輸入兩個整數
第一個決定交通工具類型
第二個輸入載重Load
交通工具類型：
LandTransport,載重量 100
SeaTransport ,載重量 200
AirTransport ,載重量 50
Car ,載重量 4
Train ,載重量 400
輸入完成後，執行transport(Load載重量) */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //System.out.println("Enter transport type (1-Land, 2-Sea, 3-Air, 4-Car, 5-Train):");
        int transportType = sc.nextInt();
        
        //System.out.println("Enter load:");
        int load = sc.nextInt();

        TransportProcessTemplate tpt;

        switch (transportType) {
            case 1:
                tpt = new LandTransport();
                break;
            case 2:
                tpt = new SeaTransport();
                break;
            case 3:
                tpt = new AirTransport();
                break;
            case 4:
                tpt = new Car();
                break;
            case 5:
                tpt = new Train();
                break;
            default:
                System.out.println("Invalid transport type.");
                sc.close();
                return;
        }

        tpt.Transport(load);
        sc.close();
    }
}