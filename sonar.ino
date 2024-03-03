#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


#define echoPin 2
#define trigPin 3
#define buzzPin 4                                                                                                             


// SCL = A5   SDA = A4

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);

  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:

  long duration, distance;
  // digitalWrite(ledPin, LOW);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  lcd.print("Distance: ");
  Serial.println(distance);
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <10)
  {
    digitalWrite(buzzPin, HIGH);
    delay(300);
    digitalWrite(buzzPin, LOW);
    
  }

  
  delay(10);  

  lcd.init();



  
}
