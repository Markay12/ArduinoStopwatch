# ArduinoStopwatch
Basic counting stopwatch for Arduino

So you want to Build an Arduino Stopwatch! That's awesome and a great starting project for anyone!  

---

## Table of Contents
1. Necessary Items  
2. Getting Started  
3. Software and Downloads


### Necessary Items
There are a few things you are going to need to get started!  
1. Arduino UNO Board found on [Amazon](https://www.amazon.com/gp/product/B008GRTSV6/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1)  
    - Purchased on Amazon for around $20 on Sale and $30 MSRP  
2. DFROBOT Gravity: 1602 LCD Keypad Shield found on [Amazon](https://www.amazon.com/gp/product/B006D903KE/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1)  
    - Used to display stopwatch letters on screen  
3. Standard USB-DataSync Cable for Arduino UNO found on [Amazon](https://www.amazon.com/gp/product/B08RCJXY1Z/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1)  

You will also need a computer where you can connect your Arduino and get started!  

---

### Getting Started!

First, you need to make sure you have all the necessary materials as described above.  
Once you have all of these we can begin!  

Here is what we have to begin with!  

<img src="/media/UNOBoard.jpg" style="float: left; width: 30%; margin-right: 1%; margin-bottom: 0.5em;" width="200">
<img src="/media/LCDDisp.jpg" style="float: left; width: 30%; margin-right: 1%; margin-bottom: 0.5em;" width="200">
<img src="/media/USBCable.jpg" style="float: left; width: 30%; margin-right: 1%; margin-bottom: 0.5em;" width="200">
<p style="clear: both;">

1. Now that we have our items, we can take the LCD Keypad and connect it to the terminals on the UNO Board. (Make sure to line them up and press down)  

<img src="/media/StepOneConnection.jpg" width="200">

2. Connect your Standard USB Cable to the Arduino UNO Board and connect it to your computer.  
3. Now we are ready to begin and can go over to our computer!  

---

### Software and Downloads

In order to properly program and upload our code to our new Arduino device, we need to use the [Arudino IDE](https://www.arduino.cc/en/software)
- The current version at time of publication is IDE 1.8.13, however, most information should not see a large update

<img src="/media/ArduinoTemplate.png" width="200">

We now have all the software that we need and can begin working on our Stopwatch!

---

### Understanding Arduino and Code

The first thing you are going to notice when you begin the Arduino software is the blank template provided.  
This template begins with two void methods, returning no output but instead controlling the actions of our Arduino  

There are two methods that are written here:  
1. setup()
2. loop()  

`void setup()` is only ran once when we begin our Arduino and sets up our device for its purpose  
- This is important as it allows us to prepare everything for our stopwatch rather than having to worry about small changes in later stages  

`void loop()` - This is what really allows the stopwatch to come alive and our Arduino to work  
- For our stopwatch(any digital watch) to function the time must be constantly updated and kept track of. Not only does time need to be synced but also uploaded to the device and to the screen periodically. 
- This means, if we had a stopwatch that was updating the screen every millisecond... we would need to update our screen at least every millisecond.
    - A small issue with this is that it should be a proper subdivision of one millisecond. Suppose we chose 0.728/1 millisecond to update. Then we would see solid increments in time, however, when the millisecond would change from 1 to 2, our update would be off. This is because, though we are updating quicker than the time period it will not properly display the times as they change.
    - The issue here should not be of issue, but something to understand for later interest

    

