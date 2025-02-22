public class Radio implements Device {
    private boolean state = false;
    private int volume = 20;
    private int channel = 1;

    @Override
    public boolean isOn() {
        return state;
    }

    @Override
    public void turnOn() {
        state = true;
        System.out.println("turn on rd");
    }

    @Override
    public void turnOff() {
        state = false;
        System.out.println("turn off rd");
    }

    @Override
    public void setChannel(int channel) {
        if (!state) {
            System.out.println("rd not turned on");
            return;
        }
        if (channel >= 1 && channel <= 128) {
            System.out.println("rd channel up");
            this.channel = channel;
        } else {
            System.out.println("invalid channel");
        }
    }

    @Override
    public int getChannel() {
        return channel;
    }

    @Override
    public void setVolume(int volume) {
        if (!state) {
            System.out.println("rd not turned on");
            return;
        }
        if (volume >= 0 && volume <= 100) {
            if (volume > this.volume) {
                System.out.println("rd volume up");
            } else {
                System.out.println("rd volume down");
            }
            this.volume = volume;
        } else {
            System.out.println("invalid volume");
        }
    }

    @Override
    public int getVolume() {
        return volume;
    }

    @Override
    public void setTemperature(int degree) {
        System.out.println("no such a function.");
    }

    @Override
    public int getTemperature() {
        System.out.println("no such a function.");
        return -1;
    }
}
