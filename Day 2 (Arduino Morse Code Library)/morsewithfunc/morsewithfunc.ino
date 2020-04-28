#include <Morse.h>

Morse morse(13);
Morse morse2(12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run reupeatedly:
  for(int i=0;i<1;i++){
    morse.dot();
  }
  for(int i=0;i<2;i++){
    morse.dash();
  }
  for(int i=0;i<3;i++){
    morse.dot();
  }
  Serial.println(morse.show());
  Serial.println(morse2.show());
  
  delay(3000);
}
