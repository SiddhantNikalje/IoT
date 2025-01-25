// Define the analog pins connected to AO pins of the modules
const int strainPin1 = 34;  // First strain module//X-Axis
const int strainPin2 = 35;  // Second strain module//Y-Axis
const int strainPin3 = 32;  // Third strain module//Z-Axis

void setup() {
  Serial.begin(115200);
  pinMode(strainPin1, INPUT);
  pinMode(strainPin2, INPUT);
  pinMode(strainPin3, INPUT);
}

void loop() {
  // Read analog values for each strain module
  int analogValue1 = analogRead(strainPin1);
  int analogValue2 = analogRead(strainPin2);
  int analogValue3 = analogRead(strainPin3);

  // Convert analog values to voltage (assuming 5V power supply)
  float voltage1 = (analogValue1 / 4095.0) * 5.0;
  float voltage2 = (analogValue2 / 4095.0) * 5.0;
  float voltage3 = (analogValue3 / 4095.0) * 5.0;

  // Strain sensitivity coefficient
  float sensitivity = 2.0;  // mV/με (example value)

  // Calculate strain for each module
  float strain1 = (voltage1 * 1000) / sensitivity;  // Convert to με
  float strain2 = (voltage2 * 1000) / sensitivity;  // Convert to με
  float strain3 = (voltage3 * 1000) / sensitivity;  // Convert to με

  // Display the values for each module
  Serial.print("Signal -X Axis- Analog: ");
  Serial.print(analogValue1);
  Serial.print(" , Voltage: ");
  Serial.print(voltage1);
  Serial.print(" , Strain: ");
  Serial.println(strain1);

  Serial.print("Signal -Y Axis- Analog: ");
  Serial.print(analogValue2);
  Serial.print(" , Voltage: ");
  Serial.print(voltage2);
  Serial.print(" , Strain: ");
  Serial.println(strain2);

  Serial.print("Signal -Z Axis- Analog: ");
  Serial.print(analogValue3);
  Serial.print(" , Voltage: ");
  Serial.print(voltage3);
  Serial.print(" , Strain: ");
  Serial.println(strain3);

  delay(1000);  // Wait for 1 second before next reading
}
