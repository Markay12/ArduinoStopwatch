# ArduinoStopwatch
Basic counting stopwatch for Arduino

So you want to Build an Arduino Stopwatch! That's awesome and a great starting project for anyone!  

---

## Table of Contents
1. Necessary Items  
2. Getting Started  
3. Software and Downloads
4. Begin to Code our Arduino
5. Full Code


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

1. Now that we have our items, we can take the LCD Keypad and connect it to the pins on the UNO Board. (Make sure to line them up and press down)  

<img src="/media/StepOneConnection.jpg" width="200">

2. Connect your Standard USB Cable to the Arduino UNO Board and connect it to your computer.  
3. Now we are ready to begin and can go over to our computer!  

---

### Software and Downloads

In order to properly program and upload our code to our new Arduino device, we need to use the [Arudino IDE](https://www.arduino.cc/en/software)
- The current version at time of publication is IDE 1.8.13, however, most information should not see a large update

<img src="/media/ArduinoTemplate.png" width="600">

We now have all the software that we need and can begin working on our Stopwatch!

---

### Understanding Arduino

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
    - The issue described here will not pertain to our project. However, this is something to understand for later interest

---

### Begin to Code your Arduino

Great! Now that you have everything else setup, we can begin to code our Arduino stopwatch!  

Let's take a look back at our code and begin  

1. The first thing we are going to want to pay attention to is making sure that we include valuable imports for a working LCD screen  
    - These two lines of code will import important libraries that allow us to communicate with our LCD screen and display our data  

```c++

#include <SPI.h>
#include <LiquidCrystal.h>

//not used now, at a later time --> used as reference
void setup()
{

}

void loop()
{

}

```

2. Now we are going to do two things before getting into our `setup()` method
    - The first thing is setting up which pins we are using on our LCD shield which correlate physically with how we want to view our displayed information
    - Secondly, we are going to create some variables that are used for counting and making a stopwatch. A start, stop and elapsed time.

* These lines of code are going to be in between the `#include <LiquidCrystal.h>` and `void setup()` lines  
* Unsigned long variables are extended size variables for number storage, and store 32 bits (4 bytes). Unlike standard longs unsigned longs won’t store negative numbers, making their range from 0 to 4,294,967,295 (2^32-1)
    - Since we cannot count time in a negative range, it makes sense to used unsigned. The long is used because we don't know how long we are going to be running the stopwatch in the future


```c++
//pins used on the LCD Shield
LiquidCrystal lcd(8,13,9,4,5,6,7);

//variables used when handling our stopwatch data
unsigned long start_time;
unsigned long finish_time;
unsigned long time_elapsed;
boolean r = false;
```

3. Now we are ready to move into our `void setup()` code and we can start with something cool to get setup! 
    - Remember that this code is ran once and should just be used to setup the arduino device  
    - We are going to do this in two steps, the first step is going to show your true programming power  

```c++
void setup()
{

    lcd.begin(16,2);
    lcd.print("Hello World!");
    lcd.setCursor(3,1);
    lcd.print("I'm Alive!");

}
```


Awesome! You've now uploaded the first few words to your arduino device! But how do we get this to display?  
1. Head to `Tools` at the top of your Arduino IDE
2. Once there, you should see port as one of the options
3. Make sure that your Arduino device is connected to a powered USB port in your computer and select this port

<img src="/media/ToolsTest.png" width="400">

If this does not work reference Part 6 of the tutorial where we work through device manager to get this setup  

Now we can actually display some important information for our Arduino stopwatch!  
We will be changing what we have typed previously in our `void setup()` method, but it will have the same general approach  

```c++
void setup()
{

    lcd.begin(16, 2); //initialize the lcd 16 characters and 2 line
    lcd.print("Mark's"); //your name
    lcd.setCursor(3,1); //set cursor to the fourth char on line 2
    lcd.print("Stopwatch");
    delay(2000); //wait two seconds
    lcd.clear(); //clear the lcd display
    lcd.print("Press SELECT for");
    lcd.setCursor(2,1); //set cursor to the third char on line 2
    lcd.print("Start & Stop");

}
```

Great! Now we can begin working on our loop! But what a good start! Getting ready to continue!  

---

### Coding the Loop method

