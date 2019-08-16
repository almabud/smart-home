
#include <Servo.h> 
int pirSensor = 6; 
int gateServoPin = 3; 
int dustServoPin = 2;
int pirState = LOW; 
int dustEcho = 4;
int dustTrig = 5;
int tankEcho = 7;
int tankTrig = 8;
//long gateDuration;
int gateDistance;
long tankDuration;
int tankDistance;
long duration;
int distance;
int gateTrig = 12;
int gateEcho = 13;
int tankRelay = 9;
int dustbinFlag = 0;
int gradenRelay=11;
int soilSensorPin = A0; 
int soilSensorValue;  
int soilLimit = 400; 
int ldrPin = A2;
int lamp = 10;
int gateDuration;
Servo survoGate; 
Servo survoDust;
void setup() {
  survoGate.attach(gateServoPin); 
  survoDust.attach(dustServoPin);
  pinMode(pirSensor, INPUT);
  pinMode(dustTrig, OUTPUT); 
  pinMode(dustEcho, INPUT);
  pinMode(tankTrig, OUTPUT); 
  pinMode(tankEcho, INPUT);
  pinMode(gateTrig, OUTPUT); 
  pinMode(gateEcho, INPUT);
  pinMode(tankRelay, OUTPUT);
  pinMode(gradenRelay, OUTPUT);
  pinMode(soilSensorPin, INPUT);
  pinMode(lamp, OUTPUT);
  pinMode(ldrPin, INPUT);
  digitalWrite(tankRelay, HIGH);
  digitalWrite(gradenRelay, HIGH);

   Serial.begin(9600);
}
void autoLight(){
  int ldrVal = analogRead(ldrPin);
  if(ldrVal <= 300){
    digitalWrite(lamp, HIGH);
  }
  else{
    digitalWrite(lamp, LOW);
  }
  
}
void soil(){
   soilSensorValue = analogRead(soilSensorPin); 
   Serial.println("Analog Value : ");
   Serial.println(soilSensorValue);
   
   if (soilSensorValue>soilLimit) {
     digitalWrite(tankRelay, LOW); //Relay need to on so water pump can  supply water to the garden
   }
   else {
    digitalWrite(tankRelay, HIGH); //Relay is off.
   }
   
}
void tank(){
  /* First measure the distance */
    digitalWrite(tankTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(tankTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(tankTrig, LOW);
    tankDuration = pulseIn(tankEcho, HIGH);
    tankDistance= tankDuration*0.034/2;

    /*Now if check the water level and do neccesarry job */
    if(tankDistance >= 4){
      digitalWrite(tankRelay, LOW);
    }
    if(tankDistance > 0 && tankDistance <= 3){
      digitalWrite(tankRelay, HIGH);
    }

    Serial.print("tankDistance ");
    Serial.println(tankDistance);
  delay(20);
}
void dustbin(){
    /* First measure the distance */
    digitalWrite(dustTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(dustTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(dustTrig, LOW);
    duration = pulseIn(dustEcho, HIGH);
    distance= duration*0.034/2;
    survoDust.write(80);
   
    if(distance < 4 && distance > 0)
    {
      survoDust.write(0);
      Serial.print("Dust Distance: ");
      Serial.println(distance);
    }
    else{
      survoDust.write(80);
    }
      Serial.print("Dust Distance: ");
      Serial.println(distance);
   
    
}
void gate(){
    digitalWrite(gateTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(gateTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(gateTrig, LOW);
     survoGate.write(0); 
    gateDuration = pulseIn(gateEcho, HIGH);
    gateDistance = gateDuration*0.034/2;
    if(gateDistance <= 5 && gateDistance > 0){
       survoGate.write(90); 
    }
    else{
      survoGate.write(0); 
    }

    Serial.print("gateDistance ");
    Serial.println(gateDistance);
    
  
}

void loop() {
  gate();
  delay(200);
  dustbin();
  delay(200);
  tank();
  delay(200);
  soil();
  delay(200);
  //temparature();
  autoLight();
  delay(200);
  
}
