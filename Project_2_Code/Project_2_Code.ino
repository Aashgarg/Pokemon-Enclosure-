#include <Servo.h>

const int ashSwitch = 7;
const int trSwitch = 6;
const int nurseSwitch = 5;
const int stretchSwitch = 4;
const int nurseEmojiSwitch = 3;
int buttonState = 0;
int previousButtonState = 1;
Servo ashServo;
Servo nurseServo;
Servo nurseEmojiServo
Servo trServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(ashSwitch, INPUT);
  pinMode(trSwitch, INPUT);
  pinMode(nurseSwitch, INPUT);
  pinMode(stetchSwitch, INPUT);
  pinMode(nurseEmojiSwitch, INPUT);
  ashServo.attach(9);
  trServo.attach(10);
  nurseServo.attach(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ashRunning();
  teamRocket();
  nurseReveal();
}

void ashRunning(){
  buttonState = digitalRead(ashSwitch);
  if (buttonState == LOW){
    ashServo.write(60);
  }
  else{
    ashServo.write(90);
  }
  // pikachu gets off switch and servo with ash goes around
}

void nurseReveal(){
  buttonState = digitalRead(nurseSwitch);
  if (buttonState == HIGH){
    nurseServo.write(90);
  }
  else{
    nurseServo.write(0);
  }
  //Ash gets placed near entrance and nurse joy comes up
}

void pikachuStretcher(){
  buttonState = digitalRead (stretcherSwitch);
   if (buttonState == HIGH){
    //lights go green
   }
  //pikachu gets placed on stretcher and green leds light up to guide user to push stretcher
}

void nurseGoesYay(){
  //stretcher finishes it's round and nurse goes thumbs up and points to exit!
}

void panic(){
  //pikachu goes on exit switch and red leds light up, nurse goes oh no
}

void teamRocket(){
  buttonState = digitalRead(trSwitch);
  
  if (buttonState == HIGH){
    trServo.write(90);
  }
  else{
    delay(200);
    Serial.print("yo");
    trServo.write(0);
  }
  //pikachu goes around to explosion and when goes on switch team rocket goes up on top with team rocket theme on piezo
}
