#ifndef C_BLOCKS_H
#define C_BLOCKS_H

//definition of external blocks - WIFI_SCANNER
typedef struct {
} WIFI_SCANNER_VARS;
void wifi_scanner_setup(WIFI_SCANNER_VARS *vars);
void wifi_scanner_loop(WIFI_SCANNER_VARS *vars);

#endif // C_BLOCKS_H
