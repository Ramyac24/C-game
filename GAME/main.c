#include "snake.c"
#include "guess_game.c"
#include "hangman.c"
#include "tictactoe.c"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#define ENTER 13
#define CLRSCR system("cls");

int main()
{
	CLRSCR
	int O,CHOICE;
	bool yes, gameon;
	printf("\t\t\t\t\t\t\tWELCOME TO QUADRANGLE\n\n\n");
	Sleep(500);                                     					// delaying display time
	printf("We bring you some of the classic games of all time, HOPE YOU ENJOY!!\n\n");
	Sleep(1000);
    
   /******************************************** DISPLAYING THE MENU *******************************************/
   
	do
	{
		printf("\t\t\t\t\t\t\tMENU\n\n\n");
		printf("1.  Tic tac toe\n\n");
		Sleep(1000);
		printf("2.  Snake\n\n");
		Sleep(1000);
		printf("3.  Hangman\n\n");
		Sleep(1000);
		printf("4.  Chase your mouse\n\n");
		Sleep(1000);
		printf("5.  EXIT\n\n");
		Sleep(250);
    
		printf("\n\t\t\tChoose your game : ");
		scanf("%d", &CHOICE);
		CLRSCR
        
	/************************************************ GAME EXECUTION ******************************************/
      
		switch (CHOICE)
		{
			case 1 : do 
					 {
						CLRSCR
						TICTACTOE();
						printf("\n\nPress Enter to Play Again :) \n\n\t\tOR \n\nPress any key to return to Main Menu :) : ");
						(getch() == ENTER) ? (yes = 1) : (yes = 0);
                	 } while(yes);
                	CLRSCR
                	break;

        	case 2 : do
                	 {
                  		CLRSCR
                    	SNAKE();
                    	printf("\n\nPress Enter to Play Again :) \n\n\t\tOR \n\nPress any key to return to Main Menu :) : ");
                    	(getch() == ENTER) ? (yes = 1) : (yes = 0);
                  	 } while(yes);
                	 CLRSCR
                	 break;

        	case 3 : do 
					 {
                  		CLRSCR
                    	HANGMAN();
                		printf("\n\nPress Enter to Play Again :) \n\n\t\tOR \n\nPress any key to return to Main Menu :) : ");
                    	(getch() == ENTER) ? (yes = 1) : (yes = 0);
                	 } while(yes);
                	 CLRSCR
                	 break;
        	case 4 : do 
                	 {
                    	CLRSCR
                    	GUESS();
                    	printf("\n\nPress Enter to Play Again :) \n\n\t\tOR \n\nPress any key to return to Main Menu :) : ");
                    	(getch() == ENTER) ? (yes = 1) : (yes = 0);
                	 } while(yes);
                	 CLRSCR
                	 break;
        
        	case 5 : printf ("THANKYOU FOR PLAYING !!!\n\t\tQUADRANGLE WELCOMES YOU ANYTIME :)\n\t\t\tCYA SOON ;)");
                	 exit(0);
    	}
    	(!yes) ? (gameon = 1) : (gameon = 0);
	} while (gameon);
	return 0;
}
