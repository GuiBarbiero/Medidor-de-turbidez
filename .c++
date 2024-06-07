int sensorPin = A0; // Pino do sensor de turbidez (potenciómetro)
int greenLedPin = 9; // Pino do LED verde
int yellowLedPin = 10; // Pino do LED amarelo
int redLedPin = 11; // Pino do LED vermelho

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(500);

  // Apaga todos os LEDs
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  // Define os níveis de turbidez
  if (sensorValue < 300) {
    digitalWrite(greenLedPin, HIGH); // Nível aceitável
  } else if (sensorValue < 600) {
    digitalWrite(yellowLedPin, HIGH); // Atenção
  } else {
    digitalWrite(redLedPin, HIGH); // Maior atenção
  }
}