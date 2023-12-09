#include <M5CoreS3.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <DNSServer.h>
#include <ESPAsyncWebSrv.h> // https://forum.arduino.cc/t/espasyncwebserver-h-no-such-file-or-directory-error-even-after-installing-espasyncwebsrv-library/1145099
#include "handler.h"

// Configure the name of the access point
const char *ssid = "Starbucks";

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
  WiFi.softAP(
      ssid);
  IPAddress myIP = WiFi.softAPIP();
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);
  server.begin();

  // Start the DNS server
  dnsServer.start(53, "*", WiFi.softAPIP());
}

void loop()
{
  dnsServer.processNextRequest();
}
