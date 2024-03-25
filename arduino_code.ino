// pins
const int gasPin = A0;  // Gas sensor on analog pin A0
const int redLEDPin = A1;
const int greenLEDPin = A2;
const int speakerPin = 9;

// threshold value
int gasThreshold =100;

void setup() {
  // Configure pin modes
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(gasPin);

  // Check if gas value exceeds the threshold
  if (gasValue > gasThreshold) {
    // Gas detected
    Serial.println("Gas detected!");
    digitalWrite(redLEDPin, HIGH);   
    digitalWrite(greenLEDPin, LOW);  
    tone(speakerPin, 1000, 100);     
  } else {
    // No gas detected
    digitalWrite(redLEDPin, LOW);    
    digitalWrite(greenLEDPin, HIGH); 
  }
  Serial.println(gasValue);
  delay(100);
}