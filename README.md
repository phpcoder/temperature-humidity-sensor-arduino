# Arduino Library to support 433.92 MHz Temperature/Humidity Sensors with Nexux/Rubiscon Protocol


![Wireless Temperature-Humidity Sensors](img/nexus_sensors.jpg)

This simple Arduino library adds a capability to decode Temperature/Humidity data sent by cheap wireless sensors similar to the ones shown on the picture. A setup should include a 433.92 MHz receiver module connected to one of the GPIO pin.

## Use
SRX882 superheterodine receiver module is recommended for this setup. It allows to get a reliable signal with minimum noise from its DATA pin (pin #5).

The project includes a PlatformIO config file example for Wemos D1 mini ESP8266 board and a sketch to print sensor temperature/humidity data. It is required to specify a GPIO number connected to the receiver.




## Links

* [PlatformIO](https://platformio.org/) - Professional collaborative platform for embedded development.
* [Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini_3.1.0.html) - A mini wifi board with 4MB flash based on ESP-8266EX.
