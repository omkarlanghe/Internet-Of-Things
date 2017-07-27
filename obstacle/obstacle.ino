int obs=D5;
int led=D2;
int count=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(obs,INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int res=digitalRead(obs);
  
  Serial.println(res);
  if(res==1){
    
    Serial.println("Obstacle detected..");
    digitalWrite(led,HIGH);

    Serial.print("count: ");
    count++;
  Serial.println(count);
  delay(2000);
  
  } else {
  
    Serial.println("Obstacle not detected..");
    digitalWrite(led,LOW);
  }
}
