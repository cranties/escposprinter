#include <SoftwareSerial.h>

#include "escposprinter.h"

#define ledPin 13
#define rxPin 6
#define txPin 7

int printStatus = 0;

EscPos ESCPOS = EscPos(rxPin, txPin); // init the Printer with Output-Pin

void setup()
{
  Serial.begin(9600); //open the USB connection too
  
  delay(1000);

  ESCPOS.start();
  ESCPOS.justifyCenter();
  ESCPOS.println("Hello World start");  
  
  ESCPOS.justifyLeft();
  ESCPOS.println("Feed 3 start");  
  ESCPOS.feed(3); 
  ESCPOS.println("Feed 3 end");  
  ESCPOS.feed(2); 
  ESCPOS.lineSpacing(30);  
  ESCPOS.println("line spacing 30 start");  
  ESCPOS.println("line spacing 30 end");  
  ESCPOS.feed(2); 

  ESCPOS.lineSpacing(90);  
  ESCPOS.println("line spacing 90 start");  
  ESCPOS.println("line spacing 90 end");  
  ESCPOS.feed(2);  
  
  ESCPOS.defaultLineSpacing();  
  ESCPOS.println("default line spacing (60) start");  
  ESCPOS.println("default line spacing (60) end");  
  
  ESCPOS.effectDoubleHeight();
  ESCPOS.println("double height on");  
  ESCPOS.effectOff();
  
  ESCPOS.effectDoubleWidth();
  ESCPOS.println("double width on");  
  ESCPOS.effectOff();
  
  ESCPOS.effectDoubleHeight();
  ESCPOS.effectDoubleWidth();
  ESCPOS.println("double height + double width on");  
  ESCPOS.effectOff();
  
  ESCPOS.effectBold();  
  ESCPOS.println("bold on");  
  ESCPOS.effectOff();
  
  ESCPOS.effectUnderline();
  ESCPOS.println("underline on");  
  ESCPOS.effectOff();
  
  ESCPOS.reverseOn();
  ESCPOS.println("reverse on");  
  ESCPOS.println(" Hamburgefonts ");  
  ESCPOS.reverseOff();   
  ESCPOS.println("reverse off");      
  
  ESCPOS.justifyCenter();
  ESCPOS.barcodeHeight();
  ESCPOS.barcodeWidth();
  ESCPOS.barcodeTextPosition();
  ESCPOS.barcodeStartPrint();
  ESCPOS.print("09031976");
  ESCPOS.barcodeEndPrint();
  
  ESCPOS.justifyRight();
  ESCPOS.println("Hello World end");  
  
  ESCPOS.partialCut();  

}

void loop()                             // run over and over again
{
  printStatus = ESCPOS.getStatus();     // get the current status of the ESCPOS printer
  if (printStatus == 0) {               // if status is 0 then we are good
    Serial.println("printer online");   // debug that we are online
  } else {
    Serial.print("printer offline: ");  // debug that we are offline
    Serial.println(printStatus);        // debug the returned status code  
  } 
  digitalWrite(ledPin, HIGH)            // sets the LED on
  delay(1000);                          // waits for a second
  if (Serial.available() > 0) {
    ESCPOS.print(Serial.read());        // if string is sent, print string
  }
  digitalWrite(ledPin, LOW);            // sets the LED off
  delay(1000);                          // waits for a second
}
