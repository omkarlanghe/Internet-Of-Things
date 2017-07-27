  #include<ESP8266WiFi.h>
  
  const char* ssid = "Redmi";
  const char* password="12345678";
  
  int ledPin=D2;
  
  WiFiServer server(80);
  
  void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  Serial.print("\n\n Connecting To: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while(WiFi.status()!=WL_CONNECTED){
    delay(1000);
    Serial.print("."); //print dot till connection establishment.
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  
  //start the server
  server.begin();
  Serial.println("Server Started");
  
  //print the IP address
  Serial.println(WiFi.localIP());
  }
  
  
  void loop() {
   WiFiClient client = server.available();
   if(!client){
    return;
   }
  
   //Wait until the client sends some data
   while(!client.available()){
    delay(1);
   }
  
   //read the first line of the request
   String req = client. readStringUntil('\r');
   client.flush();
  
   //Match the request
   if(req.length()>10){
      if(req.indexOf("/OFF") != -1) {
        digitalWrite(ledPin,LOW);
        Serial.println("You clicked OFF");
      }

      if(req.indexOf("/ON") != -1) {
        digitalWrite(ledPin,HIGH);
        Serial.println("You clicked ON"); 
      }

      else{
        Serial.println("Invalid Request");
        client.stop();
        return;
      }

      //prepare the response
      String s = "HTTP/1.1 200 OK";
      s += "Content-Type: text/html";
      s += "<!DOCTYPE HTML><html>";
      s += "<br><input type=\"button\" value=\"Turn LED ON\" onclick=\"location.href='/ON'\">";
      s += "<br><br><br>";
      s += "<br><input type=\"button\" value=\"Turn LED OFF\" onclick=\"location.href='/OFF'\">";
      s += "</html>";

      client.flush();

      //send the response to the client
      client.print(s);
      delay(1);
  }
 }
