
 
 #include <Servo.h>
#define trigPin 3
#define echoPin 2
Servo servo;


int sound = 250;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(4); //right hand updown motion

} 
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance < 10 && distance > 1 ) {
  Serial.println(distance,"start");
servo.write(90);



}
else { Serial.println("far");

servo.write(0);


}


}
