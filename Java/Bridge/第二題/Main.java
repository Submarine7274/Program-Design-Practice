import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Device device = null;

        while (true) {
            String input = scanner.nextLine();
            if (input.equals("exit")) break;

            if (device == null) {
                switch (input) {
                    case "tv":
                        device = new Television();
                        break;
                    case "rd":
                        device = new Radio();
                        break;
                    case "rf":
                        device = new Refrigerator();
                        break;
                    case "ac":
                        device = new AirConditioner();
                        break;
                    default:
                        System.out.println("no such a function.");
                        continue;
                }
            } else {
                MediaRemote remote = new MediaRemote(device);
                switch (input) {
                    case "Pwr":
                        remote.togglePower();
                        break;
                    case "Vup":
                        remote.volumeUp();
                        break;
                    case "Vdn":
                        remote.volumeDown();
                        break;
                    case "Cup":
                        remote.channelUp();
                        break;
                    case "Cdn":
                        remote.channelDown();
                        break;
                    case "Tup":
                        remote.temperatureUp();
                        break;
                    case "Tdn":
                        remote.temperatureDown();
                        break;
                    default:
                        System.out.println("no such a function.");
                }
            }
        }

        scanner.close();
    }
}
