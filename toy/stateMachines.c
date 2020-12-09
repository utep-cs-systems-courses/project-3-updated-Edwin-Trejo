
#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <abCircle.h>
#include <shape.h>
#include "switches.h"

AbRect rect5 = {abRectGetBounds, abRectCheck, {15,15}};
AbRect rect8 = {abRectGetBounds, abRectCheck, {8,8}};
AbRect rect20 = {abRectGetBounds, abRectCheck, {20,20}};
AbRect rect1 = {abRectGetBounds, abRectCheck, {10,10}};



  

void state_init()
{

  
}

void state_advance(){
  char changed = 0;
  switch(changed){
  case 0:
    change_arrows();
    break;
  case 1:
    change_squares();
    break;
  }
}

void change_arrows(){
  char changed = 0;
}

void change_squares(){
   char changed = 0;
   
   Layer square1 ={
  (AbShape *)&rect5,
  {(screenWidth/2), screenHeight-30},
  {0,0},{0,0},
  COLOR_BLUE,
  0
  };

  Layer square2 ={
  (AbShape *)&rect8,
  {(screenWidth/2), screenHeight-30},
  {0,0},{0,0},
  COLOR_BLUE,
  &square1,
  };
  Layer square3 ={
  (AbShape *)&rect20,
  {(screenWidth/2), screenHeight-30},
  {0,0},{0,0},
  COLOR_BLUE,
  &square2,
  };
  Layer square4 ={
  (AbShape *)&rect1,
  {(screenWidth/2), screenHeight-30},
  {0,0},{0,0},
  COLOR_BLUE,
  &square3,
  };
}
