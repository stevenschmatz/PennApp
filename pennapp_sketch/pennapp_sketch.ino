int x;
int y;


void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(A5, INPUT);
}

void loop() {
  y = analogRead(A5);
  x = analogRead(A4);
  Serial.print(y);
  Serial.print("    ");
  Serial.println(x);
  delay(50);
}
