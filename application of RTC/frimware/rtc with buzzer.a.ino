#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
int buzzer=13;

// LCD
// LCD D4 to Arduino 9
// LCD D5 to Arduino 10
// LCD D6 to Arduino 11
// LCD D7 to Arduino 12
// RS 4 to Arduino 7
// EN 6 to Arduino 8
// RH 5 to GND
// pin 3 to center pot
LiquidCrystal lcd(7,6,5,4,3,2);
//DS1307 RTC
//SDA pin to Arduino A4
// SCL pin to Arduino A5
RTC_DS1307 RTC;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();

  /*
  if (! RTC.isrunning()) {
   Serial.println("RTC is NOT running!");
   // following line sets the RTC to the date & time this sketch was compiled
     RTC.adjust(DateTime(10/23/2012, 10:30:00));
   }
   */

  lcd.begin(16,2); // 16x2 LCD
  if (! RTC.isrunning()) {
Serial.println("RTC is NOT running!");
// following line sets the RTC to the date & time this sketch was compiled
RTC.adjust(DateTime(__DATE__, __TIME__));
 // lcd.clear();
 // lcd.setCursor(0,0);
//  lcd.print("DATE"); // blank the display
//  lcd.setCursor(0,1);
//  lcd.print("TIME");
  
}
}

void loop() {
  DateTime now = RTC.now();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DATE:");
  lcd.setCursor(6,0);
//  if (now.day() < 10) {
//    lcd.print("0");
//  }


  lcd.print(now.day());
  lcd.print('/');
    if (now.month() < 10) {
    lcd.print("0");
  }
   lcd.print(now.month());
  lcd.print("/");

  lcd.print(now.year());
   lcd.setCursor(0,1);
  lcd.print("TIME:");
  lcd.setCursor(7,1);
  if (now.hour() < 10) {
    lcd.print("0");
  }
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) {
    lcd.print("0");
  }

  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) {
    lcd.print("0");
  }

  lcd.print(now.second());
  delay(1000);
  //Morning alaram at 8:15am
   if (now.hour()==8 && now.minute()==14&& now.second()<=34 )
    {
      digitalWrite(buzzer,HIGH);
    }
    //Afternoon Break at 1:00pm
    else if (now.hour()==12 && now.minute()==11 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }
    //Afternoon Break reminder at 1:55pm 
    else if (now.hour()==13 && now.minute()==54 && now.second()<=59 )
    {
      digitalWrite(buzzer,HIGH);
    }    
    //Afternoon Break over at 2:00pm 
    else if (now.hour()==14 && now.minute()==00 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }    
    //Evening off and over time on at 5:00pm 
    else if (now.hour()==18 && now.minute()==57 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }
    //Overtime off time at 8:00pm 
    else if (now.hour()==20 && now.minute()==58 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }
    
    
      else 
   {
     digitalWrite(buzzer,LOW);
   }   
    }
