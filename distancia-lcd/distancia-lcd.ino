 
#include <NewPing.h>
 




/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200

#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //


int pin=2;
DHT11 dht11(pin);
 
/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);

       // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
}
 
void loop() {
  // Esperar 1 segundo entre mediciones
  delay(1000);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  // Imprimir la distancia medida a la consola serial
  Serial.print("Distancia: ");
  // Calcular la distancia con base en una constante
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");


// datos al LCD


             lcd.setCursor(0,0);
  lcd.print("Distancia:");

              lcd.setCursor(5,1);
  lcd.print(uS / US_ROUNDTRIP_CM);
  lcd.print(" cm    ");

// escribe eu en la posicion 15 de la primera linea
 // lcd.setCursor(14,0);
 // lcd.print("cm   ");

  
  
}
