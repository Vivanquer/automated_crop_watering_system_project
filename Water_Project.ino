#define PUMP_PIN 8
#define SENSOR_PIN A0

// Calibration - SET THESE!
const int DRY = 475;   // Value in dry air
const int WET = 200;   // Value in water
const int THRESHOLD = 15; // Moisture % to trigger

void setup() {
  // Critical stability delays
  delay(2500);  // Wait for power stabilization
  Serial.begin(9600);
  
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW); // Start with pump OFF
  
  Serial.println(F("System Ready (Protected)"));
}

void loop() {
  int moisture = readMoisture();
  Serial.println(moisture);
  //Serial.println(F("%"));
  if(moisture < THRESHOLD) {
    safePumpCycle();
  }
  
  delay(1800000); // Check every 30 minutes
}

int readMoisture() {
  int val = analogRead(SENSOR_PIN);
  //Serial.println(val);
  val = constrain(val, WET, DRY);
  return map(val, DRY, WET, 0, 100); // 0% = dry, 100% = wet
}

void safePumpCycle() {
  activatePump();
  delay(1000);  // Run for 1 second
  deactivatePump();
}

void activatePump() {
  static unsigned long lastPumpTime = 0;
  
  // Prevent rapid toggling
  if(millis() - lastPumpTime < 3000) return;
  
  digitalWrite(PUMP_PIN, LOW);  // Turn off first
  delay(50);                    // Debounce delay
  digitalWrite(PUMP_PIN, HIGH);
  
  Serial.println("Pump: ON (Stable)");
  lastPumpTime = millis();
}

void deactivatePump() {
  digitalWrite(PUMP_PIN, LOW);
  delay(50);  // Debounce delay
  Serial.println("Pump: OFF");
}
