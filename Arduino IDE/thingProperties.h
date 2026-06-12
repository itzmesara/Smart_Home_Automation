#include <ArduinoIoTCloud.h> 
#include <ArduinoConnectionHandler.h> 

const char THING_ID[]           = "*********************";  //Enter THING ID 
const char DEVICE_LOGIN_NAME[]  = "********************"; //Enter DEVICE ID 

const char SSID[]               = SECRET_SSID;  // Network SSID (name)
const char PASS[]               = SECRET_PASS;    // Network password (use for WPA, or use as key for 
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password 


//Switch toggle
void onSwitch1Change(); 
void onSwitch2Change(); 

//Arduino Variables
CloudSwitch light1; 
CloudSwitch light2; 

void initProperties(){ 

    ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME); 
    ArduinoCloud.setSecretDeviceKey(DEVICE_KEY); 
    ArduinoCloud.setThingId(THING_ID); 
    ArduinoCloud.addProperty(light1, READWRITE, ON_CHANGE, onSwitch1Change); 
    ArduinoCloud.addProperty(light2, READWRITE, ON_CHANGE, onSwitch2Change); 

} 

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
