// Programa realizado por Eufrasio Cabrera para controlar un sensor de humedad y temperatura DHT11 y pantalla LCD

#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //


int pin=2;
DHT11 dht11(pin);

void setup()
   {
       Serial.begin(9600);

       // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
   }

void loop()
   {
       int err;
       float temp, hum;
       if((err = dht11.read(hum, temp)) == 0)    // Si devuelve 0 es que ha leido bien
          {
          Serial.print("Temperatura: ");
             Serial.print(temp);
             Serial.print(" Humedad: ");
             Serial.print(hum);
             Serial.println();

             lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp,1);//1 decimal
  lcd.print(" C  ");

// escroibe eu en la posicion 15 de la primera linea
  lcd.setCursor(14,0);
  lcd.print("eu");

  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.print(hum,1); //1 decimal
  lcd.print(" % ");
          }
       else
          {
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(err);
             Serial.println();




// Cursor en la primera posición de la primera fila
  
  // Cursor en la 11° posición de la primera fila
  //lcd.setCursor(10,0);
  //lcd.print("V:");
 // lcd.print(sen2,1);//1 decimal
 // lcd.print("V  ");
  // Cursor en la primera posición de la 2° fila
  
  //lcd.print("337C  "); // "337" -> "°"
  // Cursor en la 11° posición de la 2° fila
  //lcd.setCursor(10,1);
  //lcd.print("t:");
  //lcd.print(tiempo);
  //lcd.print(" s  ");
  
  //delay(200);


             
          }
       delay(5000);            //Recordad que solo lee una vez por segundo
   }
