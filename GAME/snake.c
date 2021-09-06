#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "snake.h"

#define N 25
#define M 80
#define CLRSCR system("cls");
#define PAUSE system("pause");

int i, j, Field[N][M], Gy, Head, Tail, x, y, a, b, var, dir, Score, HighScore, Speed;
bool Game, Frogs, Return;
FILE *f;

/******************************************* EXECUTION OF GAME ******************************************/

void SNAKE()
{
	snakeInitialization();
    WelcomeMessage();
	while (Game)
    {
        print();
        ResetScreenPosition();
        Random();
        movement();
        TailRemove();
		Sleep(Speed);
    }
}

/***************************************** PREAMBLE TO THE GAME *******************************************/

void WelcomeMessage()
{
	printf("\t\t\t\tWelcome to the MINI SNAKE GAME.");
	PAUSE
	fflush(stdin);
	CLRSCR
	printf("Game instructions\n---------------------\n\n\n");
	printf("->  Use the keys 'WSAD' to control your snake. They mean Up, Down, Left and Right respectively.\n\n");
	printf("->  You will be provided foods at the several coordinates of the screen which your snake has to eat.\n\n");
	printf("->  Everytime you eat food ,the length of the snake will be increased by 1 element and thus the score.\n\n");
	printf("->  Here you will have only one life. If your snake ends up eating its own body, it's...... GAME OVER!\n\n");
	PAUSE
	fflush(stdin);
	CLRSCR
}

/*********************************** INITIALIZING ALL VALUES OF THE GAME ************************************/

void snakeInitialization()
{
	f = fopen("HighScore.txt","r");					// Storing highscore in the file highscore
	fscanf(f,"%d",&HighScore);							// and displaying it.
	fclose(f);
	
    for (i=0; i<N; i++)								// Printing the Arena/Board.
    {
        for (j=0; j<M; j++)
        {
            Field[i][j] = 0;
        }
    }

    x = N/2;										// Initial position of the snake is the middle of the arena.
    y = M/2;
    Head = 5;                               		// Coordinate holding the value 5 is head of snake
    Tail = 1;											// and 1 is tail of snake.
    Gy = y;											// Temporary variable used to set the elements of Field array
    Game = 1;											// to values starting from 1,2,3...
    Frogs = 0;
    dir = 'd';
    Score = 0;

    for (i=0; i<Head; i++)							// A loop to initialize all those values
    {													// of array which hold the snake's body.
        Gy++;
        Field[x][Gy-Head] = i+1;
    }
}

/******************************* PRINTING THE BORDER, SCORE, HIGH SCORE *************************************/

void print()                               													 
{
	for (i=0; i<=M+1; i++)									
    {														
        if (i == 0)											
            printf ("%c", 201);								
        else if (i == M+1)
            printf("%c", 187);
        else
            printf("%c", 205);
    }
    
	
    printf("\n");

    for (i=0; i<N; i++)   
    {
        printf("%c", 186);
        for (j=0; j<M; j++)
        {
            if (Field[i][j] == 0)										// Space to cover for ASCII values
                printf(" ");												//	201, 187, 200, 188. 
            if ((Field[i][j] > 0) && (Field[i][j] != Head))				// (char) 15 is the food that is displayed.
                printf ("%c", 176);										
            if (Field[i][j] == Head)									// 186, 205 are also used for border.
                printf ("%c", 178);
            if (Field[i][j] == -1)
                printf ("%c", 15);
            if (j == M-1)
                printf ("%c\n", 186);
        }
    }

    for (i=0; i<=M+1; i++)
    {
        if (i == 0)
            printf ("%c", 200);
        else if (i == M+1)
            printf("%c", 188);
        else
            printf("%c", 205);
    }
    printf("\n\n\tScore : %d\t\t\t\t\t\tHigh Score : %d\n\n", Score, HighScore);
}

/************************************ RESETTING THE POSITION OF THE CURSOR ************************************/

void ResetScreenPosition()
{
    HANDLE hout;                                    // Provides a handle to the console of the program.
    COORD Position;                              	// Holds the position of the beginning of the terminal (0,0).
    hout = GetStdHandle (STD_OUTPUT_HANDLE);        // Handles standard / console output.
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition( hout, Position);
}

/********************************* GENERATING RANDOM POSITION FOR FOOD/FROG ************************************/

void Random()
{
	srand( time(0) );
    a = 1 + rand() % (N-2);										// N-2, -2 to prevent the food from being 
    b = 1 + rand() % (M-2);											// generated on the border.

    if (Frogs == 0 && Field[a][b] == 0)
    {
        Field[a][b] = -1;
        Frogs = 1;
		if (Speed > 10 && Score != 0)
			Speed -= 15;
    }
}

/************************ GETTING ASCII VALUE OF THE CHARACTER WHEN KEYBOARD IS HIT **************************/

int getch_noblock()
{
	if(_kbhit())
		return _getch();
	else
		return -1;
}

/************************************ CONTROL OF SNAKE BODY MOVEMENT *************************************/

void movement()
{
	var = getch_noblock();
	var = tolower(var);
	if (((var == 'd') || (var == 's') || (var == 'a') || (var == 'w')) && (abs(dir-var) > 5))
		dir = var;
	if (dir == 'd')
	{
		y++;
		if (Field[x][y] != 0 && Field[x][y] != -1)					// When the snake encounters it's own body, game ends.
			GameOver();
		if (y == M-1)
			y=0;
		if (Field[x][y] == -1)
		{
			Frogs = 0;
			Score += 1;
			Tail -= 2;												// Increasing the length of snake body
		}																// when food is consumed.
		Head++;
		Field[x][y] = Head;
	}
	
	if (dir == 'a')
	{
		y--;
		if (Field[x][y] != 0 && Field[x][y] != -1)
			GameOver();
		if (y == 0)
			y = M-1;
		if (Field[x][y] == -1)
		{
			Frogs = 0;
			Score += 1;
			Tail -= 2;
		}
		Head++;
		Field[x][y] = Head;
	}
	
	if (dir == 'w')
	{
		x--;
		if (Field[x][y] != 0 && Field[x][y] != -1)
			GameOver();
		if (x == 0)
			x = N-1;
		if (Field[x][y] == -1)
		{
			Frogs = 0;
			Score += 1;
			Tail -= 2;
		}
		Head++;
		Field[x][y] = Head;
	}
	
	if (dir == 's')
	{
		x++;
		if (Field[x][y] != 0 && Field[x][y] != -1)
			GameOver();
		if (x == N-1)
			x=0;
		if (Field[x][y] == -1)
		{
			Frogs = 0;
			Score += 1;
			Tail -= 2;
		}
		Head++;
		Field[x][y] = Head;
	}
}

/******************************* MOVING THE TAIL FORWARD WITH THE HEAD MOVEMENT ****************************/

void TailRemove()
{
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			if (Field[i][j] == Tail)
				Field[i][j] = 0;
	Tail++;
}

/*************************************************** GAME OVER *********************************************/

void GameOver()
{
	printf("\a");
	Sleep(1500);
	CLRSCR
	
	if(Score > HighScore)												// Overwrites the high score in HighScore.txt only
	{																		// when the current score is greater than HighScore.
		printf("New HighScore!!!!!!!!!  %d\n\n", Score);
		PAUSE
		f=fopen("HighScore.txt","w");
		fprintf(f, "%d", Score);
		fclose(f);
	}		

	CLRSCR
	printf("\n\n\t\t\t\t\tGAME OVER !!!!!");
	PAUSE
	CLRSCR
	record();
	Game = 0;
}

/****************************** STORING ALL RECORDS IN A FILE AND DISPLAYING THEM *************************/

void record()
{
	char plname[20],nplname[20],cha,c;
	int i,j,px;
   
	FILE *info;														// Creating or Opening an already existing file
    info = fopen("record.txt","a+");									// record.txt to store the player's details.
    CLRSCR
    printf ("Enter your name : ");
    scanf(" %[^\n]s",plname);
   
    for(j=0; plname[j] != '\0'; j++)
    { 																// To convert the first letter after 
    	nplname[0] = toupper(plname[0]);								// space to capital
	    if(plname[j-1] == ' ')
		{
	    	nplname[j] = toupper(plname[j]);
   			nplname[j-1] = plname[j-1];
		}
   		else 
		   nplname[j] = plname[j];
    }
    nplname[j] = '\0';
   
    fprintf(info,"Player Name : %s\n",nplname);
   
    time_t mytime;													 // For date and time
    mytime = time(NULL);
    fprintf(info,"Played Date : %s",ctime(&mytime));
	fprintf(info,"Score : %d\n",Score);								
    
    for(i=0; i<=50; i++)
    	fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
	
	CLRSCR
    printf("To see past records press 'y/n'\n");
    scanf(" %c",&cha);
    CLRSCR
    
	if(cha == 'y')
	{
 	   	info = fopen("record.txt","r");
   		do
		{
       		putchar(c=getc(info));
       	} while(c != EOF);
	}
    fclose(info);
}
