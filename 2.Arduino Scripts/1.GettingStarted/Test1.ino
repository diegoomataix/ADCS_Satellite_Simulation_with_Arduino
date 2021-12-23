//include the servo library:
#include <Servo.h>
//variables for storing values from LDRs:
int ldr1;
int ldr2;
//variable for the servo angle, initial value 90:
int angle = 90;
//create a servo object:
Servo myServo;

void setup()
{
    myServo.attach(11);   //servo is connected to pin 11
    myServo.write(angle); // set servo to starting ange
    Serial.begin(9600);   //start serial communication
}

void loop()
{
    //read both sensor values and and store to variables:
    ldr1 = analogRead(A0);
    ldr2 = analogRead(A1);

    //if value from ldr1 is bigger than ldr2,
    //decrease the angle by 2 degrees:
    if (ldr1 > ldr2)
    {
        angle = angle - 2;
        //else increase the angle:
    }
    else if (ldr1 <= ldr2)
    {
        angle = angle + 2;
    }
    //check if the angle has reached the maximum.
    //if it has, set angle to 180.
    if (angle > 180)
    {
        angle = 180;
    }
    //check if the angle has reached the minimum.
    //if it has, set angle to 0:
    if (angle < 0)
    {
        angle = 0;
    }

    //print values for debugging purposes:
    Serial.print("ldr1: ");
    Serial.print(ldr1);
    Serial.print(" ldr2: ");
    Serial.print(ldr2);
    Serial.print(" angle: ");
    Serial.println(angle);

    //finally, set the servo to an angle:
    myServo.write(angle);
    //a small delay:
    delay(20);
}