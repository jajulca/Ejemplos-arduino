

// Desde la aplicación del movil (bluetooth) se encienden  y
//apagan dos LEDs con las flechas UP/DOWN 
//Cuando pulsa la flecha UP envía una 'U' cuyo código
//ASCII es 85
//Cuando pulsa la flecha DOWN envía una 'D' cuyo código
//ASCII es 68

#define LED1 3
#define LED2 4
#define LED3 5


byte dato; 


//Etiquetas de identificación de los pines 
// labels for pins
//pines para controlar la direccion de giro 
// with 2 pins we control de spinning direction
const int motorA_Dir1 = 8;        
const int motorA_Dir2 = 9;
const int motorA_Velocidad = 10;  

//salida PWM para controlar la velocidad 
// PWM for speed

//Variables
int vPWM = 155;    //valor de la velocidad en PWM
 // PWM speed

void setup(){
  //configuracion de los pines //pins setup
  pinMode(motorA_Dir1, OUTPUT);
  pinMode(motorA_Dir2, OUTPUT);


    Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
}


void forward(){
    //Activamos el motor A en un sentido de giro
  //spinning direction 1 (high-low)
  digitalWrite(motorA_Dir1,HIGH);
  digitalWrite(motorA_Dir2,LOW); 
  analogWrite(motorA_Velocidad,vPWM);
}
   
void backw(){
  //Activamos el motor A en un sentido de giro
  //spinning direction 1 (high-low)
  digitalWrite(motorA_Dir1,LOW);
  digitalWrite(motorA_Dir2,HIGH); 
  analogWrite(motorA_Velocidad,vPWM);
}

void stop(){
 
  digitalWrite(motorA_Dir1,LOW);
  digitalWrite(motorA_Dir2,LOW);
}


void loop(){
  //forward();
 // delay(4000);              
  //stop();
 // delay(2000);
 // backw();
 // delay(4000); 
 // stop();
 // delay(2000);  


  if (Serial.available()) dato = Serial.read();   
  Serial.println(dato);

  if (dato == 85) { // UP 
    //digitalWrite(LED1, HIGH);
    //digitalWrite(LED2, LOW);

forward();

}
  if (dato == 68) { // DOWN
 //   digitalWrite(LED2, HIGH);
 //   digitalWrite(LED1, LOW);
    
    backw();
    }


    if (dato == 97) { // A
      digitalWrite (LED1, HIGH);
            digitalWrite (LED2, HIGH);
                  digitalWrite (LED3, HIGH);}
                  
                  
if (dato == 98) { // C
      digitalWrite (LED1, LOW);
            digitalWrite (LED2, LOW);
                  digitalWrite (LED3, LOW);}

    
if (dato == 67) { // Boton central
    //  digitalWrite (LED1, LOW);
  //          digitalWrite (LED2, LOW);
      //            digitalWrite (LED3, LOW);
   stop();     
      }


 
}


