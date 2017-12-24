void setup() {
  Serial.begin(9600);
  

}

void loop() {
  //lee la entrada analogica A0
int sensorValue = analogRead(A0);

Serial.println(sensorValue);
delay (1000);
}
