int redLed = 12;
int greenLed = 11;
int buzzer = 10;
const int smokeA0 = A5;
// Your threshold value
int sensorThres = 250;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(38400);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

 // Serial.print("Pin A0: ");
 // Serial.println(analogSensor); 
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    Serial.println(analogSensor);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
    delay(1000);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
