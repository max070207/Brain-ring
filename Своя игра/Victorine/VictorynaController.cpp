#include "VictorynaController.h"
    Victorine_control::Victorine_control(int pin_b, int pin_l){
       _pin_button = pin_b;
       pinMode(_pin_button, INPUT_PULLUP);
       _pin_led = pin_l;
       pinMode(_pin_led, OUTPUT);
    }
    Victorine_control::Victorine_control(){
    }
    void Victorine_control::setButtonPin(int pin){
      _pin_button = pin;
      pinMode(_pin_button, INPUT_PULLUP);
    }
    void Victorine_control::setLedPin(int pin){
      _pin_led = pin;
      pinMode(_pin_led, OUTPUT);
    }
    bool Victorine_control::isControllerPressed(){
      return (!digitalRead(_pin_button));
    }
    void Victorine_control::ledOff(){
      digitalWrite(_pin_led, 0);
    }
    void Victorine_control::ledOn(){
      digitalWrite(_pin_led, 1);
    }
    bool Victorine_control::isHaveAnswer(){
      return _haveAnswer;
    }
    void Victorine_control::setAnswer(bool answer){
      _haveAnswer = answer;
    }
    void Victorine_control::setScore(int newScore){
      _score = newScore;
    }
    void Victorine_control::addScore(int increment){
      _score += increment;
    }
    int Victorine_control::getScore(){
      return _score;
    }