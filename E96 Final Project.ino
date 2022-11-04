void setup() {
  Serial.begin(9600);
}

void loop() {
  int inputval = analogRead(A5);
  Serial.println(inputval);
  delay(15);
}