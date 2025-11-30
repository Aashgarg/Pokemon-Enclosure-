#include <Servo.h>

const int ashSwitch = 7;
const int trSwitch = 6;
const int nurseSwitch = 5;
const int stretchSwitch = 4;
const int nurseEmojiSwitch = 3;
const int greenLightOne = 13;
const int sensor = A0;
const int threshold = 10;

const int redLight = 2;
int buttonState = 0;
int previousButtonState = 1;
int sensorval;


Servo ashServo;
Servo nurseServo;
Servo nurseEmojiServo;
Servo trServo;

bool stateOne = true;
bool stateTwo = false;
bool stateThree = false;
bool stateFour = false;
bool stateFive = false;
bool stateSix = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ashSwitch, INPUT);
  pinMode(trSwitch, INPUT);
  pinMode(nurseSwitch, INPUT);
  pinMode(stretchSwitch, INPUT);
  pinMode(nurseEmojiSwitch, INPUT);
  pinMode(greenLightOne, OUTPUT);
  //pinMode(sensor, INPUT);
  pinMode(redLight, OUTPUT);
  ashServo.attach(8);
  trServo.attach(10);
  nurseServo.attach(11);
  nurseEmojiServo.attach(12);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (stateOne = true){
    ashRunning();
  }
  if (stateTwo = true){
    nurseReveal();
  }
  if (stateThree = true){
    pikachuStretcher();
  }
  if (stateFour = true){
    exit();
  }
  if (stateFive = true){
    teamRocket();
  }
  
}

void ashRunning(){
  buttonState = digitalRead(ashSwitch);

  sensorval = analogRead(sensor);
  Serial.println(sensorval);
  if (buttonState == LOW){
    if (sensorval > 20){
      Serial.println("Hi");
      ashServo.write(98); //have to push since this was previously commented out
    }
    else{
      Serial.println("stop");
      ashServo.write(90);
      stateOne = false;
      stateTwo = true;
    }
    
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
    ashServo.write(90);
    stateThree = true;
  }
  else{
    nurseServo.write(0);
    //ashServo.write(90);
  }
  //Ash gets placed near entrance and nurse joy comes up
}

void pikachuStretcher(){
  buttonState = digitalRead(stretchSwitch);
   if (buttonState == HIGH){
    digitalWrite(greenLightOne, HIGH);
    ashServo.write(90);
    stateFour = true;
   }
   else{
    digitalWrite(greenLightOne, LOW);
    //ashServo.write(90);
   }
  //pikachu gets placed on stretcher and green leds light up to guide user to push stretcher
}

void exit(){
  buttonState = digitalRead(nurseEmojiSwitch);

  if (buttonState == HIGH){
    Serial.println("this");
    nurseEmojiServo.write(100);
    ashServo.write(90);
    stateFive = true;
  }
  else{
    nurseEmojiServo.write(90);
    //ashServo.write(90);
  }
  
  //stretcher finishes it's round and nurse goes thumbs up and points to exit!
}

void teamRocket(){
  buttonState = digitalRead(trSwitch);
  
  if (buttonState == HIGH){
    trServo.write(180);
    ashServo.write(90);
  }
  else{
    //delay(200);
    trServo.write(0);
    //ashServo.write(90);
  }
  //pikachu goes around to explosion and when goes on switch team rocket goes up on top with team rocket theme on piezo
}
