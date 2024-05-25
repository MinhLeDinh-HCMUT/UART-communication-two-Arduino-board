int button1 = 8;
int button2 = 9;
int enA = 6;
int in1 = 5;
int in2 = 4; 
int state1, state2, reading1, reading2;
int laststate1 = HIGH, laststate2 = HIGH,delaytime = 50;
unsigned long lastdelay1 = 0, lastdelay2 = 0;
String ADCstr;
byte ADCval;


void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT);  // Setting up pins
  pinMode(button2, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT); 
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);
}

void loop() {
  reading1 = digitalRead(button1);
  reading2 = digitalRead(button2);

  if (reading1 != laststate1) 
  {
    lastdelay1 = millis();
  }
  if ((millis() - lastdelay1) > delaytime)  // Debounce button 1
  { 
    if (reading1 == LOW && state1 == HIGH) 
    {
      Serial.print("RED\n");  // Send data
    }
    state1 = reading1;
  }
  laststate1 = reading1;
    
  if (reading2 != laststate2) {
    lastdelay2 = millis();
  }
  if ((millis() - lastdelay2) > delaytime)  // Debounce button 2 
  {
    if (reading2 == LOW && state2 == HIGH) 
    {
      Serial.print("GREEN\n");  // Send data
    }
    state2 = reading2;
  }
  laststate2 = reading2;
  
  if (Serial.available() > 0) // Check data availability and read data
  {
      ADCstr = Serial.readStringUntil('\n');  // Check for terminator
      ADCval = ADCstr.toInt();
  }
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, ADCval);
}
