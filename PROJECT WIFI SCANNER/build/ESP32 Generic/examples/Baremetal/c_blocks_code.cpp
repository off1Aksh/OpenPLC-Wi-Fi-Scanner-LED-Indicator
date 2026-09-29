#include <stdint.h>

#ifdef ARDUINO
#include <Arduino.h>
#endif

/*********************/
/*  IEC Types defs   */
/*********************/

typedef uint8_t  IEC_BOOL;

typedef int8_t    IEC_SINT;
typedef int16_t   IEC_INT;
typedef int32_t   IEC_DINT;
typedef int64_t   IEC_LINT;

typedef uint8_t    IEC_USINT;
typedef uint16_t   IEC_UINT;
typedef uint32_t   IEC_UDINT;
typedef uint64_t   IEC_ULINT;

typedef uint8_t    IEC_BYTE;
typedef uint16_t   IEC_WORD;
typedef uint32_t   IEC_DWORD;
typedef uint64_t   IEC_LWORD;

typedef float    IEC_REAL;
typedef double   IEC_LREAL;

#ifndef STR_MAX_LEN
#define STR_MAX_LEN 126
#endif

#ifndef STR_LEN_TYPE
#define STR_LEN_TYPE int8_t
#endif

typedef STR_LEN_TYPE __strlen_t;
typedef struct {
    __strlen_t len;
    uint8_t body[STR_MAX_LEN];
} IEC_STRING;

//definition of external blocks - WIFI_SCANNER
typedef struct {
} WIFI_SCANNER_VARS;

extern "C" void wifi_scanner_setup(WIFI_SCANNER_VARS *vars);
extern "C" void wifi_scanner_loop(WIFI_SCANNER_VARS *vars);


#include <WiFi.h>

unsigned long lastScanTime = 0;
const unsigned long scanInterval = 5000;

void wifi_scanner_setup(WIFI_SCANNER_VARS *vars) {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true, true);
    
    delay(100);

    Serial.println("Mulai WiFi scanner (OpenPLC Mode)...");
    WiFi.scanNetworks(true);
    lastScanTime = millis();
}

void wifi_scanner_loop(WIFI_SCANNER_VARS *vars) {
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
