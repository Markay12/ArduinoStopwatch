/*
 * Arduino Stopwatch
 * Mark Ashinhust
 */

 #include <SPI.h>
 #include <LiquidCrystal.h>

 //pins that are used on the shield
 LiquidCrystal lcd(8,13,9,4,5,6,7);

 //variables used for counting mechanism
 unsigned long start_time, finish_time, time_elapsed;
 boolean r = false;

 //vars for button debounce time
 long timeSinceLastPress = 0; //time since last button press
 long debounceDelay = 50; //the debounce time, set as low as possible

 void setup(){

  lcd.begin(16, 2); //initialize the lcd 16 characters and 2 line
  lcd.print("Simple");
  lcd.setCursor(3,1); //set cursor to the fourth char on line 2
  lcd.print("Stopwatch");
  delay(2000); //wait two seconds
  lcd.clear(); //clear the lcd display
  lcd.print("Press SELECT for");
  lcd.setCursor(2,1); //set cursor to the third char on line 2
  lcd.print("Start & Stop");
  
 }

 void loop(){

  CheckStartStop();
  DispResult();
  
 }

 void CheckStartStop(){

  int x = analogRead(0); //assign 'x' to the AnalogueInput (Shield button)
  if (x < 800 && x < 600) //if the button SELECT was pressed
  {
    if ((millis() - timeSinceLastPress) > debounceDelay)
    {
      if (r ==false){
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Elapsed Time");
        start_time = millis(); //save start time, difference to be used for elapsed
      }
      else if(r=true)
      {
        lcd.setCursor(2, 0);
        lcd.print(" Final Time ");
        
      }
      r = !r;
    }
    timeSinceLastPress = millis();
  }
 }

 void DispResult()
 {

  if (r==true)
  {
    finish_time = millis(); //save the stop time, calculate difference for elapsed time
    //declare calculation variables
    float h, m, s, ms;
    unsigned long over;

    time_elapsed = finish_time - start_time;
    h = int(time_elapsed/ 3600000); //calculate hours
    over = time_elapsed % 3600000; //remainder of hours calculation
    m = int(over/60000); //calculate minutes with remainder of hours
    over = over % 60000; //remainder of minutes
    s = int(over / 1000); //calculate seconds
    ms = over % 1000; //remainder of seconds

    //display final results
    lcd.setCursor(0, 1);
    lcd.print(h, 0); //disp hours 
    lcd.print("h "); //use h for spacing instead of hours

    lcd.print(m, 0); //disp minutes
    lcd.print("m ");
    
    lcd.print(s, 0); //disp seconds
    lcd.print("s ");

    if (h < 10) //if hours are less than double digits we will have enough room
    {
      lcd.print(ms, 0); //disp milliseconds
      lcd.print("ms -");
    }
  }

 }
