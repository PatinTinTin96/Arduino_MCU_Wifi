#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

ESP8266WebServer server(80); // 80 is the port number
Servo servoMotor;

const char* ssid = "Familia Soto";
const char* password = "Marlyn0421";

const char* op = "on";
const char* cl = "off";

//const char* ssid = "Familia Aguilar";
//const char* password = "271386749lol";

//const char* ssid = "VTR-0749855";
//const char* password = "mz7dhSghVfg7";

//const char* ssid = "PatinTinTin";
//const char* password = "campanita";

String servoon,servooff;

void Redon()
{
    servoMotor.write(180);
  server.send(200, "text/html", servoon);
}

void Redoff()
{
   servoMotor.write(0);
  server.send(200, "text/html", servooff);
}


void setup() {

  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)delay(500);

  Serial.print(WiFi.localIP());



  server.on(op, Redon);
  server.on(cl, Redoff);


  server.begin();

  servoMotor.attach(4);
  //pinMode(4, OUTPUT);//D2
  //digitalWrite(4, LOW);

}

void loop()
{
  server.handleClient();
  delay(1);
}
