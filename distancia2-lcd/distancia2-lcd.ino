
// Indica la distancia con dos decimales
// No utiliza ninguna libreria

long tiempo;
int disparador = 12;   // triger
int entrada = 11;      // echo
float distancia;

#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //


int pin=2;
DHT11 dht11(pin);
 


void setup()
{
  pinMode(disparador, OUTPUT);
  pinMode(entrada, INPUT);
  
  Serial.begin(9600);

       // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
}


void loop()
{
  // lanzamos un pequeño pulso para activar el sensor
  digitalWrite(disparador, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador, LOW);
  
  // medimos el pulso de respuesta
  tiempo = (pulseIn(entrada, HIGH)/2); // dividido por 2 por que es el 
                                       // tiempo que el sonido tarda
                                       // en ir y en volver
  // ahora calcularemos la distancia en cm
  // sabiendo que el espacio es igual a la velocidad por el tiempo
  // y que la velocidad del sonido es de 343m/s y que el tiempo lo 
  // tenemos en millonesimas de segundo
  distancia = float(tiempo * 0.0343);
  
  // y lo mostramos por el puerto serie una vez por segundo

  Serial.print ("Distancia : ");
  Serial.println(distancia);
  delay(2000);


// datos al LCD


             lcd.setCursor(0,0);

      
  lcd.print("Distancia:");
  
 

// escribe eu en la posicion 15 de la primera linea
 // lcd.setCursor(14,0);
 // lcd.print("cm   ");

lcd.setCursor(0,1);


lcd.print(distancia);
 lcd.print(" cm    ");
  
}
