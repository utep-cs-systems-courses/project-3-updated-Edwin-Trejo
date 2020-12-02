#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <abCircle.h>
#include <shape.h>
#include "switches.h"


#define LED_GREEN BIT6             // P1.6

short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

AbRect rect10 = {abRectGetBounds, abRectCheck, {10,10}}; /*10x10 rectangle  */
AbRArrow rightArrow = {abRArrowGetBounds, abRArrowCheck, 30};

AbRectOutline fieldOutline ={                 // playing field
  abRectOutlineGetBounds, abRectOutlineCheck,
  {screenWidth/2 - 10, screenHeight/2 - 10}
};





void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 250) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_BLUE) ? COLOR_RED : COLOR_BLUE;
    redrawScreen = 1;
  }
}
  

void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_WHITE);
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      drawString5x7(10,10, "Catch every ball!", fontFgColor, COLOR_WHITE);
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}

    
    



