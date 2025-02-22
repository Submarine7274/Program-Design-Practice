/*Q2
功能說明：
電器包含以下幾種：電視機、收音機、電冰箱、空調
可以控制開關、音量、頻道、溫度等
音量在0~100之間
一共有128個頻道，在1~128之間
冰箱溫度可設定在-10~4度之間
空調溫度可設定在16~29度之間

Interface Device 說明：
有一個int i = 0
有一個abstract method isOn()檢查是否開啟
有一個abstract method void turnOn()
有一個abstract method void turnOff()
有一個abstract method void setChannel(int channel)
有一個abstract method int getChannel()
有一個abstract method void setVolume(int volume)
有一個abstract method int getVolume ()
有一個abstract method void setTemperature(int degree)
有一個abstract method int getTemperature ()

Class Radio 說明：
Radio需要實作Device
Radio有一個bool state = false
Television有一個int Volume = 20
Television有一個int Channel = 1
Radio實作setChannel(int channel)
Radio實作getChannel()
Radio實作setVolume(int volume)
Radio實作getVolume ()

Class Television 說明：
Television需要實作Device
Television有一個bool state = false
Television有一個int Volume = 20
Television有一個int Channel = 1
Television實作setChannel(int channel)
Television實作getChannel()
Television實作setVolume(int volume)
Television實作getVolume ()

Class Refrigerator 說明：
Refrigerator需要實作Device
Refrigerator有一個bool state = false
Refrigerator有一個int Temperature = 2
Refrigerator實作setTemperature(int degree)
Refrigerator實作setTemperature()

Class AirConditioner 說明：
AirConditioner需要實作Device
AirConditioner有一個bool state = false
AirConditioner有一個int Temperature = 25
AirConditioner實作setTemperature(int degree)
AirConditioner實作setTemperature()

Class Remote 說明：
Remote有一個 Device device
Remote有一個建構子 Remote(String device)
Remote有一個 abstract void togglePower()

Class MediaRemote 說明：
MediaRemote繼承 Remote
MediaRemote有一個建構子 MediaRemote(String device)
MediaRemoteRemote實作void togglePower()
MediaRemoteRemote實作void temperatureUp()
MediaRemoteRemote實作void temperatureDown()

Class MediaRemote 說明：
MediaRemote繼承 Remote
MediaRemote有一個建構子 MediaRemote(String device)
MediaRemoteRemote實作void togglePower()
MediaRemoteRemote實作void volumeUp()
MediaRemoteRemote實作void volumeDown()
MediaRemoteRemote實作void channelUp()
MediaRemoteRemote實作void channelDown()

Class Main 說明：
Main需要建立Remote物件
Main執行流程：
輸入一個String 選擇要控制的裝置
tv: 電視機
rd: 收音機
rf: 電冰箱
ac: 空調
輸入指令操控機器
Pwr: 電源開關
vup: 音量上升
Vdn: 音量下降
Cup: 頻道上升
Cdn: 頻道下降
Tup: 溫度上升
Tdn: 溫度下降
exit: 退出
如果輸入錯誤，輸出"no such a function."。
輸入：
tv
Pwr
Vup
Vdn
Cup
Cup
Cdn
Cdn
exit
輸出：
turn on tv
tv volume up
tv volume down
tv channel up
tv channel up
tv channel down
tv channel down
 */