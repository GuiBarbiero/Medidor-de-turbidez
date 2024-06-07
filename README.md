# Medidor de Turbidez da Água

Projeto no Tinkercad desenvolvido para medir e indicar o nível da turbidez das águas do mar, de acordo com a quantidade de poluição.




## Materiais Utilizados

- Arduino Uno
- Potenciômetro (simulado como se fosse um sensor de turbidez)
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores (220Ω)
- Fios Jumper
- Placa de Ensaio Pequena


## Instruções de Uso

Primeiramente, é necessário colocar o sensor de turbidez em contato com a água do mar e assim ele medirá o espalhamento de luz produzido pela presença de partículas em suspensão  sendo expressa como Unidade Nefelométrica de Turbidez.

Os LEDs serão ligados quando um determinado nível de turbidez for detectado. 
- O verde acenderá quando a Unidade Nefelométrica de Turbidez for menor que 300, significando que a água está limpa. 
- O amarelo acenderá nos níveis maiores que 300 e menores que 600, significando que a água já não está 100% limpa e precisa de uma atenção maior.
- O vermelho acenderá quando a unidade for maior que 600, indicando um grau alto de turbidez e que o tratamento desse fluido precisa ser iniciado.


## Código Fonte C++

```
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

```
## Projeto Simulado

Link do projeto no Tinkercad: https://www.tinkercad.com/things/eibn55Iv2tH-magnificent-amur-jofo/editel?sharecode=dh11j_QI8xqpvM-nSwEQ-iuIKR9e3UJLsTAIEkqYr2w
## Autores

- [@Camilamie](https://github.com/camilamie) [RM: 555418]
- [@Valieris](https://www.github.com/Valieris) [RM: 555119]
- [@Guibarbiero](https://www.github.com/Guibarbiero) [RM: 555185]