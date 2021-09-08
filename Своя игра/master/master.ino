(//Master sketch
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(19200);
  Serial.begin(115200);
}

void loop() {
  static unsigned long t = 0;
  if(t + 2000 < millis()){
    t = millis();
    mySerial.write(5);
    Serial.println(t);
  }
  if(mySerial.available()){
    Serial.print(char(mySerial.read()));
  }
}
