// Sensor de Color
//
//    Arduino   TCS230 SENSOR COLOR
//      8         OUT
//      7         S3
//      6         S2
//      5         S1
//      4         S0
//      5V        VCC
//      GND       GND
//

#define S0 2
#define S1 3
#define S2 4
#define S3 8
#define sensorSalida 9
int Rojo_Frec = 0;
int Verde_Frec = 0;
int Azul_Frec = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorSalida, INPUT);
  
                           // Configura la escala de Frecuencia en 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
                          // Configura el filtor ROJO para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  delay(100);
  Rojo_Frec= pulseIn(sensorSalida, LOW);
  Serial.print(" R= "); Serial.print(Rojo_Frec);
  delay(100);
                            // Configura el filtor VERDE para tomar lectura
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  delay(100);
  Verde_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" V= "); Serial.print(Verde_Frec);
  delay(100);
                           // Configura el filtor AZUL para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  delay(100);
  Azul_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" A= "); Serial.print(Azul_Frec);
  delay(100);

                  //Valores obtenidos en la calibracion del sensor, son propios de cada usuario 
                  
 if (Rojo_Frec < 65 && Verde_Frec > 175 && Azul_Frec >125)  Serial.print(" . *** PELOTA ROJA **");
 if (Rojo_Frec > 130 && Verde_Frec >110 && Azul_Frec < 80)  Serial.print(" . *** PELOTA AZUL **");
 if (Rojo_Frec < 65 && Verde_Frec < 50 && Azul_Frec >40)  Serial.print(" . *** PELOTA VERDE **");
 if(Rojo_Frec > 95 && Verde_Frec > 90 && Azul_Frec >90) Serial.print(" . *** PELOTA NEGRO **");
 


 Serial.println("*");
 delay(200);
}
