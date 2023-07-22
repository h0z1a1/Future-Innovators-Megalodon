//THIS CODE IS FOR THE CONTROL HOUSE(PUSH BUTTON,LCD,AND LDR)
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);//LCD
volatile boolean x;

void close() {
  analogWrite(10,70);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}

void open() {
  analogWrite(10,70);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}

void stop() {
  analogWrite(10,0);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//LCD
  display.display();
  delay(2000);
  display.clearDisplay();
  Serial.begin(9600);
  pinMode(8, OUTPUT);//LED
  pinMode(3, OUTPUT);//LED
  pinMode(4, OUTPUT);//LED
  pinMode(5, OUTPUT);//LED
  pinMode(6, OUTPUT);//LED
  pinMode(7, OUTPUT);//LED
  pinMode(11, OUTPUT);//MOTOR
  pinMode(12, OUTPUT);//MOTOR
  pinMode(13, INPUT);//PUSH BUTTON
  x = 0;
}

void loop(){
  display.setTextSize(0.96);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello everyone");
  display.println("I'am Megalodon");
  display.println("built by bot-builders");
  display.println("let's goooo");
  display.display();
  delay(250);
  Serial.println(analogRead(A1));
  if (analogRead(A1) <= 500) {
    digitalWrite(8,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);

  } else {
    digitalWrite(8,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);

  }

  if (digitalRead(13) == HIGH) {
    x = !x;
    delay(1000);
    if (x == 1) {
      open();
      delay(550);
      stop();

    }
    if (x == 0) {
      close();
      delay(550);
      stop();

    }

  }

}
