/*
  // Place a description here....
*/

#define _LED 13     // led is attached at digital pin 13
#define _MOTION 8   // motion sensor is attached at digital pin 8
#define _BUZZER 9   // buzzer alarm is attached at digital pin 9

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  
  pinMode(_LED, OUTPUT);
  pinMode(_MOTION, INPUT);
  pinMode(_BUZZER, OUTPUT);

  Serial.println("Arduino initialized...");
}

void activateAlarm(int times) {
  int delayTime = 1000;
  for(int t=0; t<times; t++) {
    digitalWrite(_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    tone(_BUZZER, 1000);
    delay(delayTime);                 // wait
    digitalWrite(_LED, LOW);    // turn the LED off by making the voltage LOW
    noTone(_BUZZER);
    delay(delayTime);
  }

  //tone(pin, frequency, duration)
  
}

void loop() {
  // Read the value of the motion sensor. If everything went OK the value should be
  // 1 (in case of a motion) or 0 (meaning that no motion was detected).
  int motionValue = digitalRead(8);

  if(motionValue == 1) {
      Serial.println("Arduino detected some motion in the area! Activating alarm 5 times...");
      activateAlarm(5);
  }else {
      Serial.println("The quiter you become the more you are able to hear - RAM DASS");
  }
}
