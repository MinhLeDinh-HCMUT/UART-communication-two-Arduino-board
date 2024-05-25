String x;
void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);  // Initialize pins
  pinMode(9,OUTPUT);
}

void loop() {
  if (Serial.available() > 0)  // Check data availability and read data
  {  
    x = Serial.readStringUntil('\n');   // Check for terminator
    Serial.println(x);
    if(x=="RED") digitalWrite(8, !digitalRead(8));   // Toggle pin's state
    if(x=="GREEN") digitalWrite(9, !digitalRead(9));    
  }
  
  int sensorValue = analogRead(A0);   // Read ADC value
  sensorValue = map(sensorValue,0,1023,0,255);
  String Value = String(sensorValue) + "\n";  // Add terminator and send data
  Serial.print(Value); 
}
