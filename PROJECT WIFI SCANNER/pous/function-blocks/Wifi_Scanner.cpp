FUNCTION_BLOCK Wifi_Scanner
VAR
END_VAR
#include <WiFi.h>

unsigned long lastScanTime = 0;
const unsigned long scanInterval = 5000;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true, true);
    
    delay(100);

    Serial.println("Mulai WiFi scanner (OpenPLC Mode)...");
    WiFi.scanNetworks(true);
    lastScanTime = millis();
}

void loop() {
    int scanResult = WiFi.scanComplete();

    if (scanResult > 0) {
        Serial.printf("\n--- Ditemukan %d jaringan ---\n", scanResult);

        for (int i = 0; i < scanResult; i++) {
            Serial.printf(
                "%d. SSID: %s | RSSI: %d dBm | Channel: %d\n",
                i + 1,
                WiFi.SSID(i).c_str(),
                WiFi.RSSI(i),
                WiFi.channel(i)
            );
        }

        WiFi.scanDelete(); 
        lastScanTime = millis();
    } 
    else if (scanResult == 0) {
        Serial.println("\nTidak ada jaringan ditemukan");
        WiFi.scanDelete();
        lastScanTime = millis();
    }

    if ((millis() - lastScanTime >= scanInterval) && (WiFi.scanComplete() != WIFI_SCAN_RUNNING)) {
        Serial.println("\nMemulai scan baru...");
        WiFi.scanNetworks(true); 
        lastScanTime = millis();
    }
}

END_FUNCTION_BLOCK