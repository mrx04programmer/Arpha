#include <Keyboard.h>
#include <EEPROM.h>
char stringArray[500] = {""};
boolean extracted = false, dispatched = false;
int extractButton = 2, dispatchButton = 3;

void setup() {
    Serial.begin(9600);
    pinMode(extractButton, INPUT);
    //pinMode(dispatchButton, INPUT);
    Keyboard.begin();
}
void loop() {
    if(digitalRead(extractButton) == HIGH && !extracted) {
        run();
        extracted = true;
    }
    }    
    if(digitalRead(extractButton) == LOW)
        extracted = false;
    //if(digitalRead(dispatchButton) == LOW)
        //dispatched = false;
}

void run() {
    Keyboard.press(KEY_LEFT_GUI, 'r');
    Keyboard.release(KEY_LEFT_GUI, 'r');
    Keyboard.print("powershell.exe");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.print("ItemProperty -Path HKLM:\SYSTEM\CurrentControlSet\Enum\USBSTOR\*\* > output.txt | Select FriendlyName >> output.txt ");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);

    for(int i=0; i<sizeof(stringArray)-1; i++)
        stringArray[i] = Serial.read();
    EEPROM.put(1, stringArray);
}
