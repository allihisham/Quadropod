#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Baud rate
  pwm.begin();
  pwm.setPWMFreq(60); //Servo motors work at 60hz refresh rate
  Dabble.begin("ESP32ServoController");
  delay(100);

}

void loop() {

  Dabble.processInput();
  if (GamePad.isUpPressed()) {
        forward();
        delay(100);    
  }else if (GamePad.isDownPressed()) {
        backward();
        delay(100);
  }else if(GamePad.isRightPressed()){
        right();
        delay(100);
  }else if(GamePad.isLeftPressed()){
        left();
        delay(100);
  }else if(GamePad.isCirclePressed()){
        dance();
        dance();
        dance();
        delay(100);
  }else if(GamePad.isSquarePressed()){
        hi();
        delay(100);
  }else if(GamePad.isTrianglePressed()){
        slep();
        delay(100);
  }else if(GamePad.isCrossPressed()){
        wake();
        delay(100);
  }
 






}
void setangle(int servonum , int angle)
{

  int pulse = map(angle , 0, 180, 150, 600);

  pwm.setPWM(servonum, 0, pulse);
}
void forward() {



    setangle(12, 40); //leg up
    setangle(3, 140); //leg up
    delay(100);
    setangle(13, 90); // move leg                               //leg2,3
    setangle(2, 0); // move leg
    delay(100);
    setangle(12, 0);// leg back on ground 
    setangle(3, 180);// leg back on ground
    delay(100);

    setangle(0, 40);
    setangle(15, 50);
    delay(100);
    setangle(1, 180);    //leg1,4
    setangle(14, 60);
    delay(100);
    setangle(0, 0);
    setangle(15, 90);
    delay(100);

    
    
    setangle(13, 45);     //reset original position
    setangle(2, 45);     //reset original position
    setangle(1, 135);    //reset original position
    setangle(14, 115);   //reset original position
    delay(100);
}
void backward() {

  
  

 setangle(12, 40);
  setangle(3, 140);
  
                         //leg2,3
  setangle(2, 90);
  delay(100);
  setangle(13, 0);
  delay(100);
  
  setangle(3, 180);
  delay(100);
  setangle(12, 0);
  delay(100);

  setangle(0, 40);
  delay(100);
  setangle(15, 50);
  delay(100);
  setangle(1, 90);    //leg1,4
  setangle(14, 180);
  delay(100);
  setangle(0, 0);
  setangle(15, 90);
  delay(100);


    setangle(13, 45);
     setangle(2, 45);
   setangle(1, 135);
    setangle(14, 115);
    delay(100);

}
void hi(){
  setangle(2,25);
  delay(200);
  setangle(0,180);
  delay(100);
  setangle(1,180);
  delay(100);
  setangle(1,90);
  delay(100);
   setangle(1,180);
  delay(100);
  setangle(1,90);
  delay(100);
   setangle(1,180);
  delay(100);
  setangle(1,90);
  delay(100);
  setangle(0,0);
  setangle(1,135);

}
void slep(){
    
  setangle(12, 90);
  setangle(0, 90);
  delay(100);
  setangle(3, 90);
  setangle(15, 0);
  delay(100);
}
void wake(){
  setangle(12, 0);
  setangle(0, 0);
  delay(100);
  setangle(3, 180);
  setangle(15, 90);
}
void dance() {


  setangle(12, 0);
  setangle(0, 0);
  delay(100);
  setangle(3, 180);
  setangle(15, 90);
  delay(100);
  setangle(0, 65);
  setangle(12, 65);
  delay(100);
  setangle(3, 115);
  setangle(15, 25);
  delay(100);
  
   // Dance move 1
  setangle(12, 45);
  setangle(3, 135);
  setangle(13, 90);
  setangle(2, 90);
  delay(100);

  // Dance move 2
  setangle(0, 20);
  setangle(15, 70);
  setangle(1, 180);
  setangle(14, 60);
  delay(100);

  // Dance move 3
  setangle(12, 0);
  setangle(3, 180);
  setangle(13, 45);
  setangle(2, 45);
  delay(100);

  // Dance move 4
  setangle(0, 45);
  setangle(15, 135);
  setangle(1, 90);
  setangle(14, 90);
  delay(100);

  // Reset to original position
  setangle(12, 20);
  setangle(3, 160);
  setangle(13, 90);
  setangle(2, 0);
  setangle(0, 20);
  setangle(15, 70);
  setangle(1, 180);
  setangle(14, 60);
  delay(500);

}

void right() {


  setangle(12,4);
  setangle(3,140);
  delay(100);
  setangle(13,90);
  setangle(2,0);           //leg 3,2
  delay(100);
  setangle(12,0);
  setangle(3,180);
  delay(100);

  setangle(0,40);
  setangle(15,50);
  delay(100);             //leg 1,4
  setangle(1,90);
  setangle(14,180);
  delay(100);
  setangle(0,0);
  setangle(15,90);
  delay(100);


  

  /*setangle(12, 40);
  delay(100);
  setangle(13, 90);
  delay(100);
  setangle(12, 0);
  delay(100);

  setangle(0, 40);
  delay(100);
  setangle(1, 90);
  delay(100);
  setangle(0, 0);
  delay(100);

  setangle(15, 50);
  delay(100);
  setangle(14, 180);
  delay(100);
  setangle(15, 90);
  delay(100);

  setangle(3, 140);
  delay(100);
  setangle(2, 0);
  delay(100);
  setangle(3, 180);
  delay(500);*/
    
    
  setangle(2, 45);
  setangle(14, 115);
  setangle(1, 135);
  setangle(13, 45);
  delay(100);
}
void left(){
  setangle(3,140);
  setangle(12,40);
  delay(100);
  setangle(2,90);
  setangle(13,0);
  delay(100);
  setangle(3,180);
  setangle(12,0);
  delay(100);


  setangle(0,40);
  setangle(15,50);
  delay(100);
  setangle(1,180);
  setangle(14,60);
  delay(100);
  setangle(0,0);
  setangle(15 ,90);
  delay(100);



  setangle(2, 45);
  setangle(14, 115);
  setangle(1, 135);
  setangle(13, 45);
  delay(100);
}
