#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

static char
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  char p2val = P2IN;

  P1IES |= (p1val & SWITCHES); 
  P2IES |= (p2val & P2_SWITCHES);
  P1IES &= (p1val | ~SWITCHES);
  P2IES &= (p2val | ~P2_SWITCHES);
  return p1val;
  
}

void
switch_init()
{
  P1REN |= SWITCHES;    //enables resistors
  P2REN |= P2_SWITCHES;
  
  P1IE |= SWITCHES;     //enables interrupts
  P2IE |= P2_SWITCHES;
  
  P1OUT |= SWITCHES;    //enables pull-ups
  P2OUT |= P2_SWITCHES;
  
  P1DIR &= ~SWITCHES;   
  P2DIR &= ~P2_SWITCHES;

  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1;
  switch_state_changed = 1;
}
