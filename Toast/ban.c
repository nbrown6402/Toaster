#include <stdio.h>
#include <windows.h>   

int banner_string(char chartype, int frame_width, int border_width, char disp_string[50]);
int banner_spaces(char chartype, int frame_width, int border_width, int space_count);
int banner_topbot(char chartype, int frame_width, int border_width);
int putchars(char chartype, int numchars);
int string_len(char instring[50]);
int banner_filled(char chartype, int frame_width, int border_width, 
                           int frame_height, int string_count, char disp_strings[11][100]);

int progress(int time);


/* ************************************************************************************ */
/* 																						*/
/* title: banner_topbot(char chartype, int frame_width, int border_width) 				*/
/* 																						*/
/* arguments: chartype (char) - ASCII code of character used for border 				*/
/* frame_width (int) - overall width of the frame in characters 						*/
/* border_width (int) - width of the border surrounding the text 						*/
/* 																						*/
/* purpose: 																			*/
/* this function generates a multiple banner lines with defined border character. 		*/
/* error checking is performed. 														*/
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 on success, 1 on failure 											*/
/* 																						*/
/* failure rules: 1) frame width must be even 											*/
/* 																						*/
/* ************************************************************************************ */

int banner_topbot(char chartype, int frame_width, int border_width) {

if(frame_width % 2 != 0) { 												// check for even frame width
printf("Error: Frame width must be even\n");
return 1;
}
for(int j=0; j<border_width; j++) {
putchars(chartype, border_width); 										// print border
putchars(chartype,(frame_width-(2*border_width))); 						// print inner frame
putchars(chartype, border_width); 										// print border
printf("\n");
}
return 0;
}


/* ************************************************************************************ */
/* 																						*/
/* title: banner_spaces(char chartype, int frame_width, int border_width, 				*/
/* int space_count) 																	*/
/* 																						*/
/* arguments: chartype (char) - ASCII code of character used for border 				*/
/* frame_width (int) - overall width of the frame in characters 						*/
/* border_width (int) - width of the border surrounding the text 						*/
/* space_count (int) - number of border spaces (lines) to be displayed 					*/
/* 																						*/
/* purpose: 																			*/
/* this function generates a multiple banner line with a spaces centered between a 		*/
/* defined border. error checking is performed. 										*/
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 on success, 1 on failure											*/
/* 																						*/
/* failure rules: 1) frame width must be even 											*/
/* 2) frame width - (2 x border width) must be >= 10 									*/
/*																						 */
/* ************************************************************************************ */
int banner_spaces(char chartype, int frame_width, int border_width, int space_count) {
if (frame_width%2==0){ 																	/* check for even frame width*/
if (frame_width - (2 * border_width)>= 10 ){ 											/* check for frame/border
																							ratio*/
for(int count = 0;count <space_count; count++ ){ 										/*FOR a given number of
																						  border spaces (lines)*/
putchars(chartype, border_width); 														//call of the function putchars to print the left border
putchars(32, frame_width - (2 * border_width)); 										//call of the function putchars to print middle banner line
																						// with spaces characters centered. Notice that the decimal ASCII 
																						//number 32 represent <SPACE>.
putchars(chartype, border_width); 														//call of the function putchars to print the right border
printf("\n");
}
}
return 0;
}
else
return 1;
}




/* ************************************************************************************ */
/*																					    */
/* Date: 11/10/2021 																	*/
/* title: banner_string(char chartype, int frame_width, int border_width, 				*/
/* char disp_string[50])																*/
/* 																						*/
/* arguments: chartype (char) - ASCII code of character used for border 				*/
/* frame_width (int) - overall width of the frame in characters 						*/
/* border_width (int) - width of the border surrounding the text 						*/
/* disp_string (char) - string to be displayed 											*/
/* 																						*/
/* purpose: 																			*/
/* this function generates a single banner line with a string centered between a 		*/
/* defined border. error checking is performed. 										*/
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 on success, 1 on failure 											*/
/* 																						*/
/* failure rules: 1) frame width must be even 											*/
/* 2) frame width - (2 x border width) must be >= 10 									*/
/* 3) there much be at least one space on each side of a string						 	*/
/* before a border character 															*/
/* 																						*/
/* ************************************************************************************ */
int banner_string(char chartype, int frame_width, int border_width, char disp_string[50]) {
int space_width = ((frame_width - (2 * border_width) - string_len(disp_string)) / 2);
																		/* Calculates the amount of spaces needed.*/
if ((frame_width % 2) == 0){ 											/* Checks if frame_width is an even number*/
if (frame_width - (2 * border_width) >= 10){

																		/* Checks if the frame width is large enough*/
if (space_width >= 1){ 													/* Checks if the space width is greater than 0*/
putchars(chartype, border_width);
putchars(32, space_width); 												/* Uses putchars to print symbols*/
printf("%s", disp_string);												 /* 32 is the ascii code for space*/
putchars(32, space_width);
putchars(chartype, border_width);
printf("\n");
return 0;
}
else{
printf("Error: frame_width is too small or border_width is too large!\n");
return 1;
}
}
else{
printf("Error: frame_width must be greater than 10 + 2 * border_width!\n");
return 1;
}
}
else{
printf("Error: frame_width must be even\n");
return 1;
}
}


/* ************************************************************************************ */
/* */
/* title: string_len(char instring[50]) */
/* */
/* arguments: instring (char) - null terminated string to be evaluated for */
/* length (note max) */
/* */
/* purpose: */
/* this function calculates and returns the length of a null terminated string. */
/* */
/* function (return) type: int */
/* */
/* return values: string length */
/* */
/* ************************************************************************************ */
int string_len(char instring[50]) {
int i;
for(i = 0; i < 50; i++){ /* write your own string */
if(instring[i] == '\0'){ /* length routine. no library */
break; /* call! */
}
}
return i;
}




/* ************************************************************************************ */
/* 																						*/
/* title: putchars(char chartype, int numchars) 										*/
/* date:11/11/2021 																		*/
/* arguments: chartype (char) - ASCII code of character used for border 				*/
/* numchars (int) - number of characters to be printed								 	*/
/* 																						*/
/* purpose: 																			*/
/* This function repeatedly prints the specified character to the screen. no error 		*/
/* checking is performed. 																*/
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 always 																*/
/* 																						*/
/* ************************************************************************************ */
int putchars(char chartype, int numchars) {
for(int i=0; i<numchars; i++) 						/* print the banner chars */
printf("%c", chartype); 							/* using calls to printf() */
return 0;
}



/* ************************************************************************************ */
/* 																						*/
/* title: banner_filled(char chartype, int frame_width, int border_width, 				*/
/* int frame_height, int string_count, char disp_strings[10][100]) 						*/
/* 																						*/
/* arguments: chartype (char) - ASCII code of character used for border 				*/
/* frame_width (int) - overall width of the frame in characters 						*/
/* border_width (int) - width of the border surrounding the text 						*/
/* frame_height (int) - overall height of the frame in console lines 					*/
/* string_count (int) - number of strings being passed (note: max = 5)					*/
/* disp_strings (char) - string array (note: max sizes) 								*/
/* 																						*/
/* purpose: 																			*/
/* this function uses subfunctions to create a complete banner. error checking is		*/
/* performed. 																			*/
/*																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 on success, 1 on failure 											*/
/* 																						*/
/* failure rules: 1) frame width must be even 											*/
/* 2) frame width - (2 x border width) must be > 10 									*/
/* 3) there much be at least one space on each side of a string 						*/
/* before a border character												 			*/
/* 																						*/
/* ************************************************************************************ */
int banner_filled(char chartype, int frame_width, int border_width, int frame_height,
int string_count, char disp_strings[11][100]) {
if ((frame_width%2 == 0) && (frame_width > 10)) {		 /* check for even frame width and length of width */
banner_topbot(chartype, frame_width, border_width);
banner_spaces(chartype, frame_width, border_width, (frame_height-string_count-2*border_width));
banner_spaces(chartype, frame_width, border_width, (frame_height-string_count-2*border_width));
for (int h=0; h<string_count; h++) {
banner_string(chartype, frame_width, border_width, disp_strings[h]);
}
banner_spaces(chartype, frame_width, border_width, (frame_height-string_count-2*border_width));
banner_spaces(chartype, frame_width, border_width, (frame_height-string_count-2*border_width));
banner_topbot(chartype, frame_width, border_width);
}
}


/* ************************************************************************************ */
/* 																						*/
/* title: progresst(int time)					 										*/
/* date:12/08/2021 																		*/
/* arguments: time (int) - second delay for Sleep() library function				    */
/* 																						*/
/* purpose: 																			*/
/* This function repeatedly prints the specified character to th screen with a delay 	*/
/* between each character. This function is also allowed to be interupted when another  */
/* character is entered. This function is only used with Toast() functions  			*/											
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 always 																*/
/* 																						*/
/* ************************************************************************************ */
int progresst(int time){
	 int keyPress;
    char userin=0;
	
    for (int i=0; i<35+(20*time); i++) {                     /* print out progress bar      */
		printf("%c", 42); 
		Sleep(1000);

        keyPress = kbhit(); if (keyPress != 0) { userin=getch(); break; }
		                                           /* if keyhit, grab char, bail  */	

	}
	
	
   return 0;                                       /* return 0 on exit            */
}

/* ************************************************************************************ */
/* 																						*/
/* title: progressb(int time)					 										*/
/* date:12/08/2021 																		*/
/* arguments: time (int) - second delay for Sleep() library function				    */
/* 																						*/
/* purpose: 																			*/
/* This function repeatedly prints the specified character to th screen with a delay 	*/
/* between each character. This function is also allowed to be interupted when another  */
/* character is entered. This function is only used with Bagel() functions  			*/												
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 always 																*/
/* 																						*/
/* ************************************************************************************ */
int progressb(int time){
	 int keyPress;
    char userin=0;
	
    for (int i=0; i<45+(20*time); i++) {                     /* print out progress bar      */
		printf("%c", 42); 
		Sleep(1000);

        keyPress = kbhit(); if (keyPress != 0) { userin=getch(); break; }
		                                           /* if keyhit, grab char, bail  */	

	}
	
	
   return 0;                                       /* return 0 on exit            */
} 

/* ************************************************************************************ */
/* 																						*/
/* title: progressd(int time)					 										*/
/* date:12/08/2021 																		*/
/* arguments: none																	    */
/* 																						*/
/* purpose: 																			*/
/* This function repeatedly prints the specified character to th screen with a delay 	*/
/* between each character. This function is also allowed to be interupted when another  */
/* character is entered. This function is only used with Defrost() functions  			*/												
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 always 																*/
/* 																						*/
/* ************************************************************************************ */
int progressd(int time){
	 int keyPress;
    char userin=0;
	
    for (int i=0; i<60+(20*time); i++) {                     /* print out progress bar      */
		printf("%c", 42); 
		Sleep(1000);

        keyPress = kbhit(); if (keyPress != 0) { userin=getch(); break; }
		                                           /* if keyhit, grab char, bail  */	

	}
	
	
   return 0;                                       /* return 0 on exit            */
} 

/* ************************************************************************************ */
/* 																						*/
/* title: progressr()					 												*/
/* date:12/08/2021 																		*/
/* arguments: time (int) - second delay for Sleep() library function				    */
/* 																						*/
/* purpose: 																			*/
/* This function repeatedly prints the specified character to th screen with a delay 	*/
/* between each character. This function is also allowed to be interupted when another  */
/* character is entered. This function is only used with Reheat() functions  			*/												
/* 																						*/
/* function (return) type: int 															*/
/* 																						*/
/* return values: 0 always 																*/
/* 																						*/
/* ************************************************************************************ */
int progressr(){
	 int keyPress;
    char userin=0;
	
    for (int i=0; i<30; i++) {                     /* print out progress bar      */
		printf("%c", 42); 
		Sleep(1000);

        keyPress = kbhit(); if (keyPress != 0) { userin=getch(); break; }
		                                           /* if keyhit, grab char, bail  */	

	}
	
	
   return 0;                                       /* return 0 on exit            */
} 


/* ************************************************************************************ */
/* 																						*/
/* title: how()					 										 				*/
/* date:12/08/2021 																		*/
/* arguments: none 																	    */
/* 																						*/
/* purpose: 																			*/
/* This function adds one everytime the program is run. This function is only used to   */
/* count the number of total bagels and piece of toast toasted 							*/
/* 																						*/
/* function (return) type: file 													    */
/* 																						*/
/* return values: 0 always 																*/
/* 																						*/
/* ************************************************************************************ */
int how(){
FILE *file_ptr;                           /*     define file pointer */
   char charCount[3];
   int numCount;

   file_ptr = fopen("trackcn2.txt", "r");    /*   open file for reading */
   
    if (!file_ptr) {                            /*   check for file err */
       file_ptr = fopen("trackcn2.txt", "w");   /*  open file for write */
       putc(48, file_ptr);                      /*      write char zero */
       putc(48, file_ptr);                      /*      write char zero */
       putc(48, file_ptr);                      /*      write char zero */
       return 1;                                /*     return to system */
    }

   charCount[0] = fgetc(file_ptr);              /*  read file 100s char */
   charCount[1] = fgetc(file_ptr);              /*   read file 10s char */
   charCount[2] = fgetc(file_ptr);              /*    read file 1s char */
   fclose(file_ptr);                            /*           close file */

   /* this calculates the count from three text chars in trackcn2.txt   */
   numCount=(charCount[0]-48)*100+(charCount[1]-48)*10+(charCount[2]-48);
   numCount++;                               /*    increment value read */
   printf("\nYou saved %d pieces of bread/bagels by turning them to Toast", numCount);           /*  display value to write */


   file_ptr = fopen("trackcn2.txt", "w");    /*     reopen to overwrite */
   putc(numCount/100+48, file_ptr);          /*     write updated count */
   numCount=numCount-numCount/100*100;       /*       subtract off 100s */
   putc(numCount/10+48, file_ptr);           /*     write updated count */
   numCount=numCount-numCount/10*10;         /*        subtract off 10s */
   putc(numCount+48, file_ptr);              /*     write updated count */
   fclose(file_ptr);                         /*              close file */
 
   
   return 0;                                 /*            exit cleanly */
} 

