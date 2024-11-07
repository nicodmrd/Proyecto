int IN1 = 7;			// IN1 de L298N a pin digital 2
int IN2 = 6;			// IN2 de L298N a pin digital 3
int ENA = 5;			// ENA de L298N a pin digital 5
int VELOCIDAD = 200;			// variable para almacenar valor de velocidad

void setup(){
  pinMode(IN1, OUTPUT);		// pin 2 como salida
  pinMode(IN2, OUTPUT);		// pin 3 como salida	
  pinMode(ENA, OUTPUT);		// pin 5 como salida
}

void loop(){

  
  analogWrite(ENA, VELOCIDAD);				// el valor de velocidad y aplica a ENA
  digitalWrite(IN1, LOW);				// IN1 en 0
  digitalWrite(IN2, HIGH);				// IN2 en 1
  delay(2000);						// demora de 50 mseg. por cada iteracion
}