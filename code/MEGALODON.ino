//THIS CODE IS FOR THE ROBOT'S ROLL AND DRIVING
int U;//VARIABLE FOR ULTRASONIC SENSOR
int W;//VARIABLE FOR WATER SENSOR
int T;//VARIABLE FOR TURBIDITY SENSOR

float checkdistance_6_5() {
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  float distance = pulseIn(5, HIGH) / 58.00;
  delay(10);
  return distance;
}

void forward() {
  analogWrite(3,80);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  analogWrite(11,80);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
}

void left() {
  analogWrite(3,80);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  analogWrite(11,80);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
}

void stop() {
  analogWrite(3,0);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  analogWrite(11,0);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

void right() {
  analogWrite(3,80);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  analogWrite(11,80);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}

void setup(){
  U = 0;
  W = 0;
  T = 0;
  pinMode(6, OUTPUT);//ULTRASONIC TRIG
  pinMode(5, INPUT);//ULTRASONIC ECHO 
  Serial.begin(9600);
  pinMode(8, OUTPUT);//DELAY
  pinMode(3,OUTPUT);//ANALOG LEFT SIDE
  pinMode(4, OUTPUT);//LEFT MOTOR
  pinMode(7, OUTPUT);//LEFT MOTOR
  pinMode(11,OUTPUT);//ANALOG RIGHT SIDE
  pinMode(12, OUTPUT);//RIGHT MOTOR
  pinMode(13, OUTPUT);//RIGHT MOTOR
}

void loop(){
  U = checkdistance_6_5();
  W = analogRead(A5);
  T = analogRead(A0);
  Serial.println(String("ULTRA :") + String(U));
  Serial.println(String("WATER : ") + String(W));
  Serial.println(String("Turbidity") + String(T));
  if (U > 15) {
    forward();

  } else if (U < 15) {
    left();
  }
  if (W < 305 && T >= 780) {
    digitalWrite(8,LOW);

  } else if (W > 305 && T >= 780) {
    digitalWrite(8,HIGH);
  } else if (W > 305 && T < 780) {
    digitalWrite(8,HIGH);
  } else {
    digitalWrite(8,HIGH);

  }

}
