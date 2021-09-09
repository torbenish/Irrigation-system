/*  You can change the stepperPins           */
/*  to any digital pins that you would like  */
/*  wire connection order {in1,in2,in3,in4}  */
uint8_t stepperPins [4] = {14,12,13,15};  

/*These are to state movement direction*/
uint8_t STOP     = 0;
uint8_t FORWARD  = 1;
uint8_t BACKWARD = 2; 
char c;



/*This is used to keep track of the current step state*/
uint8_t stepper_Tracker = 0;

void setup() {
  Serial.begin(9600);
  pinMode(stepperPins[0], OUTPUT);
  pinMode(stepperPins[1], OUTPUT);
  pinMode(stepperPins[2], OUTPUT);
  pinMode(stepperPins[3], OUTPUT);
  set_Motor_Pins_Low();
  delay(1000);
}

void loop() {
  unsigned long tempStartTime  = millis();
  unsigned long currentStepperTime = millis();  
  c = Serial.read();
  switch (c)
  {
  case '1': // 20 segundos
    while ((currentStepperTime-tempStartTime) < 10000)/*loop 10 seconds forward*/
  {
    one_Step(FORWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  tempStartTime  = millis();
  currentStepperTime = millis();
    while ((currentStepperTime-tempStartTime) < 10000)/*loop 10 seconds backward*/
  {
    one_Step(BACKWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  break;
  case '2': // 40 segundos
    while ((currentStepperTime-tempStartTime) < 20000)/*loop 20 seconds forward*/
  {
    one_Step(FORWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  tempStartTime  = millis();
  currentStepperTime = millis();
    while ((currentStepperTime-tempStartTime) < 20000)/*loop 20 seconds backward*/
  {
    one_Step(BACKWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  break;
  case '3': // 60 segundos
    while ((currentStepperTime-tempStartTime) < 30000)/*loop 30 seconds forward*/
  {
    one_Step(FORWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  tempStartTime  = millis();
  currentStepperTime = millis();
    while ((currentStepperTime-tempStartTime) < 30000)/*loop 30 seconds backward*/
  {
    one_Step(BACKWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  break;
  case '4': // 120 segundos
    while ((currentStepperTime-tempStartTime) < 60000)/*loop 60 seconds forward*/
  {
    one_Step(FORWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  tempStartTime  = millis();
  currentStepperTime = millis();
    while ((currentStepperTime-tempStartTime) < 60000)/*loop 60 seconds backward*/
  {
    one_Step(BACKWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  break;
  case '5': // 300 segundos
    while ((currentStepperTime-tempStartTime) < 150000)/*loop 150 seconds forward*/
  {
    one_Step(FORWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  tempStartTime  = millis();
  currentStepperTime = millis();
    while ((currentStepperTime-tempStartTime) < 150000)/*loop 150 seconds backward*/
  {
    one_Step(BACKWARD);
    delay(5);/*make larger to slow down spin speed, should not be 0 */
    currentStepperTime = millis(); 
  }
  break;
  default:
  break;
}
}  


/*Ignore below, unless you want to know how it works*/


void one_Step(uint8_t stepper_direction)
{
  if(stepper_direction == FORWARD)
  {
    if(stepper_Tracker == 3)
    {
      stepper_Tracker = 0; 
    }
    else
    {
      stepper_Tracker = stepper_Tracker+1;
    } 
    set_Motor_Pin(stepper_direction);
  }
  else if(stepper_direction == BACKWARD)
  {
    if(stepper_Tracker == 0)
    {
      stepper_Tracker =3; 
    }
    else
    {
      stepper_Tracker = stepper_Tracker-1;
    }
    set_Motor_Pin(stepper_direction); 
  }
}

void set_Motor_Pin(uint8_t moving_direction)
{
  if (moving_direction == FORWARD)
  {
    if(stepper_Tracker == 0)
    {
      digitalWrite(stepperPins[3], LOW); 
      digitalWrite(stepperPins[0], HIGH); 
    }
    else
    {
      digitalWrite(stepperPins[stepper_Tracker-1], LOW); 
      digitalWrite(stepperPins[stepper_Tracker], HIGH); 
    }
  }
  else if(moving_direction == BACKWARD)
  {
    if(stepper_Tracker ==3)
    {
      digitalWrite(stepperPins[0], LOW); 
      digitalWrite(stepperPins[3], HIGH);
    }
    else
    {
      digitalWrite(stepperPins[stepper_Tracker+1], LOW); 
      digitalWrite(stepperPins[stepper_Tracker], HIGH); 
    }
  }
  else if(moving_direction == STOP)
  {
    set_Motor_Pins_Low();
  }
}

void set_Motor_Pins_Low()
{
  digitalWrite(stepperPins[0], LOW); 
  digitalWrite(stepperPins[1], LOW); 
  digitalWrite(stepperPins[2], LOW); 
  digitalWrite(stepperPins[3], LOW);
}
