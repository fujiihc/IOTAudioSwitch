#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "Your Arduino Device ID Here";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onChannelChange();
void onAudioChannel1Change();
void onAudioChannel2Change();
void onAudioChannel3Change();
void onAudioChannel4Change();

int channel;
CloudSwitch audioChannel1;
CloudSwitch audioChannel2;
CloudSwitch audioChannel3;
CloudSwitch audioChannel4;

void initProperties(){
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(channel, READWRITE, ON_CHANGE, onChannelChange);
  ArduinoCloud.addProperty(audioChannel1, READWRITE, ON_CHANGE, onAudioChannel1Change);
  ArduinoCloud.addProperty(audioChannel2, READWRITE, ON_CHANGE, onAudioChannel2Change);
  ArduinoCloud.addProperty(audioChannel3, READWRITE, ON_CHANGE, onAudioChannel3Change);
  ArduinoCloud.addProperty(audioChannel4, READWRITE, ON_CHANGE, onAudioChannel4Change);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
