#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
#include "guess_game.h"

/******************************* COMPARING THE PLAYER'S GUESS WITH CURRENT SITUATION ***************************/

	void GUESS() 
	{ 
		int total, cheese; 
		printf("You have to guess the hole in which the Rat is hidden among three holes.\nThe hole in which Rat is present is named as 'R' and rest two are named as 'N'. \nIf your guess is wrong, you lose the cheese cubes you entered from the total number of cheese cubes you have.\nIf you guess it right, you win twice the cheese cubes you entered from the total number of cheese cubes you have.	\nKeep playing and keep winning until you run out of cheese.\n\nREMEMBER YOUR GUESS SHOULD BE EITHER 1,2 OR 3\n\n");
		printf("\n----Enter the number of cheese cubes you have now---- : "); 
		scanf("%d", &cheese); 

		while (cheese > 0) 
		{ 
			printf("\nEnter the amount of cheese cubes you want to play for : "); 
			scanf("%d", &total); 
			if (cheese == 0 || total > cheese) 
				break;
			system("cls");
			GuessGame(total, &cheese); 
		} 

/********************************************** FINISHING GAME ************************************************/

	if (cheese == 0 || total > cheese) 
	{ 
		printf("\n\""
			"  Sorry you don't have enough cheese to play more, "); 
		printf("Do come next time\""
			"\n"); 
		printf("Thank You for playing  \n"); 
	} 
	getchar();
} 

void GuessGame(int total, int* cheese) 
{ 
	char Hole[3] = { 'N', 'R', 'N' };
	printf("\nWait !! Rat is shuffling it's position...\n"); 
	srand((time(NULL))); 
	int i, x, y, temp, r; 

	/******SWAPPING THE RAT'S (R'S) POSITION FIVE TIMES USING THE RANDOM NUMBER FOR RANDOM INDEX ***********/

	for (i = 0; i < 5; i++) 
	{
		x = rand() % 3; 
		y = rand() % 3; 
		temp = Hole[x]; 
		Hole[x] = Hole[y]; 
		Hole[y] = temp; 
	}
	
	int PlayerGuess;
	
	printf("\nYou may now guess the hole in which Rat is present: "); 
	scanf("%d", &PlayerGuess);
	
	/*********************************** CHECKING THE PLAYER'S INPUT **************************************/
	
	do	
	{
		if (PlayerGuess!=1 && PlayerGuess!=2 && PlayerGuess!=3 )	
		{
			printf("Invalid Move\nTry again\n");
			Sleep(1000);
			printf("\nYou may now guess the hole in which Rat is present: ");
			scanf("%d", &PlayerGuess);	
		}
		(PlayerGuess!=1 && PlayerGuess!=2 && PlayerGuess!=3 )?(r=1):(r=0);
	} while(r);	

	if (Hole[PlayerGuess - 1] == 'R') 
	{ 
		(*cheese) += 2 * total; 
		printf("You win ! The holes are as follows: "); 
		printf("\"%c %c %c\" ", Hole[0], Hole[1], Hole[2]); 
		printf("\nThe total no of cheese cubes with you now is = %d \n", *cheese); 
	} 

	else 
	{ 
		(*cheese) -= total; 
		printf("You Loose ! The holes are as follows: "); 
		printf("\"%c %c %c\" ", Hole[0], Hole[1], Hole[2]); 
		printf("\nCheese cubes present with you now is = %d \n", *cheese); 
	} 

} 

