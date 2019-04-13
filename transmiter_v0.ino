/*
 *  serial transmiter with keypad shield
 * adapted by Nicu FLORICA (niq_ro)
 * use info from https://www.dfrobot.com/wiki/index.php/Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009)
 * v.0 - 13.04.2019 - Craiova, Romania
*/

//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************
Original program test the LCD panel and the buttons
Mark Bramwell, July 2010
Small changes by Nicu FLORICA (niq_ro) to see step from 1024
********************************************************/

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
/*
  For V1.1 us this threshold
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  
*/
 // For V1.0 comment the other threshold and use the one below:

 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   



 return btnNONE;  // when all others fail, return this...
}

void setup()
{
 Serial.begin(9600);
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Push the buttons"); // print a simple message
}

void loop()
{
 lcd.setCursor(7,1);            // move cursor to second line "1" and 9 spaces over
// lcd.print(millis()/1000);      // display seconds elapsed since power-up
if (adc_key_in < 1000) lcd.print(" ");
if (adc_key_in < 100) lcd.print(" ");
if (adc_key_in < 10) lcd.print(" ");

lcd.print(adc_key_in);
lcd.print("/1024");
 
 lcd_key = read_LCD_buttons();  // read the buttons


lcd.setCursor(0,1);            // move to the begining of the second line
 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd.print("RIGHT ");
     Serial.println("command1");
     break;
     }
   case btnLEFT:
     {
     lcd.print("LEFT   ");
      Serial.println("command2");
     break;
     }
   case btnUP:
     {
     lcd.print("UP    ");
      Serial.println("command3");
     break;
     }
   case btnDOWN:
     {
     lcd.print("DOWN  ");
      Serial.println("command4");
     break;
     }
   case btnSELECT:
     {
     lcd.print("SELECT");
     Serial.println("command5");
     break;
     }
     case btnNONE:
     {
     lcd.print("NONE  ");
     break;
     }
 }
delay(100);
}
