// Define the analog pin connected to AO pin of the module
const int strainPin = 34;  // Example GPIO pin for analog input

void setup() {
  Serial.begin(115200);
  pinMode(strainPin, INPUT);
}

void loop() {
  // Read the analog value (0-4095, as ESP32 uses 12-bit ADC)
  int analogValue = analogRead(strainPin);

  // Convert the analog value to voltage (assuming 5V power supply)
  float voltage = (analogValue / 4095.0) * 5.0;

  // Optional: Calculate strain using a strain sensitivity coefficient
  // Example strain sensitivity coefficient (change it as per your module)
  float sensitivity = 2.0;  // mV/με (from the document)

  // Calculate strain
  float strain = (voltage * 1000) / sensitivity;  // Convert to με

  // Display the values
  // Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" , ");
  // Serial.print(" | Voltage: "); 
  Serial.print(voltage);
  Serial.print(" , ");
  // Serial.print(" V | Strain: ");
  Serial.println(strain);
  // Serial.println(" με");

  delay(50);  // Wait for 0.5 second before next reading
}
