public class Refrigerator implements Device {
    private boolean state = false;
    private int temperature = 2;

    @Override
    public boolean isOn() {
        return state;
    }

    @Override
    public void turnOn() {
        state = true;
        System.out.println("turn on rf");
    }

    @Override
    public void turnOff() {
        state = false;
        System.out.println("turn off rf");
    }

    @Override
    public void setTemperature(int degree) {
        if (!state) {
            System.out.println("rf not turned on");
            return;
        }
        if (degree < -10 || degree > 4) {
            System.out.println("reached temperature gap");
        } else {
            if (degree > this.temperature) {
                System.out.println("rf temperature up");
            } else {
                System.out.println("rf temperature down");
            }
            this.temperature = degree;
        }
    }

    @Override
    public int getTemperature() {
        return temperature;
    }

    @Override
    public void setChannel(int channel) {
        System.out.println("no such a function.");
    }

    @Override
    public int getChannel() {
        System.out.println("no such a function.");
        return -1;
    }

    @Override
    public void setVolume(int volume) {
        System.out.println("no such a function.");
    }

    @Override
    public int getVolume() {
        System.out.println("no such a function.");
        return -1;
    }
}
