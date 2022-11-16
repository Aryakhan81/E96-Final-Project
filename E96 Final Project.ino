//Gloabl constants
const unsigned short pinin = A0;

//Global time variables
unsigned long startMillis;
unsigned long currentMillis;

//Write a function to learn the 
void setup() {
  Serial.begin(9600);
  startMillis = millis();
}

void loop() {
  //Update values
  int inputval = analogRead(pinin);
  currentMillis = millis() - startMillis;

  //Print values to Serial monitor
  Serial.print(inputval);
  Serial.print(',');
  Serial.print(currentMillis);
  Serial.println();
  delay(15);
}