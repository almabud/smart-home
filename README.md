# Smart Home
------------

## Components:
-	Arduino Uno *2
- Bread board *2
- Echo sensor *3
- Servo sg90 *2
- LCD Display(16*2)  *1
- LM35 *1
- LED *1
- LDR Module *1
- Water Pump *2
- Relay Modul *2
- Water Pipe && Jumpers wire
- Soil moisture sensor *1

## Wire connection:
## Door:
### Echo Sensor:
- Trigger -> Arduino pin 12
- Echo -> Arduino pin 13
- Vcc -> 5 volt input
- Ground -> any ground pin.

### Servo Motor:
-	Middle wire -> Arduino pin 3
-	Vcc-> 5 volt input
-	Ground -> any ground pin
--------------------------

## Dustbin:
### Echo Sensor:
- Trigger -> Arduino pin 5
- Echo -> Arduino pin 4
- Vcc -> 5 volt input
- Ground -> any ground pin

### Servo Motor:
- Middle wire -> Arduino pin 2
- Vcc-> 5 volt input
- Ground -> any ground pin
-----------------------------
## Water Tank: 
### Echo Sensor:
- Trigger -> Arduino pin 8
-	Echo -> Arduino pin 7
-	Vcc -> 5 volt input
-	Ground -> any ground pin
### Relay Module:
-	IN -> Arduino pin 9
-	Vcc -> 5 volt input
-	Ground -> any ground pin
> Note: Next connect the water pump to the relay module.
---------------------------------
## Out door Lamp:
### LDR Module:	
- IN -> Arduino pin A2
-	Vcc -> 5 volt input
-	Ground -> any ground pin
### LED / Lamp pin:	
-	Vcc-> Arduino pin 10
-	Ground -> any ground pin
---------------------------------
## automatic garden watering system:
### Relay Module:
-	IN -> Arduino pin 11
-	Vcc -> 5 volt input
-	Ground -> any ground pin
> Note: Next connect the water pump to the relay module.
### Soil moisture sensor:
-	AO/Analog output -> Arduino pin A0
-	Vcc -> 5 volt input
-	Ground -> any ground pin
---------------------------------

## Temperature sensor  (2nd Arduino uno):
### LM35:
-	Analog out/ middle pin -> Arduino pin A0
-	Vcc -> 5 volt input
-	Ground -> any ground pin
### Display:
-	rs -> Arduino pin  5;
-	en -> Arduino pin  6;
-	d4 – d7 -> Arduino pin  6,10,11,12,13;
> Note: For details connection of LCD please search on google. Here only  Arduino pin that is connected with Arduino is shown. Also some necessary components are needed for LCD display. Here you can used LCD module.



