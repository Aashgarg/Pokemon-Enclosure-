
const int ashSwitch = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("This is a test");
  pinMode(ashSwitch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Merging testing again");
  ashRunning();
}

void ashRunning(){
  if (digitalRead(ashSwitch) == LOW){
    Serial.println("ash moves");
  }
  else{
    Serial.println("ash is still");
  }
  // pikachu gets off switch and servo with ash goes around
}

void nurseReveal(){
  //pikachu gets placed near entrance and nurse joy comes up
}

void pikachuStretcher(){
  //pikachu gets placed on stretcher and green leds light up to guide user to push stretcher
}

void nurseGoesYay(){
  //stretcher finishes it's round and nurse goes thumbs up and points to exit!
}

void panic(){
  //pikachu goes on exit switch and red leds light up, nurse goes oh no
}

void teamRocket(){
  //pikachu goes around to explosion and when goes on switch team rocket goes up on top with team rocket theme on piezo
}
