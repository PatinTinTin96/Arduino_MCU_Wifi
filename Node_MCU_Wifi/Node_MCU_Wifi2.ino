#include <ESP8266WiFi.h>

WiFiServer server(80);
IPAddress ip(192, 168, 0, 10);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

const char* ssid = "VTR-4382214";
const char* password = "ft8Phhrrw8mx";

const char* op = "on";
const char* cl = "off";
void setup() {
  Serial.begin(9600);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  server.begin();
  Serial.println("Connected");
  Serial.print(WiFi.localIP());
  
  pinMode(4, OUTPUT);//D2


  digitalWrite(4, LOW);




  

}
void loop() {
  
 WiFiClient client = server.available();
  if (!client) {
    return;
  }
  if(Serial.println(client.readStringUntil('$')=(op))){  
  String x = "Encendido";
  client.println(x);
   digitalWrite(4, HIGH);
  client.flush();
  }
  if(Serial.println(client.readStringUntil('$')=(cl))){  
  String x = "Apagado";
  client.println(x);
   digitalWrite(4, LOW);
  client.flush();

  }
  }
  
