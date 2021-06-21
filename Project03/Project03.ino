const int sensorPin = A0;
int pinNumber = 0;
int sensorVal = 0;
float baseLineTemp = 0.0;
int i = 0;

void setup() 
{
  Serial.begin(9600); // open a serial port
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

float CalibrateTemp(float x) //Function used to calibrate a temperature sensor to room ambient temperature
  {
    // Calibrating the temperature sensor
    Serial.print("BASE LINE SENSOR VAL: ");
    Serial.print(x);
    // Convert ADC reading to voltage
    float y = (x/1024.0) * 5.0;
    Serial.print(" BASE LINE VOLTAGE: ");
    Serial.print(y);
    // Convert voltage into degrees C
    float z = (y - 0.5) * 100;
    Serial.print(" BASE LINE TEMP: ");
    Serial.println(z);
	return z;
  }



void loop()
{
  if(int i = 0)
  {
	delay(5000);
	baseLineTemp = CalibrateTemp(sensorVal);
	i++;
  }	
  
  // Show Calibration
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // covert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(" , Volts: ");
  Serial.print(voltage);
  Serial.print(" , degrees C: ");
  // convert the voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if(temperature < baseLineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baseLineTemp+2 && temperature < baseLineTemp+4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baseLineTemp+4 && temperature < baseLineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baseLineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}
