#include <Arduino.h>

#define s1 5 //D1
#define s2 4 //D2
#define tr 0 //D3 -> TRIGGER
#define led 2 //D4 -> CHECK LED
#define stop 14
int mode = 0;
int i = 0;
void setup() {
  Serial.begin(115200);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(tr, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(stop, INPUT_PULLUP);
}

void loop() {
  
  if(digitalRead(s1) == LOW && digitalRead(s2) == HIGH){
    //Serial.println("SAFE");
    mode = 3;
  }
  if(digitalRead(s1) == HIGH && digitalRead(s2) == LOW){
    //Serial.println("AUTO");
    mode = 0;
  }
  if(digitalRead(s1) == LOW && digitalRead(s2) == LOW){
    //Serial.println("SEMI");
    mode = 1;
  }
  digitalWrite(led, HIGH);
  //while(&& digitalRead(tr) == LOW){
    while(mode == 0 && digitalRead(tr) == LOW)
    {
      Serial.println("SAFE");
      digitalWrite(led, LOW);
    }   

    while(mode == 1 && digitalRead(tr) == LOW)
    {
      Serial.println("SEMI");
      digitalWrite(led, LOW);
      delay(500);
      digitalWrite(led, HIGH);
      delay(500);
    }
        
    while(mode == 3 && digitalRead(tr) == LOW)
    {
      Serial.println("AUTO");
      digitalWrite(led, LOW);
      
    }
    digitalWrite(led, HIGH);
//}
  
  while(digitalRead(stop) == LOW){
      digitalWrite(led, LOW);
      delay(100);
      digitalWrite(led, HIGH);
      delay(100);
  }

  
  
}