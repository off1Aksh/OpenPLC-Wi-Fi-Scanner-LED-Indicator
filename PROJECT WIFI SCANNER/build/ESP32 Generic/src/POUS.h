#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// FUNCTION_BLOCK WIFI_SCANNER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,HASBEENINITIALIZED)

} WIFI_SCANNER;

void WIFI_SCANNER_init__(WIFI_SCANNER *data__, BOOL retain);
// Code part
void WIFI_SCANNER_body__(WIFI_SCANNER *data__);
// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,WAKTU_BLINK)
  TON TIMER1;
  TON TIMER2;
  WIFI_SCANNER WIFI_SCANNER1;
  __DECLARE_LOCATED(BOOL,LED_OUT)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
