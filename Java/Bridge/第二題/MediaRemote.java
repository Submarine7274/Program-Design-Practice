public class MediaRemote extends Remote {

    public MediaRemote(Device device) {
        super(device);
    }

    @Override
    public void togglePower() {
        if (device.isOn()) {
            device.turnOff();
        } else {
            device.turnOn();
        }
    }

    public void volumeUp() {
        if (device.isOn()) {
            device.setVolume(device.getVolume() + 1);
        } else {
            System.out.println("Device not turned on");
        }
    }

    public void volumeDown() {
        device.setVolume(device.getVolume() - 1);
    }

    public void channelUp() {
        device.setChannel(device.getChannel() + 1);
    }

    public void channelDown() {
        device.setChannel(device.getChannel() - 1);
    }

    public void temperatureUp() {
        device.setTemperature(device.getTemperature() + 1);
    }

    public void temperatureDown() {
        device.setTemperature(device.getTemperature() - 1);
    }
}
