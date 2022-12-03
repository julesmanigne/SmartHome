# ESP32 Smart Home
## Build a Smart Home using ESP32 


![GitHub](https://img.shields.io/github/license/julesmanigne/SmartHome?color=success)
![GitHub repo size](https://img.shields.io/github/repo-size/julesmanigne/SmartHome?color=purple)
![GitHub last commit](https://img.shields.io/github/last-commit/julesmanigne/SmartHome?color=blueviolet&logo=GitHUb&logoColor=yellow)
## Summary

This project describes how to build a Smart station using ESP32, a BMP388 (temperature sensor), DHT22 (humidity sensor), a SSD1306 (OLED screen) and some LEDs.
- [🛠️ Installation](#🛠️-installation)
    - [On MacOS](#on-macos)
        - [🍺 Install HomeBrew](#🍺-install-homebrew)
        - [Install Node-RED](#install-node-red)
            - [Node.js](#node.js)
            - [Node-RED](#node-red)
        - [Install Mosquitto](#install-mosquitto)
    - [On Windows](#on-windows)
- [Quick Start](#quick-start)
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
Accept starting the installation and the license, it will be installed automatically.

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
We will now use Homebrew to install Node.js and Node-Red. 

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

![NodeRED-Install](https://github.com/julesmanigne/SmartHome/blob/master/img/NoderedInstall.png)

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

The installation path is by default: C:\Program Files\mosquitto
Navigate to the folder with cmd.exe using cd C:\”Program Files”\mosquitto

Running the command ```mosquitto.exe -v``` will start the broker. 
For more information check this tutorial : [**Mosquitto-Install**](https://team-ethernet.github.io/guides/How%20to%20install%20and%20use%20Mosquitto%20for%20Windows.pdf)
## Quick Start

## Schematics

![ESP32 Smart Home](https://github.com/julesmanigne/SmartHome/blob/master/img/Fritzing-Schematic.jpeg)
#### Parts : 
- 1x Breadboard 
- 1x ESP32 Dev board / ESP8266 NodeMCU (can do the job too)
- 1x OLED screen (SSD1306)
- 2x BMP388 Adafruit / BMP280 (can do the job too)
- 2x DHT11 / DHT22 (can do the job too)
- 6x LEDs 
## 📝 License

[MIT-License](https://www.mit.edu/~amini/LICENSE.md)
