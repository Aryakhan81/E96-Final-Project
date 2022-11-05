//Gloabl constants
const unsigned short pinin = A0;

//Write a function to learn the 
void setup() {
  Serial.begin(9600);
}

void loop() {
  int inputval = analogRead(pinin);
  Serial.println(inputval);
  delay(15);
}