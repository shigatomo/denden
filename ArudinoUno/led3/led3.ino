#define LED3 3

void setup() {
  pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED3, HIGH);
  delay(1000);
  digitalWrite(LED3, LOW); 
  delay(3000);
}
