#include <ESP8266WiFi.h>
#include <Servo.h>

WiFiServer server(80);
IPAddress ip(192, 168, 1, 10);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

//const char* ssid = "VTR-0749855";
//const char* password = "mz7dhSghVfg7";

const char* ssid = "Familia Soto";
const char* password = "Marlyn0421";
Servo servoMotor;

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
  Serial.println(WiFi.localIP());

  //pinMode(4, OUTPUT);//D2
  servoMotor.attach(4);
  //digitalWrite(4, LOW);






}
void loop() {

 WiFiClient client = server.available();
  if (!client) {
    return;
  }
  

 if(Serial.println(client.readStringUntil('$')=(op))){
  String x = "Encendido";
  client.println(x);
   servoMotor.write(180);

   //digitalWrite(4, HIGH);
  client.flush();
  }
 delay(2000);
 
  if(Serial.println(client.readStringUntil('$')=(cl))){
  String x = "Apagado";
  client.println(x);
   servoMotor.write(-180);

   //digitalWrite(4, LOW);
  client.flush();

  }

 
  }
