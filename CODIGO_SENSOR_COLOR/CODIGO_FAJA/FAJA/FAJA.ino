#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

// Pines para el sensor de color
#define S0 2
#define S1 3
#define S2 4
#define S3 8
#define OUT 9

//Pines para el motor
#define IN1 7			// IN1 de L298N a pin digital 2
#define IN2 6			// IN2 de L298N a pin digital 3
#define ENA 5			// ENA de L298N a pin digital 5

//Pines para el servo
#define SERV 10

Servo ServoMotor;


LiquidCrystal_I2C lcd(0x27,16,2);

//Variable
int VELOCIDAD = 80;			// variable para almacenar valor de velocidad

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

int iniciar_proceso=0;

int i=0;

void setup() {
    lcd.init(); 
    lcd.backlight();
    lcd.clear();

    // Configuración de pines
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(OUT, INPUT);

    pinMode(IN1, OUTPUT);		
    pinMode(IN2, OUTPUT);	
    pinMode(ENA, OUTPUT);	

    ServoMotor.attach(SERV);
  
    // Configuración de la frecuencia de salida del TCS3200
    digitalWrite(S0, HIGH); // Configura la frecuencia en 20%
    digitalWrite(S1, LOW);
  
    // Inicia el monitor serial
    Serial.begin(9600);

    ServoMotor.write(100);
}

void loop() {

  if ((Serial.available() > 0) && (iniciar_proceso == 0)) {
    char command = Serial.read(); // Lee el comando recibido
    if (command == 'R') { // 'R' es un comando para comenzar a enviar datos
        startSendingData = true; // Activa el envío de datos
        contadorRojo = 0;
        contadorVerde = 0;
        contadorAzul = 0;
        contadorOtros = 0;

        iniciar_proceso=1;

        analogWrite(ENA, VELOCIDAD);				// el valor de velocidad y aplica a ENA
        digitalWrite(IN1, LOW);				// IN1 en 0
        digitalWrite(IN2, HIGH);				// IN2 en 1
    }
  }

  if ((Serial.available() > 0) && (iniciar_proceso == 1)) {
    char command = Serial.read(); // Lee el comando recibido
    if (command == 'L') { // 'MN' es para apagar el motor
        
        digitalWrite(ENA, LOW);	// ENA en 0 para deshabilitar motor
    }

    if (command == 'H') { // 'MN' es para apagar el motor
        
        analogWrite(ENA, VELOCIDAD);				// el valor de velocidad y aplica a ENA
        digitalWrite(IN1, LOW);				// IN1 en 0
        digitalWrite(IN2, HIGH);				// IN2 en 1
    }
  }

  if(startSendingData){

    // Lectura de valores de color
    redValue = readColor(LOW, LOW);    // Rojo
    greenValue = readColor(HIGH, HIGH); // Verde
    blueValue = readColor(LOW, HIGH);   // Azul

    // Determinar el color predominante
    String currentColor = "NEGRO"; // Por defecto es negro

    if ((redValue > 490 && redValue < 550) && (greenValue > 480 && greenValue < 540) && (blueValue > 380 && blueValue < 440)) {
        currentColor = "NEGRO";
    } else if ((redValue > 100 && redValue < 110) && (greenValue > 230 && greenValue < 240) && (blueValue > 190 && blueValue < 280)) {
        currentColor = "ROJO"; // ROJO // PLASTICO
    } else if ((redValue > 290 && redValue < 320) && (greenValue > 330 && greenValue < 360) && (blueValue > 275 && blueValue < 305)) {
        currentColor = "VERDE"; // VERDE // CARTON
    } else if ((redValue > 280 && redValue < 300) && (greenValue > 260 && greenValue < 275) && (blueValue > 170 && blueValue < 180)) {
        currentColor = "AZUL"; // AZUL // VIDRIO
    } else if ((redValue > 385 && redValue < 415) && (greenValue > 390 && greenValue < 420) && (blueValue > 315 && blueValue < 345)) {
        currentColor = "OTROS"; // OTROS // OTROS
    } 

    // Registrar el color solo si ha cambiado de negro a un color válido
    if (currentColor != "NEGRO" && previousColor == "NEGRO") {

        lcd.clear();
        // Incrementar el contador correspondiente al color detectado
        if (currentColor == "ROJO") {
            contadorRojo++;
            ServoMotor.write(0);
            lcd.setCursor(0,0);
            lcd.print("PLASTICO:     "+ String(contadorRojo));
        } else if (currentColor == "VERDE") {
            contadorVerde++;
            ServoMotor.write(60);
            lcd.setCursor(0,0);
            lcd.print("CARTON:       "+ String(contadorVerde));
        } else if (currentColor == "AZUL") {
            contadorAzul++;
            ServoMotor.write(120);
            lcd.setCursor(0,0);
            lcd.print("VIDRIO:       "+ String(contadorAzul));
        } else if (currentColor == "OTROS") {
            contadorOtros++;
            ServoMotor.write(180);
            lcd.setCursor(0,0);
            lcd.print("OTROS:        "+ String(contadorOtros));
        }
        lcd.display();

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

    delay(100); // Pequeña pausa para evitar lecturas continuas
  }
  
}

// Función para leer el color configurando los pines S2 y S3
int readColor(int S2state, int S3state) {
    digitalWrite(S2, S2state);
    digitalWrite(S3, S3state);
    delay(50); // Esperar un poco para estabilizar la señal
    return pulseIn(OUT, LOW); // Mide el tiempo en que el pin OUT está en LOW
}
