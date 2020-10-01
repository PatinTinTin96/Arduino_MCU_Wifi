#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

ESP8266WebServer server(80); // 80 is the port number

//const char* ssid = "VTR-4382214";
//const char* password = "ft8Phhrrw8mx";

//const char* ssid = "Familia Aguilar";
//const char* password = "271386749lol";

const char* ssid = "VTR-0749855";
const char* password = "mz7dhSghVfg7";

String ledon,ledoff,led1on,led1off;

void Redon()
{
  digitalWrite(4, HIGH);
  server.send(200, "text/html", ledon);
}

void Redoff()
{
  digitalWrite(4, LOW);
  server.send(200, "text/html", ledoff);
}


void setup() {

  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)delay(500);

  Serial.print(WiFi.localIP());

  server.on("/led1on", Redon);
  server.on("/led1off", Redoff);


  server.begin();


  pinMode(4, OUTPUT);//D2


  digitalWrite(4, LOW);

}

void loop()
{
  server.handleClient();
  delay(1);
}
