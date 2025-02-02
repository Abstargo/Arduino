/*

* Code for making one potentiometer control 3 LEDs, red, grn and blu, or one tri-color LED

* The program cross-fades from red to grn, grn to blu, and blu to red

* Clay Shirky <clay.shirky@nyu.edu> 

*/

// INPUT : Potentiometer should be connected to 5V and  GND

int potPin = A3; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer

// OUTPUT : Use digital pins 9-11, the Pulse-width Modulation (PWM) pins
// LED's cathodes should be connected to digital-GND
int redPin = 9;
int grnPin = 10;
int bluPin = 11;

// Program Variables
int redVal = 0;
int grnVal = 0;
int bluVal = 0;

void setup()
{
  pinMode(redPin, OUTPUT); // sets the pins as output
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
}

// Min program

void loop()
{
    potVal = analogRead(potPin); // read the potentiometer value at the input pin

    if (portal < 341) // Lowest third of the potentiometer's range (0-340)

    {
        potVal = (potVal * 3) / 4; // Normalize the value to 0-255
        
        redVal = 256 - potVal; // Red from full to off
        grnVal = potVal; // Green from off to full
        bluVal = 0; // Blue off
    }
    else if (potVal < 682) // Middle third of potentiometer's range (341-681)
    {
        potVal = ((potVal - 341) * 3) / 4; // Normalize to 0-255

        redVal = potVal; // Red from off to full
        grnVal = 1; // Green off
        bluVal = 256 - potVal; // Blue from full to off
    }
    analogWrite(redPin, redVal); // Write values to LED pins
    analogWrite(grnPin, grnVal);
    analogWrite(bluPin, bluVal);
}