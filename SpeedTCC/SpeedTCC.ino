 #include <AccelStepper.h>

AccelStepper stepper(AccelStepper::FULL4WIRE, 14, 13, 12, 15);

int spd = 200;    // The current speed in steps/second
int sign = 1;      // Either 1, 0 or -1

void setup()
{ 
  Serial.begin(9600);
  stepper.setMaxSpeed(200);
  stepper.setSpeed(200);   
}

void loop()
{ 
  char c;
  c = Serial.read();
  switch (c)
  {
  case 'f':
    sign = 1;
    break;
  case 'r':  // reverse
    sign = -1;
  case 's':
    sign = 0;
    break;  
  case '1':
    spd = 100;
    break;
  case '2':
    spd = 200;
    break;
    default:
    break;
  }
  stepper.setSpeed(sign * spd);
  stepper.runSpeed();
}
