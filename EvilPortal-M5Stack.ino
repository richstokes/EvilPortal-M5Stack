#include <M5CoreS3.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <DNSServer.h>
#include <ESPAsyncWebSrv.h> // https://forum.arduino.cc/t/espasyncwebserver-h-no-such-file-or-directory-error-even-after-installing-espasyncwebsrv-library/1145099
#include "handler.h"

// Configure the name of the access point
// const char *ssid = "Starbucks";
const char *ssid = "Google Wireless";

// Configure IP address settings
IPAddress local_IP(192, 168, 69, 1);
IPAddress gateway(192, 168, 69, 1);
IPAddress subnet(255, 255, 255, 0);

DNSServer dnsServer;
AsyncWebServer server(80);

void setup()
{
  M5.begin();
  M5.lcd.setTextSize(2);
  M5.lcd.println(
      "Wifi Access Point:");
  M5.lcd.printf("%s \n", ssid);

  // Start the AP
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(
      ssid);
  IPAddress myIP = WiFi.softAPIP();
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);
  server.begin();

  // Start the DNS server
  dnsServer.start(53, "*", WiFi.softAPIP());

  Serial.println("Ready!");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
  dnsServer.processNextRequest();
}
