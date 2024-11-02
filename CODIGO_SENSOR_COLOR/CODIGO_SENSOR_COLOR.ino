// Pines del Arduino conectados al TCS3200
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8

/*//VARIABLES PARA EL MOTOR
int IN1 = 2;			// IN1 de L298N a pin digital 2
int IN2 = 3;			// IN2 de L298N a pin digital 3
int ENA = 5;			// ENA de L298N a pin digital 5*/

// Variables para almacenar los valores de cada color
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

// Contadores de detección acumulados para cada color
int contadorRojo = 0;
int contadorVerde = 0;
int contadorAzul = 0;
int contadorOtros = 0;

bool startSendingData = false; // Bandera para iniciar el envío de datos

// Estado de color anterior
String previousColor = "NEGRO";

void setup() {
    // Configuración de pines
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(OUT, INPUT);
  
    // Configuración de la frecuencia de salida del TCS3200
    digitalWrite(S0, HIGH); // Configura la frecuencia en 20%
    digitalWrite(S1, LOW);
  
    // Inicia el monitor serial
    Serial.begin(9600);
}

void loop() {


  if (Serial.available() > 0) {
        char command = Serial.read(); // Lee el comando recibido
        if (command == 'R') { // 'S' es un comando para comenzar a enviar datos
            startSendingData = true; // Activa el envío de datos
            contadorRojo = 0;
            contadorVerde = 0;
            contadorAzul = 0;
            contadorOtros = 0;
        }
    }

    if(startSendingData){

      // Lectura de valores de color
      redValue = readColor(LOW, LOW);    // Rojo
      greenValue = readColor(HIGH, HIGH); // Verde
      blueValue = readColor(LOW, HIGH);   // Azul

      // Determinar el color predominante
      String currentColor = "NEGRO"; // Por defecto es negro

      if (redValue > 95 && greenValue > 90 && blueValue > 90) {
          currentColor = "NEGRO";
      }else if (redValue < 65 && greenValue > 175 && blueValue >125) {
          currentColor = "ROJO";
      } else if (redValue > 130 && greenValue >110 && blueValue < 80) {
          currentColor = "AZUL";
      } else if (redValue < 65 && greenValue < 50 && blueValue >40 ) {
          currentColor = "VERDE";
      } if (redValue < 50 && greenValue < 50 && blueValue <50 ) {
          currentColor = "OTROS";
      } 

      // Registrar el color solo si ha cambiado de negro a un color válido
      if (currentColor != "NEGRO" && previousColor == "NEGRO") {
          // Incrementar el contador correspondiente al color detectado
          if (currentColor == "ROJO") {
              contadorRojo++;
          } else if (currentColor == "VERDE") {
              contadorVerde++;
          } else if (currentColor == "AZUL") {
              contadorAzul++;
          } else if (currentColor == "OTROS") {
              contadorOtros++;
          }

          // Imprimir los valores acumulados en el formato solicitado
          Serial.print(contadorRojo);
          Serial.print(",");
          Serial.print(contadorVerde);
          Serial.print(",");
          Serial.print(contadorAzul);
          Serial.print(",");
          Serial.println(contadorOtros);
      }

      // Actualizar el color anterior
      previousColor = currentColor;

      delay(250); // Pequeña pausa para evitar lecturas continuas
  }
}

// Función para leer el color configurando los pines S2 y S3
int readColor(int S2state, int S3state) {
    digitalWrite(S2, S2state);
    digitalWrite(S3, S3state);
    delay(50); // Esperar un poco para estabilizar la señal
    return pulseIn(OUT, LOW); // Mide el tiempo en que el pin OUT está en LOW
}
