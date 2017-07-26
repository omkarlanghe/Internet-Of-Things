void setup() {
  // put your setup code here, to run once:
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0,HIGH);
  delay(700);
  digitalWrite(D0,LOW);
  delay(200);
  digitalWrite(D1,HIGH);
  delay(300);
  digitalWrite(D1,LOW);
  delay(200);
   digitalWrite(D2,HIGH);
  delay(1000);
  digitalWrite(D2,LOW);
  delay(200);
  
}
