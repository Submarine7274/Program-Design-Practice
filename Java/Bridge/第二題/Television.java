public class Television implements Device {
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
        System.out.println("turn on tv");
    }

    @Override
    public void turnOff() {
        state = false;
        System.out.println("turn off tv");
    }

    @Override
    public void setChannel(int channel) {
        if (!state) {
            System.out.println("tv not turned on");
            return;
        }
        if (channel >= 1 && channel <= 128) {
            if (channel > this.channel) {
                System.out.println("tv channel up");
            } else {
                System.out.println("tv channel down");
            }
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
            System.out.println("tv not turned on");
            return;
        }
        if (volume >= 0 && volume <= 100) {
            if (volume > this.volume) {
                System.out.println("tv volume up");
            } else {
                System.out.println("tv volume down");
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
