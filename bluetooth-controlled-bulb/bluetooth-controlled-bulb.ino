//Project Descriptions

/* Connections: 
Bluetooth module TX to D10
Bluetooth module RX to D11
Bluetooth module Vcc to 5V
Bluetooth module GND to GND
*/

#include <SoftwareSerial.h>

softwareSerial BT(10, 11);

#define SW 2 //define pin 2 as control pin

void setup() {
  // put your setup code here, to run once:
  pinMode(SW, OUTPUT); 
  BT.begin(9600); //Data rate for the softwareSerial port
  BT.println("Hello from Arduino"); //Send test message to other device
}

char a; //stores incoming character from other device

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available()) { //If text arrived in from BT serial
    a = (BT.read());
    
    if (a == '1') {
      digitalWrite(SW, LOW); //Turn Light ON
      BT.println("Light on");
    }
    
    if (a == '2') {
      digitalWrite(SW, HIGH); //Turn OFF
      BT.println("Light off");
    }
    
    if (a == '?'){
      BT.println("Send '1' to turn Light ON");
      BT.println("Send '2' to turn Light OFF");
    }
    
  }
  
}
