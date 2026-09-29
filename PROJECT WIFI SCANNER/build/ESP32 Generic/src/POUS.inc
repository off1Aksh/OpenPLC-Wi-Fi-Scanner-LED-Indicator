#include "POUS.h"
#include "Config0.h"

void WIFI_SCANNER_init__(WIFI_SCANNER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->HASBEENINITIALIZED,0,retain)
}

// Code part
void WIFI_SCANNER_body__(WIFI_SCANNER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

  WIFI_SCANNER_VARS vars;
  
  #undef GetFbVar
  #undef SetFbVar
;
  if ((__GET_VAR(data__->HASBEENINITIALIZED,) == __BOOL_LITERAL(FALSE))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

  wifi_scanner_setup(&vars);
  
    #undef GetFbVar
    #undef SetFbVar
;
    __SET_VAR(data__->,HASBEENINITIALIZED,,__BOOL_LITERAL(TRUE));
  };
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

  wifi_scanner_loop(&vars);
  
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // WIFI_SCANNER_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->WAKTU_BLINK,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  TON_init__(&data__->TIMER1,retain);
  TON_init__(&data__->TIMER2,retain);
  WIFI_SCANNER_init__(&data__->WIFI_SCANNER1,retain);
  __INIT_LOCATED(BOOL,__QX0_0,data__->LED_OUT,retain)
  __INIT_LOCATED_VALUE(data__->LED_OUT,__BOOL_LITERAL(FALSE))
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TIMER1.,IN,,!(__GET_VAR(data__->TIMER2.Q,)));
  __SET_VAR(data__->TIMER1.,PT,,__GET_VAR(data__->WAKTU_BLINK,));
  TON_body__(&data__->TIMER1);
  __SET_VAR(data__->TIMER2.,IN,,__GET_VAR(data__->TIMER1.Q,));
  __SET_VAR(data__->TIMER2.,PT,,__GET_VAR(data__->WAKTU_BLINK,));
  TON_body__(&data__->TIMER2);
  __SET_LOCATED(data__->,LED_OUT,,__GET_VAR(data__->TIMER1.Q,));
  __SET_VAR(data__->WIFI_SCANNER1.,EN,,__BOOL_LITERAL(TRUE));
  WIFI_SCANNER_body__(&data__->WIFI_SCANNER1);

  goto __end;

__end:
  return;
} // MAIN_body__() 





