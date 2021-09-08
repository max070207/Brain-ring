#include "VictorynaController.h"
#define PIN_BUZZER 3
#define PIN_PLUS A0
#define PIN_MINUS A1
int Nround = 0;
const int N = 2;
const int pin_players = 4;
Victorine_control players[N];

void setup() {
  for(int i = 0; i < N; i++){
    players[i].setButtonPin(pin_players + i * 2);
    players[i].setLedPin(pin_players + i * 2 + 1);
  }
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_PLUS, INPUT_PULLUP);
  pinMode(PIN_MINUS, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println("Welcome to the new game!");
}

void loop() {
  bool flagOut = false;
  while(!flagOut){
    for(int i = 0; i < N; i++){
      players[i].setAnswer(players[i].isControllerPressed());
      if(players[i].isHaveAnswer()){
        players[i].ledOn();
        AnswerBip();
        flagOut = true;
        break;
      }
    }
  }
  flagOut = false;
  while(!flagOut){
    if(digitalRead(PIN_PLUS) && digitalRead(PIN_MINUS)){
      flagOut = true;
      for(int i = 0; i < N; i++){
        if(!players[i].isControllerPressed())
          flagOut = true;
        else
          flagOut = false;
        }
      }
    }
  Serial.println("Admin control");
  flagOut = false;
  while(!flagOut){
    if(!digitalRead(PIN_PLUS)){
      for(int i = 0; i < N; i++){
        if(players[i].isHaveAnswer() == true){
          players[i].addScore(1);
          players[i].setAnswer(false);
          players[i].ledOff();
          RightBip();
          flagOut = true;
          break;
        }
      }
    }
    if(!digitalRead(PIN_MINUS)){
      for(int i = 0; i < N; i++){
        if(players[i].isHaveAnswer() == true){
          players[i].addScore(-1);
          players[i].setAnswer(false);
          players[i].ledOff();\
          NotRightBip();
          flagOut = true;
          break;
        }
      }
    }
  }
  show_score();
  Nround++;
  flagOut = false;
  while(!flagOut){
    if(digitalRead(PIN_PLUS) && digitalRead(PIN_MINUS)){
      flagOut = true;
      for(int i = 0; i < N; i++){
        if(!players[i].isControllerPressed())
          flagOut = true;
        else
          flagOut = false;
        }
      }
    }
  delay(5000);
  Serial.println("NEW ROUND");
  NewRoundBip();
}

void show_score(){
  Serial.print("***ROUND ");
  Serial.print(Nround);
  Serial.println("***");
  for(int i = 0; i < N; i++){
    Serial.print("Player ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(players[i].getScore());
  }
}

void AnswerBip(){
  tone(PIN_BUZZER, 3000, 500);
  delay(50);
  tone(PIN_BUZZER, 3000, 500);
}

void NotRightBip(){
  tone(PIN_BUZZER, 1500, 500);
  delay(500);
  tone(PIN_BUZZER, 1000, 500);
}

void RightBip(){
  tone(PIN_BUZZER, 4500, 500);
  delay(500);
  tone(PIN_BUZZER, 5000, 500);
}

void NewRoundBip(){
  tone(PIN_BUZZER, 4000, 500);
  delay(500);
  tone(PIN_BUZZER, 3000, 500);
  delay(500);
  tone(PIN_BUZZER, 3000, 500);
}
