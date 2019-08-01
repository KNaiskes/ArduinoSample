## Simple LCD screen (16x2) program.

### Install platformio and dependencies
```
$ python -m venv venv # Create a virtual enviroment
$ source venv/bin/activate # Activate virtual enviroment
$ platformio init --board uno
$ platformio lib install "LiquidCrystal_I2C"
```

### Upload code to Arduino
```
# It may be necessary to change permission to ttyUSB0
# $ sudo chmod 777 /dev/ttyUSB0
$ platformio run --target upload
```

### Pinout connections

| I2C | Arduino |
|-----|:-------:|
|GND  | GND     |
|VCC  | 5V      |
|SDA  | A4      |
|SCL  | A5      |
