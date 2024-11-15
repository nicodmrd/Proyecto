#include <LiquidCrystal_I2C.h>

// Definimos los pines para el LED RGB
#define LED_BLUE 5
#define LED_GREEN 6
#define LED_RED 7

// Definimos los pines del sensor ultrasónico
#define TRIGGER_PIN 36
#define ECHO_PIN 35

// Definimos el pin del sensor PIR
#define PIR_PIN 4

// Inicializamos la pantalla LCD en la dirección I2C especificada, con 16 columnas y 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); // Asegúrate de que la dirección coincide con tu modelo

// Variable para almacenar el estado del sistema
bool sistemaActivo = false;

void setup() {
  Serial.begin(115200); // Iniciamos la comunicación serial para la interacción con el usuario
  
  // Configuramos la pantalla LCD
  lcd.begin();
  lcd.backlight(); // Activamos la luz de fondo del LCD
  lcd.setCursor(0, 0); // Posicionamos el cursor al inicio
  lcd.print("Espera"); // Mostramos el mensaje inicial de espera

  // Configuración de pines de entrada y salida
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  Serial.println("Ingrese 'ON' para iniciar el sistema.");
}

void loop() {
  // Espera de comando de inicio mientras el sistema está bloqueado
  if (!sistemaActivo) {
    if (Serial.available()) { // Si hay datos en el puerto serial
      String comando = Serial.readStringUntil('\n'); // Leemos la línea completa
      comando.trim(); // Eliminamos espacios en blanco alrededor del comando

      if (comando == "ON") { // Si el comando es "ON"
        sistemaActivo = true; // Activamos el sistema
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sistema Activo"); // Mostramos mensaje en el LCD
        Serial.println("Sistema activado. Monitoreo iniciado.");
        delay(1000); // Espera para que el mensaje se muestre
        lcd.clear();
      }
    }
    return; // Salimos de la función loop temporalmente si el sistema no está activo
  }

  // Monitoreo de movimiento con el sensor PIR
  bool movimientoDetectado = digitalRead(PIR_PIN); // Leemos el estado del sensor PIR
  if (movimientoDetectado) {
    Serial.println("Movimiento detectado: posible intruso."); // Notificación de intrusión en el puerto serial
  }

  // Medición de distancia con el sensor ultrasónico HC-SR04
  long distancia = medirDistancia(); // Llamada a la función de medición de distancia
  if (distancia < 20) {  // Si el vehículo está a menos de 20 cm
    encenderLED(LED_RED); // Enciende el LED en rojo
    lcd.setCursor(0, 0);
    lcd.print("¡ALERTA!      "); // Muestra alerta en el LCD
  } else if (distancia >= 20 && distancia <= 100) { // Distancia segura entre 20 y 100 cm
    encenderLED(LED_BLUE); // Enciende el LED en azul
    lcd.setCursor(0, 0);
    lcd.print("---          "); // Muestra "---" en el LCD como indicador de distancia segura
  } else { // Si la distancia es mayor a 100 cm (no hay vehículo cerca)
    encenderLED(LED_GREEN); // Enciende el LED en verde
    lcd.setCursor(0, 0);
    lcd.print("-            "); // Muestra "-" en el LCD indicando que no hay vehículo cerca
  }

  delay(1000); // Pausa de 1 segundo para la siguiente medición
}

// Función para medir distancia usando el sensor ultrasónico HC-SR04
long medirDistancia() {
  // Enviamos un pulso de 10 microsegundos al pin Trigger
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Medimos la duración del pulso de respuesta en el pin Echo
  long duracion = pulseIn(ECHO_PIN, HIGH);

  // Convertimos la duración del pulso a distancia en cm (velocidad del sonido ≈ 0.034 cm/µs)
  long distancia = duracion * 0.034 / 2;
  return distancia;
}

// Función para encender el LED RGB en el color especificado
void encenderLED(int colorPin) {
  // Apagamos todos los pines del LED RGB antes de encender el color específico
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(colorPin, HIGH); // Enciende el color correspondiente
}
