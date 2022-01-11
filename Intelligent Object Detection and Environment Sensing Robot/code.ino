/*
Arduino Based Music Player

 This example shows how to play three songs from SD card by pressing a push button

 The circuit:
 * Push Button on pin 2 and 3
 * Audio Out - pin 9
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 

 created  25 Jun 2017
 by Aswinth Raj

 This example code was created for CircuitDigest.com

 */
 
#include "SD.h" //Lib to read SD card
#include "TMRpcm.h" //Lib to play auido
#include "SPI.h" //SPI lib for SD card

#define SD_ChipSelectPin 4 //Chip select is pin number 4 or 53
TMRpcm music; //Lib object is named "music"

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 3;
int ledPin2 = 2;     
int room1f = 5;
int sensorValue = 0;


void setup(){

  
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(room1f, INPUT);

music.speakerPin = 9; //Auido out on pin 9
Serial.begin(9600); //Serial Com for debugging 
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}
else
{
  Serial.println("SD is ok");
}
  //pinMode(SD_ChipSelectPin, OUTPUT);
music.setVolume(6);    //   0 to 7. Set volume level
music.quality(1);        //  Set 1 for 2x oversampling Set 0 for normal    1 dela sound hoyna 
music.volume(0);        //   1(up) or 0(down) to control volume
//music.play("filename",30); plays a file starting at 30 seconds into the track    
//music.play("test.wav");
}

void loop()
{ 
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  Serial.print("flm   ");
  Serial.println(analogRead(A1));
if(sensorValue <= 300)
  {
     digitalWrite(ledPin, HIGH);
     digitalWrite(ledPin2, HIGH);
  }

  else
  {
     digitalWrite(ledPin, LOW);
     digitalWrite(ledPin2, LOW);
  }
  

  if(analogRead(A1) <= 300)
  {
   Serial.println("fireroom");
    music.play("fire.wav"); //Play song 1 from 10th second 
    delay(5000);
  }
  
  if(digitalRead(room1f) == HIGH)
  {
    Serial.println("fireroom");
    music.play("Human.wav"); //Play song 1 from 10th second 
    delay(5000);
  }

}
