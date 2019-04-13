/*
 serial receiver
 use Serial Event example -  http://www.arduino.cc/en/Tutorial/SerialEvent
 adapted by Nicu FLORICA (niq_ro)
 v.0 - 13.04.2019, Craiova, Romania
*/

#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define led5 8

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

pinMode(led1, OUTPUT);
digitalWrite(led1, LOW); 
pinMode(led2, OUTPUT);
digitalWrite(led2, LOW); 
pinMode(led3, OUTPUT);
digitalWrite(led3, LOW); 
pinMode(led4, OUTPUT);
digitalWrite(led4, LOW); 
pinMode(led5, OUTPUT);
digitalWrite(led5, LOW); 
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
  if(inputString.indexOf("command1")>=0)
    {
      Serial.println("-");
      digitalWrite(led1, HIGH);
      delay(100);
      digitalWrite(led1, LOW);
    }
  if(inputString.indexOf("command2")>=0)
    {
      Serial.println("--");
      digitalWrite(led2, HIGH);
      delay(100);
      digitalWrite(led2, LOW);
    }
  if(inputString.indexOf("command3")>=0)
    {
      Serial.println("---");
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
    }
  if(inputString.indexOf("command4")>=0)
    {
      Serial.println("-----");
      digitalWrite(led4, HIGH);
      delay(100);
      digitalWrite(led4, LOW);
    }
  if(inputString.indexOf("command5")>=0)
    {
      Serial.println("------");
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led5, LOW);
    }
       
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
} // end of program

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() 
{
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n')    
    stringComplete = true;
    }  
}
