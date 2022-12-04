# ESP32 Smart Home
## Build a Smart Home using ESP32 

![GitHub](https://img.shields.io/github/license/julesmanigne/SmartHome?color=brightgreen)
![GitHub repo size](https://img.shields.io/github/repo-size/julesmanigne/SmartHome?color=blueviolet)
![GitHub last commit](https://img.shields.io/github/last-commit/julesmanigne/SmartHome?color=blue&logo=GitHub&logoColor=blue)
## Introduction

This project describes how to build a Smart station using ESP32, a BMP388 (temperature sensor), DHT22 (humidity sensor), a SSD1306 (OLED screen) and some LEDs.
- [🛠️ Installation](#%EF%B8%8F-installation)
    - [On MacOS](#on-macos)
        - [🍺 Install HomeBrew](#-install-homebrew)
        - [Install Node-RED](#install-node-red)
            - [Node.js](#nodejs)
            - [Node-RED](#node-red)
        - [Install Mosquitto](#install-mosquitto)
        - [Install Arduino](#install-arduino)
            - [ESP-32](#esp-32)
    - [On Windows](#on-windows)
        - [Install Node-RED](#install-node-red-1)
            - [Node.js](#nodejs-1)
            - [Node-RED](#node-red-1)
        - [Install Mosquitto](#install-mosquitto-1)
        - [Install Arduino](#install-arduino-1)
            - [ESP-32](#esp-32-1)
- [Quick Start](#quick-start)
    - [Start Node-RED](#Start-Node-RED)
        - [Terminal](#Terminal)
        - [Localhost](#Localhost)
    - [Start MQTT](#Start-MQTT)
        - [Subscribe to a topic](#Subscribe-to-a-topic)
        - [Publish to a topic](#Publish-to-a-topic)
    - [](#)

- [Schematics](#schematics)  

## 🛠️ Installation
### On MacOS
#### 🍺 Install HomeBrew
[**Homebrew**](https://brew.sh/index_fr) (brew) is a free and open-source package manager that allows installing apps and software in macOS, depending on the user’s desire. It has been recommended for its simplicity and effectiveness in saving time and effort. Its famous description is “The missing package manager for macOS”
Homebrew lets you avoid possible security problems associated with using the ```sudo``` command to install software like Node.

Installing Homebrew is straightforward as long as you understand the Mac Terminal. The Homebrew installation process guides through each step.

You need Xcode for some Homebrew tools, Xcode is a macOS integrated development environment (IDE). You can use it to make apps for all mac OSs, iOS, iPad OS, watch OS, and tv OS. To download and install it, run the following command in the Terminal:

```bash
xcode-select --install
```
Accept starting the installation and the license, it will be installed automatically.<br>
Now, to install Homebrew automatically, run the below command for macOS High Sierra, Sierra, El Capitan, and earlier :
```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
And run this command for MacOS Catalina, macOS Mojave, and macOS Big Sur :
```bash 
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```
Homebrew is now installed, to make sure it is up to date you can run the following commmand : 
``` brew update``` 

#### Install Node-RED

[**Node-RED**](https://nodered.org/) can be used on all platforms that can run Node.js. Node-RED supports Node.js 0.10.x or later. It is recommended to use the LTS (long-term maintenance) version of Node.js. 
We will now use ***Homebrew*** to install Node.js and Node-Red. 

##### Node.js

To install [**Node.js**](https://formulae.brew.sh/formula/node#default) (npm will be installed with Node) run the following command :

```bash 
brew install node
```
![NodeJS-Install](https://github.com/julesmanigne/SmartHome/blob/master/img/NodejsInstall.png)

Congratulations you’ve installed Node.js & npm, to check the version you can run the following commmand : 
- ``` node -version``` 
- ``` npm -version```

If the Node.js version and npm are correctly installed, you’ll see the version name in the Terminal. 

##### Node-RED

To install **Node-RED** you can use the npm command that comes with Node.js :
```bash 
sudo npm install -g --unsafe-perm node-red
```
Once installed, you are ready to run Node-RED, you just have to start with the ```node-red``` command. At first boot, the necessary directories and files will be created automatically.   

![NodeRED-Start](https://github.com/julesmanigne/SmartHome/blob/master/img/NoderedInstall.png)

Enter the IP address of the specified server, by default it will be **127.0.0.1:1880**.

#### Install Mosquitto

Open a Terminal window and run the following command to request Homebrew to install **Mosquitto** :
```bash 
brew install mosquitto
```
After the Mosquitto installation has been completed, run the following command in a new Terminal window to launch Mosquitto with the default configuration. 
```bash 
/usr/local/sbin/mosquitto -c /usr/local/etc/mosquitto/mosquitto.conf
```

- To ***start*** the broker, run the following command : ```brew services start mosquitto```
- To ***stop*** the broker, run the following command : ```brew services stop mosquitto```

#### Install Arduino 

Get the latest version of **Arduino** from the [**download page**](https://www.arduino.cc/en/software). The file is in zip format, if you use Safari it will be automatically extracted. If you use a different browser you may need to extract it manually.

Then, copy the Arduino application bundle into the Applications folder (or elsewhere on your computer).

##### ESP-32 

To install the ESP32 board in your Arduino IDE, follow these next instructions : <br>
In your Arduino IDE, go to File> Preferences : 

Enter the following into the ***Additional Board Manager URLs*** field : <br>
```https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json```

Next, open the Boards Manager, go to Tools > Board > Boards Manager, search for ESP32 and press install button for the *ESP32 by Espressif Systems*. That’s it. It should be installed after a few seconds.

### On Windows
#### Install Node-RED
[**Node-RED**](https://nodered.org/) can be used on all platforms that can run Node.js. Node-RED supports Node.js 0.10.x or later. It is recommended to use the LTS (long-term maintenance) version of Node.js. 

##### Node.js

First, you need to download the Windows Installer (.msi) file from the official [**Node.js**](https://nodejs.org/en/download/) website. This MSI installer database carries a collection of installer files essential to install, update, or modify the existing Node.js version.

Notably, the installer also carries the Node.js package manager (npm) within it. It means you don’t need to install the npm separately.

When downloading, select the correct version as per your operating system. For example, if you’re using a 64-bit operating system, download the 64-bit version, and if you’re using the 32-bit version, download the 32-bit version

Once you open and run the .msi file, the installation process begins. But you have to set a few parameters before running the installation process. The system will complete the installation within a few seconds or minutes and show you a success message. 
Click on the Finish button to close the Node.js installer.

Congratulations you’ve installed Node.js & npm, to check the version you can run the following commmand : 
- ``` node --version``` 
- ``` npm --version```

##### Node-RED

To install **Node-RED** you can use the same npm command as MacOS that comes with Node.js :
```bash 
sudo npm install -g --unsafe-perm node-red
```
Once installed, you are ready to run Node-RED, you just have to start with the ```node-red``` command. At first boot, the necessary directories and files will be created automatically.  

Enter the IP address of the specified server, by default it will be **127.0.0.1:1880**.

#### Install Mosquitto

Download **Mosquitto** from https://mosquitto.org/download/ and install it, if you install it with the “Service” checkbox checked, it will start automatically with Windows and occupy the default port **1883**.

If you installed Mosquitto this way you can disable the service by going into the Services
menu in Windows and pressing the stop button with the Mosquitto Broker selected. 

The installation path is by default : ***C:\Program Files\mosquitto***, navigate to the folder with cmd.exe using : <br>
```cd C:\”Program Files”\mosquitto```

Running the command ```mosquitto.exe -v``` will start the broker. 
For more information check this tutorial : [**Mosquitto-Install**](https://team-ethernet.github.io/guides/How%20to%20install%20and%20use%20Mosquitto%20for%20Windows.pdf)

#### Install Arduino

Get the latest version of **Arduino** from the [**download page**](https://www.arduino.cc/en/software). You can choose between the Installer (.exe) and the zip packages. We suggest you use the first one that installs directly everything you need to use the Arduino Software (IDE), including the drivers. 

With the zip package you need to install the drivers manually. The zip file is also useful if you want to create a portable installation.

##### ESP-32 

To install the ESP32 board in your Arduino IDE, follow these next instructions : <br>
In your Arduino IDE, go to File> Preferences : 

Enter the following into the ***Additional Board Manager URLs*** field : <br>
```https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json```

Next, open the Boards Manager, go to Tools > Board > Boards Manager, search for ESP32 and press install button for the *ESP32 by Espressif Systems*. That’s it. It should be installed after a few seconds.

## Quick Start
### Start Node-RED 
#### Terminal 
As mentionned abovve, to start Node-RED, you just have to run the ```node-red``` command : 

![NodeRED-start](https://github.com/julesmanigne/SmartHome/blob/master/img/NoderedInstall.png)
> (**MacOS**)

#### Localhost 
In order to access to Node-RED in your browser (Chrome, FireFox, Safari, etc), enter the IP address of the specified server, by default it will be [**127.0.0.1:1880**](http://127.0.0.1:1880/).
You should have something that looks like this : 

![NodeRED-browser](https://github.com/julesmanigne/SmartHome/blob/master/img/Node-RED-Browser.png)

### Start MQTT 
Open your terminal again, enter the following command : 
```bash 
brew services start mosquitto
```

#### Subscribe to a topic

```bash
mosquitto_sub -t inTopic
``` 
With this command we subscribe to a topic called **"inTopic"**, it means that we will received everything that will be published on the topic. 
#### Publish to a topic
Then, we may want to publish something on the inTopic which can be done using this command : 
```bash
mosquitto_pub -t inTopic  -m "hellow world"
``` 
## Schematics

![ESP32 Smart Home](https://github.com/julesmanigne/SmartHome/blob/master/img/Fritzing-Schematic.jpeg)
#### Parts : 
- 1x Breadboard 
- 1x ESP32 Dev board (/ ESP8266 NodeMCU) 
- 1x OLED screen SSD1306
- 2x BMP388 Adafruit (/ BMP280)
- 2x DHT11 (/ DHT22) 
- 6x LEDs 
## 📝 License

[MIT-License](https://www.mit.edu/~amini/LICENSE.md)
