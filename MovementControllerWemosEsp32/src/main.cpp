#include <Arduino.h>
// Motor A connections
int enA = 16;
int in1 = 22;
int in2 = 21;
// Motor B connections
int enB = 23;
int in3 = 19;
int in4 = 5;

char direction = 'f';
// speed er max 255
int speed = 127;
int stop = 0;

void Backwards(int time){
    analogWrite(enA, speed);
    analogWrite(enB, speed);

    // Turn on motor A & B
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(time);
}
void Forwards(int time){
    analogWrite(enA, speed);
    analogWrite(enB, speed);

    // Turn on motor A & B
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(time);
}
void Left(int time){
    analogWrite(enA, speed);
    analogWrite(enB, 0);

    // Turn on motor A & B
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(time);
}
void Right(int time){
    analogWrite(enA, 0);
    analogWrite(enB, speed);

    // Turn on motor A & B
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(time);
}




void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
	
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void loop() {
    if (stop <= 2){
        if (direction == 'f')
        {
            Forwards(2000);
            direction = 'b';
        }else if (direction == 'b')
        {
            Backwards(2000);
            direction = 'l'; 
        }else if (direction == 'l')
        {
            Left(2000);
            direction = 'r';
        }else if (direction == 'r')
        {
            Right(2000);
            direction = 'f';
            stop++;
        }
    }
    if (stop == 3){
        analogWrite(enA, 0);
        analogWrite(enB, 0);
    }
}

/* alt væk
void directionControl() {
    // Set motors to maximum speed
    // PWM value ranges from 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);

    // Turn on motor A & B
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);
	
    // Turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
void speedControl() {
    // Turn on motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
	
    for (int i = 0; i < 256; i++) {
        analogWrite(enA, i);
        analogWrite(enB, i);
        delay(20);
    }
	
    for (int i = 255; i >= 0; --i) {
        analogWrite(enA, i);
        analogWrite(enB, i);
        delay(20);
    }
	
    // Now turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
	
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void loop() {
    directionControl();
    delay(1000);
    speedControl();
    delay(1000);
}

*/