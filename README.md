"Evil" Access Point / Captive Portal implementation for the [M5Stack CoreS3](https://www.amazon.com/gp/product/B0C7G5GPGC/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1).  The M5 is nicely suited to this as it has a battery built in.

For educational purposes only :-)

&nbsp;

## How to use / how it works

1. Change the `ssid` to whatever access point name you want to pretend to be
1. Change the contents of `html.h` to resemble the login screen for the service you wish to phish
1. Once someone connects to the AP and submits their credentials, they will be displayed on the screen and echo'd to the serial port.

It would be pretty easy to modify this to store to an SD card or something similar if you wanted to let it run for a long time.


&nbsp;

## Libraries:
- https://github.com/dvarrel/ESPAsyncWebSrv



