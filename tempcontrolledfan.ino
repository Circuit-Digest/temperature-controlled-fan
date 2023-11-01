const int lm35_pin = A0;   // LM35 output pin
const int relay_pin = 2;   // Relay control pin (change to the appropriate pin)
void setup() {
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);  // Set the relay pin as an output
  digitalWrite(relay_pin, LOW);   // Turn off the relay (fan)
}
void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  // Read temperature
  temp_val = (temp_adc_val * 4.88); // Convert ADC value to equivalent voltage
  temp_val = (temp_val / 10);       // LM35 gives an output of 10mV/°C
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.println(" Degree Celsius");
  
  if (temp_val < 40) {
    Serial.println("Fan off");
    digitalWrite(relay_pin, LOW);   // Turn off the relay (fan)
   
  } else {
     Serial.println("Fan on");
    digitalWrite(relay_pin, HIGH);  // Turn on the relay (fan)
  }
}
