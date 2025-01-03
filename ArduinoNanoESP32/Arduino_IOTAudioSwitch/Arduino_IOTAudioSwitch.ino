/*
Author: Hiro Fujii
Date: 04Jul24
*/

#include "arduino_secrets.h"
#include "thingProperties.h"

//A, B, C Pins for Multiplexor
//Make These Whatever You Want According To Your Schematic
const int A = 2;
const int B = 3;
const int C = 4;
//C Doesn't Have Mute Functionality Currently Bc Of Arduino Cloud Limitations

//Setup
void setup(){
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  //Preps Output Pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  
  //Updates to Previously Selected Channel On Boot
  onChannelChange();
}

//Loop
void loop(){
  ArduinoCloud.update();
}

//When Cloud Variable channel Changes
//Handles Actual Switching of Channels
void onChannelChange(){ 
  if(channel == 1){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
  }else if(channel == 2){
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
  }else if(channel == 3){
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
  }else if(channel == 4){
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
  }
}

//The Following Functions Handle How Google Home Interacts With Changing Channels

//When Cloud Variable audioChannel1 Changes
void onAudioChannel1Change()  {
  if(audioChannel1 == true){
    channel = 1;
    audioChannel2 = false;
    audioChannel3 = false;
    audioChannel4 = false;
    onChannelChange();
  }
}

//When Cloud Variable audioChannel2 Changes
void onAudioChannel2Change()  {
  if(audioChannel2 == true){
      channel = 2;
      audioChannel1 = false;
      audioChannel3 = false;
      audioChannel4 = false;
      onChannelChange();
  }
}

//When Cloud Variable audioChannel3 Changes
void onAudioChannel3Change()  {
  if(audioChannel3 == true){
    channel = 3;
    audioChannel2 = false;
    audioChannel1 = false;
    audioChannel4 = false;
    onChannelChange();
  }
}

//When Cloud Variable audioChannel4 Changes
void onAudioChannel4Change()  {
  if(audioChannel4 == true){
    channel = 4;
    audioChannel2 = false;
    audioChannel3 = false;
    audioChannel1 = false;
    onChannelChange();
  }
}



