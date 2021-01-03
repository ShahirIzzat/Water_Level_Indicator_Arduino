const int trigPin = 3;
const int echoPin = 2;
float duration;
float distance;
int led_red = 5;
int led_green = 6;

void setup() 
{
pinMode(led_red, OUTPUT);
pinMode(led_green, OUTPUT);  
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

}

void loop() 
{

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = ((duration*(0.0343))/2);
delay(10);

if (distance > 8)
{
Serial.print("Water Level is Low : ");
Serial.println(distance);
Serial.print("\n");

digitalWrite(led_red, HIGH);

// turn off tone function for pin 8:
noTone(8);
// play a note on pin 6 for 200 ms:
tone(6, 440, 200);
delay(200);

// turn off tone function for pin 6:
noTone(6);
// play a note on pin 7 for 500 ms:
tone(7, 494, 500);
delay(500);

// turn off tone function for pin 7:
noTone(7);
// play a note on pin 8 for 300 ms:
tone(8, 523, 300);
delay(10);

}

else
{
digitalWrite(led_green, HIGH);
Serial.print("FULL : ");
Serial.println(distance);
Serial.print("\n");
delay(100);
}

}
