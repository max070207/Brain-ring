#include <Arduino.h>
class Victorine_control{
  public:
    Victorine_control(int pin_b, int pin_l);
    Victorine_control();
    void setButtonPin(int pin);
    void setLedPin(int pin);
    bool isControllerPressed();
    void ledOff();
    void ledOn();
    bool isHaveAnswer();
    void setAnswer(bool answer);
    void setScore(int newScore);
    void addScore(int increment);
    int getScore();
  private:
    int _pin_button = 2;
    int _pin_led = 2;
    int _score = 0;
    bool _haveAnswer = false;
};