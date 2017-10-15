# Clear Lung Project - Hardware Subteam
## Project Overview
- Current main files to use are `raspiI2Ctest.py` and `teensyAudioInRaspiOut`
- 10/15/17: Got I2C working between raspi and teensy, but still need to test if the right values are being sent when doing a higher speed transfer.

<br><br>
## How to get started
### 1. Setup the Arduino IDE
- Download and install from: https://www.arduino.cc/en/Main/Software
- Install the teensy addon: https://www.pjrc.com/teensy/loader.html
### 2. Install Git
Choose one of the following options:
- [Instructions for *Windows*](https://gist.github.com/derhuerst/1b15ff4652a867391f03#file-linux-md)
- [Instructions for *Mac*](https://gist.github.com/derhuerst/1b15ff4652a867391f03#file-mac-md)
- [Instructions for *Linux*](https://gist.github.com/derhuerst/1b15ff4652a867391f03#file-linux-md)
### 3. Clone this Repo
- Make a folder on your computer to store these files
- Make a local copy (clone) of these files: `git clone https://github.com/jtcostello/ClearLungProject-Hardware`

<br><br>
## How to use this repo
### Pull the Current Code
- `git pull` to get the current version of the code
### Open and Run the code
- open `teensyAudioInRaspiOut` in Arduino, load onto the teensy
- open a terminal on raspi in the same directory as the python code
  - `python raspiI2Ctest.py` to run on raspi
- *Start the teensy code before starting the raspi code to avoid errors*
### Push Updated Code to Github
- if you made changes and understand how git works, publish code changes:
  - `git add .` to add all the files
  - `git commit -m "what changes I made"` to commit changes
  - `git push -u origin master` to submit to github

<br><br>
## Wire Connections
- 3 connections between Raspi and Teensy (for i2c): 
  - connect `ground` pins
  - connect `SCL0` pins
  - connect `SDA0` pins
- 2 connections between Teensy and Source (mic or signal generator)
  - connect `ground` pins
  - connect `A0` on teesy to the signal
- For getting started we used https://oscarliang.com/raspberry-pi-arduino-connected-i2c/.
- See `raspiTeensyI2C_test` for teensy testing code. 
### Teensy Pinout
![Teensy Pinout](https://github.com/jtcostello/ClearLungProject-Hardware/blob/master/ReferenceDocs/teensy3.2pinout.png)
### Raspi Pinout
![Raspi Pinout](https://github.com/jtcostello/ClearLungProject-Hardware/blob/master/ReferenceDocs/raspiGPIOpinout.png)
### I2C Connections (ignore the Arduino pin numbers)
![I2C Setup](https://github.com/jtcostello/ClearLungProject-Hardware/blob/master/ReferenceDocs/teensy_raspi_connections.png)


