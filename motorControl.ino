// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

// Motor C connections
int enAAux = 10;
int in1Aux = 12;
int in2Aux = 13;
// Motor D connections
int enBAux = 11;
int in3Aux = 2;
int in4Aux = 6;

int cm = 100;

 // For PWM maximum possible values are 0 to 255
int speed = 150;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
    pinMode(enAAux, OUTPUT);
  pinMode(enBAux, OUTPUT);
  pinMode(in1Aux, OUTPUT);
  pinMode(in2Aux, OUTPUT);
  pinMode(in3Aux, OUTPUT);
  pinMode(in4Aux, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, LOW);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, LOW);

  Serial.begin(9600);

   //-----------------LED RGB--------------------
    pinMode(A2, OUTPUT); //red
    pinMode(A3, OUTPUT); // blue
    pinMode(A4, OUTPUT); // green
}

void loop() {     
    delay(2000); // Wait for 2000 millisecond(s) 

    if(checkMove()){
      delay(100);
      allMotorsForward();
      allMotorsForwardAux();   
  
      delay(1000);
      allMotorsOff();
      allMotorsOffAux();
    }else{
    /*
     * En el caso que no se pueda mover:
     *  Parar motores.
     *  Echar 0,5 seg hacia atrás.
     *  Girar a la derecha 0,5 seg.     
     *  Parar motores. 
     */
      allMotorsOff();
      allMotorsOffAux();

      delay(1000);
      allMotorsBackward();
      allMotorsBackwardAux(); 
      delay(500);

      allMotorsForward();
      allMotorsBackwardAux(); 
      delay(500);

      allMotorsOff();
      allMotorsOffAux();
    }
    
}

void allMotorsForward(){
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);   
}

void allMotorsBackward(){
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  // Turn on motor A & B
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);   
}

void allMotorsOff(){
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  // Turn on motor A & B
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);   
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, speed);
  analogWrite(enB, speed);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  
  // Now change motor directions
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

// This function lets you control spinning direction of motors
void directionControlAux() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAAux, speed);
  analogWrite(enBAux, speed);

  // Turn on motor A & B
  digitalWrite(in1Aux, HIGH);
  digitalWrite(in2Aux, LOW);
  digitalWrite(in3Aux, HIGH);
  digitalWrite(in4Aux, LOW);
  delay(2000);
  
  // Now change motor directions
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, HIGH);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, HIGH);
  delay(2000);
  
  // Turn off motors
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, LOW);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  
  // Decelerate from maximum speed to zero
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

// This function lets you control speed of the motors
void speedControlAux() {
  // Turn on motors
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, HIGH);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enAAux, i);
    analogWrite(enBAux, i);
    delay(20);
  }
  
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enAAux, i);
    analogWrite(enBAux, i);
    delay(20);
  }
  
  // Now turn off motors
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, LOW);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, LOW);
}

void allMotorsForwardAux(){
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAAux, speed);
  analogWrite(enBAux, speed);
  
  // Turn on motor A & B
  digitalWrite(in1Aux, HIGH);
  digitalWrite(in2Aux, LOW);
  digitalWrite(in3Aux, HIGH);
  digitalWrite(in4Aux, LOW);   
}

void allMotorsBackwardAux(){
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAAux, speed);
  analogWrite(enBAux, speed);
  
  // Turn on motor A & B
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, HIGH);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, HIGH);   
}

void allMotorsOffAux(){
  
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAAux, speed);
  analogWrite(enBAux, speed);
  
  // Turn on motor A & B
  digitalWrite(in1Aux, LOW);
  digitalWrite(in2Aux, LOW);
  digitalWrite(in3Aux, LOW);
  digitalWrite(in4Aux, LOW);   
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return 0.01723 * pulseIn(echoPin, HIGH);
}

bool checkMove()
{
   // measure the ping time in cm
  cm = readUltrasonicDistance(A0, A1);  
  //Serial.print(cm);
  //Serial.println("cm");
   if(cm > 120){
      colorVerde();
      return true;
   }else if((cm > 80) && (cm <=120)){
      colorAmarillo();
      return true;
   }else{
      colorRojo();
      return false;
   }  
}

void colorRojo(){
   //Hacer color rojo
  digitalWrite(A2,255);
  digitalWrite(A3,0);
  digitalWrite(A4,0); 
}

void colorAzul(){
  //Hacer color rojo
  digitalWrite(A2,0);
  digitalWrite(A3,255);
  digitalWrite(A4,0); 
}

void colorVerde(){
  //Hacer color rojo
  digitalWrite(A2,0);
  digitalWrite(A3,0);
  digitalWrite(A4,255); 
}

void colorAmarillo(){
  //Hacer color rojo
  digitalWrite(A2,255);
  digitalWrite(A3,0);
  digitalWrite(A4,255); 
}
