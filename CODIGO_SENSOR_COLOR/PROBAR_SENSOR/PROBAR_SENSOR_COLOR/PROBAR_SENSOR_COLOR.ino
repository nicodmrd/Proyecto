// Sensor de Color TCS3200
// 
//    Arduino   TCS3200 SENSOR COLOR
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

// Parámetros de las lecturas
#define NUM_SAMPLES 5  // Número de lecturas por color

// Variables para las lecturas del sensor
int redValue = 0, greenValue = 0, blueValue = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorSalida, INPUT);

  // Configura la escala de Frecuencia en 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Leer y promediar el valor ROJO
  redValue = tomarPromedio(LOW, LOW);

  // Leer y promediar el valor VERDE
  greenValue = tomarPromedio(HIGH, HIGH);

  // Leer y promediar el valor AZUL
  blueValue = tomarPromedio(LOW, HIGH);

  // Mostrar valores promedio
  Serial.print("Promedio R: "); Serial.print(redValue);
  Serial.print(" V: "); Serial.print(greenValue);
  Serial.print(" A: "); Serial.println(blueValue);

  // Clasificación del material con valores promedios
  if ((redValue > 390 && redValue < 420) && (greenValue > 415 && greenValue < 440) && (blueValue > 330 && blueValue < 360)) Serial.print(" *** NEGRO ***");                 
  if ((redValue > 240 && redValue < 280) && (greenValue > 300 && greenValue < 335) && (blueValue > 260 && blueValue < 290)) Serial.print(" *** CARTÓN ***");
  if ((redValue > 290 && redValue < 400) && (greenValue > 340 && greenValue < 400) && (blueValue > 290 && blueValue < 345)) Serial.print(" *** PLASTICA ***");
  if ((redValue > 35 && redValue < 40) && (greenValue > 47 && greenValue < 52) && (blueValue > 44 && blueValue < 49)) Serial.print(" *** VIDRIO ***");
  if ((redValue > 35 && redValue < 40) && (greenValue > 47 && greenValue < 52) && (blueValue > 44 && blueValue < 49)) Serial.print(" *** OTROS ***");

  Serial.println();
  delay(200);
}

// Función para tomar el promedio de múltiples lecturas
int tomarPromedio(int s2State, int s3State) {
  long total = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    digitalWrite(S2, s2State);
    digitalWrite(S3, s3State);
    delay(10);  // Pequeño delay para estabilizar el sensor
    total += pulseIn(sensorSalida, LOW);
  }
  return total / NUM_SAMPLES;
}
