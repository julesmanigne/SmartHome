# ESP32 Smart Home
## Build a Smart Home using ESP32 


![GitHub](https://img.shields.io/github/license/julesmanigne/SmartHome?color=ye)
![GitHub repo size](https://img.shields.io/github/repo-size/julesmanigne/SmartHome?color=purple)
![GitHub last commit](https://img.shields.io/github/last-commit/julesmanigne/SmartHome?color=yellow&logo=GitHUb&logoColor=yellow)
## Summary

This project describes how to build a Smart station using ESP32, a BMP388 (temperature sensor), DHT22 (humidity sensor), a SSD1306 (OLED screen) and some LEDs. 

## 🛠️ Installation
### With MacOS
#### 🍺 Install HomeBrew
**Homebrew** (brew) is a free and open-source package manager that allows installing apps and software in macOS, depending on the user’s desire. It has been recommended for its simplicity and effectiveness in saving time and effort. Its famous description is “The missing package manager for macOS”
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
**Node-RED** can be used on all platforms that can run Node.js. Node-RED supports Node.js 0.10.x or later. It is recommended to use the LTS (long-term maintenance) version of Node.js. 
We will now use Homebrew to install Node.js and Node-Red. 

##### Node.js
To install **Node.js** (npm will be installed with Node) run the following command :

```bash 
brew install node
```
![NodeJS-Install](https://github.com/julesmanigne/SmartHome/blob/master/img/NodejsInstall.png)

Congratulations you’ve installed Node.js & npm

##### Node-RED
To install **Node-RED** you can use the npm command that comes with Node.js :
```bash 
sudo npm install -g --unsafe-perm node-red
```
Then, you just have to start with the ```node-red``` command. At first boot, the necessary directories and files will be created automatically.  

![NodeRED-Install](https://github.com/julesmanigne/SmartHome/blob/master/img/NoderedInstall.png)

Enter the IP address of the specified server, by default it will be **127.0.0.1:1880**

#### Install Mosquitto
Open a Terminal window and run the following command to request Homebrew to install **Mosquitto** :
```bash 
brew install mosquitto
```

### With Windows

## Quick Start

## Schematics

![ESP32 Smart Home](https://github.com/julesmanigne/SmartHome/blob/master/img/Fritzing-Schematic.jpeg)

## 📝 License

[MIT-License](https://www.mit.edu/~amini/LICENSE.md)
