#include<time.h>

/* ************************************************************************ */
/*                                                                          */
/* function library toastsim.c                                              */
/*                                                                          */
/* purpose: toaster operation simulator.  will be replaced with actual      */
/*          toater control drivers/functions.                               */
/*                                                                          */
/*                                                                          */
/* function list:                                                           */
/*          toast() activates toast operation                               */
/*          cancel() activates cancels operation/wakes up toaster           */
/*          plus() increments darkness (no memory)                          */
/*          minus() decrements darkness (no memory)                         */
/*          bagel() toggles bagel mode on toaster(no memory)                */
/*          reheat() toggles reheat mode on toaster (no memory)             */
/*          defrost() toggles defrost mode on toaster (no memory)           */
/*          set_darkness(int darkness) sets darkness                        */
/*                                                                          */
/* ************************************************************************ */

/* subfunction declarations                                                 */
void delay(int number_of_seconds); 
int putcharsX(char chartype, int numchars); /* used for toaster sim messages */



/* ************************************************************************ */
/* function toast() activates toast operation                               */
/* ************************************************************************ */
int toast(void)
{
    putcharsX(42, 15); printf("  TRAY LOWERING  "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay while lower  */
    putcharsX(42, 15); printf("     TOASTING    "); putcharsX(42, 15); putcharsX(10, 1);
    delay(4);                                      /* delay while toast  */
    putcharsX(42, 15); printf("  TRAY RAISING   "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function cancel() activates cancels operation/wakes up toaster           */
/* ************************************************************************ */
int cancel(void)
{

    putcharsX(10, 1);                                /* print CR and message */
    putcharsX(42, 15); printf("    CANCELLED    "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/
    putcharsX(42, 15); printf("  TRAY RAISING   "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function plus() increments darkness (no memory)                          */
/* ************************************************************************ */
int plus(void)
{
    putcharsX(10, 1);                              /* print CR and message */
    putcharsX(42, 15); printf("  +++++ PRESSED  "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function minus() decrements darkness (no memory)                         */
/* ************************************************************************ */
int minus(void)
{
    putcharsX(10, 1);                              /* print CR and message */
    putcharsX(42, 15); printf("  ----- PRESSED  "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function bagel() toggles bagel mode on toaster(no memory)                */
/* ************************************************************************ */
int bagel(void)
{
    putcharsX(10, 1);                               /* print CR and message */
    putcharsX(42, 15); printf("  BAGEL TOGGLED  "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function reheat() toggles reheat mode on toaster (no memory)             */
/* ************************************************************************ */
int reheat(void)
{
    putcharsX(10, 1);                              /* print CR and message */
    putcharsX(42, 15); printf(" REHEAT  TOGGLED "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function defrost() toggles defrost mode on toaster (no memory)           */
/* ************************************************************************ */
int defrost(void)
{
    putcharsX(10, 1);                              /* print CR and message */
    putcharsX(42, 15); printf(" DEFROST TOGGLED "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;
}

/* ************************************************************************ */
/* function set_darkness(int darkness) sets darkness                        */
/* ************************************************************************ */
int set_darkness(int darkness)
{
    putcharsX(42, 15); printf(" CHANGING DARK "); putcharsX(42, 15); putcharsX(10, 1);
    delay(8);                   /* delay while toasting and print message*/
    putcharsX(42, 15); printf(" DARK  CHANGED "); putcharsX(42, 15); putcharsX(10, 1);
    delay(2);                                      /* delay after message*/

    return 0;

}

/* ************************************************************************ */											   
/* function delay(seconds) used for set_darkness()                          */
/* ************************************************************************ */											   
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 


/* ************************************************************************ */
/* function putcharsX(chartype, numchars) print numchars chars (chartype)    */
/* ************************************************************************ */
int putcharsX(char chartype, int numchars) {
    for(int i=0; i<numchars; i++) printf("%c", chartype);
    return 0;
}