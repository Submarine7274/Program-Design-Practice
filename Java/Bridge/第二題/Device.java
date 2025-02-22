public interface Device {
    boolean isOn();
    void turnOn();
    void turnOff();
    void setChannel(int channel);
    int getChannel();
    void setVolume(int volume);
    int getVolume();
    void setTemperature(int degree);
    int getTemperature();
}