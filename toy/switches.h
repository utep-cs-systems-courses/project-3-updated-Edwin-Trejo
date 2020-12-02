#ifndef switches_included
#define switches_included

#define SW1 BIT3
#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3

#define SWITCHES SW1
#define P2_SWITCHES (S1 | S2 | S3 | S4)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed;
#endif

