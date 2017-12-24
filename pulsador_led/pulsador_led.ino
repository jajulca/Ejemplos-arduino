const int inputPin = 2;
 
int value = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(13, OUTPUT);
}
 
void loop(){
  value = digitalRead(inputPin);  //lectura digital de pin
 
  //mandar mensaje a puerto serie en función del valor leido
  if (value == HIGH) {
    //  Serial.println("Encendido");
      digitalWrite(13,HIGH);
  }
  else {
  //    Serial.println("Apagado");
      digitalWrite(13,LOW);
  }
  //delay(1000);
}
