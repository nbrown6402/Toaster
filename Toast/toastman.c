#include <stdio.h>                        		 /* std i/o library */
#include <time.h>                             		 /* library for delay() */
#include <windows.h>                             	 /* needed for Sleep() function */
#include <conio.h>                            		 /* needed for kbhit()/getch() */       
/* ***************** THE ABOVE INCLUDES MUST REMAIN *********************** */
/* ************************************************************************ */

    #include "mrbread.c"                            	/* add your includes here*/
     #include "ban.c"



/* ************************************************************************ */
/* ************************************************************************ */
/*                                                                          */
/* program: toastman.c							    */
/* programmer: Nicole Brown						    */
/* due date: 12/10/21							    */
/*							           	    */
/* purpose:To toast bread or bagels duh...  				    */
/*									    */
/* inputs: A button "push"						    */
/* outputs:text, ascii art, toasted bread or bagel			    */
/*									    */
/* notes: none                                                              */
/*                                                                          */
/* ************************************************************************ */
/* ************************************************************************ */



/* ************************************************************************ */
/* ******************** THE ITEMS BELOW MUST REMAIN *********************** */
#define PORT "COM6"                            /* define the COM port       */
                                               /* remember to check device  */
                                               /* manager for port number   */
#ifdef REAL
   #include "serialdrv.h"                      /* serial port header file   */
   #include "serialdrv.c"                      /* serial port support code  */
   #include "toastdrv.c"                       /* toaster sim functions     */
#else
   #include "serialsim.h"                      /* serial port header file   */
   #include "serialsim.c"                      /* serial port support code  */
   #include "toastsim.c"                       /* toaster sim functions     */
#endif
/* ******************** THE ITEMS ABOVE MUST REMAIN *********************** */
/* ************************************************************************ */


int main(){
	//creates a character array that will eventually display
	//Mr. Toastyman
	
	char toasty[50][100] = {"\n  _   __ \n ( `^` )) \n |.  . || \n |  -  || \n '-----'` \n", };
	char user_input = 0;								//initializes the users input as 0 until the user enters a value
	cancel();									//wakes the toaster up
	int k=4;									//initializes the original darkness level to 4
											//creates a character array that will eventually display the menu
	char banner_data [11][100] = {"Welcome to the legend of Mr. Toastyman",
				        "and Mr. Bagelman",
				        "  ",
				        "Please Enter what you would like to do: ",
					"T for Toast ",
					"C for Cancel",
					"B for Bagel ",
					"R to Reheat ",
					"D to Defrost",
					"1-7 for Darkness Level",
					"S for the story of Mr. Toastyman and Mr. Bagelman " };
							
while(user_input !='x'){ 						//runs the code below until 'x' is entered
banner_filled(42, 56, 2 , 8, 11, banner_data);				//displays the menu
printf("The current darkness level is %d/7",k);				//displays the current darkness setting
printf("\nPlease enter an option: "); 					//prompts the user to enter an option
scanf("%s",&user_input); 						//scans the users input 

	
//when T is entered the toaster will toast, the text and ascii art will appear on screen, the progress bar will run, and the number
//of total pieces or toast/bagels toasted will increase by one.
if (user_input=='T') {toast(); printf("This is Mr. Toastyman say hello!\n");banner_string(0, 100, 0, toasty[0]); progresst(k);how(); }

//when C is entered the action the toaster is preforming will be stopped and the tray will raise
if (user_input=='C') {cancel(); k=0;}

//when + is entered the darkness level will increase by one and the timing of the progress bar will increase by one. If 7 is the current
//darkness level and + is entered the darkness level will go back to 1.
if (user_input=='+') {plus(); k=k+1; if (k==8) k=1;}

//when - is entered the darkness level will decrease by one and the timing of the progress bar will decrease by one. If 1 is the current
//darkness leven and - is entered the darkness level will go to 7.
if (user_input=='-') {minus(); k=k-1; if(k==0) k=7;}

//when B is entered the bagel mode will be toggeled, the toaster will then toast, the text and ascii art will appear on screen, the 
//progress bar will run, and the number of total pieces of toast/bagels toasted will increase by one.
if (user_input=='B') {bagel(); Sleep(1000); toast(); printf("This is Mr. Bagelman say hello! \n" );
 bread();progressb(k);how();}
 
//when R is entered the toaster will reheat whatever was put into the toaster, the text and asciii art will appear on screen, and the 
//progress bar will run
if (user_input=='R'){ reheat(); printf("In their free time MR.Toastyman and Mr. Bagelman like to sit around the fire. \n");
fire();progressr();}

//when D is entered the toaster will defrost whatever was put into the toaster, the text and ascii are will appear on screen, and the
//progress bar will run
if (user_input=='D'){ defrost(); printf("One time Mr. ToastyMan and Mr. Bagelman had to save the townspeople from overtoasting the people.\n"); 
dragon();progressd(k);}

//when a number 1-7 is entered the darkness leve will change to the inputted level and change the progressbar time accordingly
if (user_input>='1' && user_input<='7') {set_darkness(user_input-48); k=(user_input-48);}

//when S is entered the story of Mr. Toastyman and Mr. Bagelman will appear on screen
if (user_input=='S') story();

printf("\n");



}
return 0; 
}




