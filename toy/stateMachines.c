#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include "stateMachines.h"

void state_init()
{
  led_state = 0;
  
}

void state_advance(){
  static char state = 0;
  switch(state){
  case 0:
    
    
  }
}
