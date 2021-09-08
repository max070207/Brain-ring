//Slave sketch
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    int str = mySerial.read();
    if(str == 17){
      digitalWrite(13, 1);
      delay(50);
      digitalWrite(13, 0);
      delay(50);
    }
    if(str == 5){
      digitalWrite(13, 1);
      delay(50);
      digitalWrite(13, 0);
      delay(50);
      digitalWrite(13, 1);
      delay(50);
      digitalWrite(13, 0);
      delay(50);
      mySerial.println("Hello");
    }
  }
}
