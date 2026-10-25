 
#include <Servo.h>
 
int pos = 0;
int sensorValue = 0;
int sensorValue2 = 0;
int velocidade = 0;
int i = 0;
 
Servo servo_9;
 
void setup()
{
  servo_9.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  sensorValue = analogRead(A0);
  sensorValue2 = analogRead(A1);
 
  pos = map(sensorValue, 0, 1023, 0, 180);
 
  // Controla a velocidade do servo
  velocidade = map(sensorValue2, 0, 1023, 5, 50);
 
  Serial.print("Sensor A0: ");
  Serial.println(sensorValue);
 
  Serial.print("Posicao: ");
  Serial.println(pos);
 
  Serial.print("Sensor A1: ");
  Serial.println(sensorValue2);
 
  Serial.print("Velocidade (delay): ");
  Serial.println(velocidade);
 
  for (i = 0; i <= pos; i++) {
    sensorValue2 = analogRead(A1);
    velocidade = map(sensorValue2, 0, 1023, 5, 50);
 
    servo_9.write(i);
    delay(velocidade);
  }
 
  for (i = pos; i >= 0; i--) {
    sensorValue2 = analogRead(A1);
    velocidade = map(sensorValue2, 0, 1023, 5, 50);
 
    servo_9.write(i);
    delay(velocidade);
  }
}
 