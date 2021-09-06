#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

#define CLRSCR system("cls");

void HANGMAN()
{
   	int k,r,i,ch,j,c,count=0,ans=0,flag=0,z=0;
   	
	char a[100][100] = { 
						 "Friends", "Locke and Key", "Stranger Things",
						 "Big Bang Theory", "Harry Potter", "Interstellar", "The Avengers",
						 "Transformer", "Twilight", "Percy Jackson", "Nancy Drew", 
						 "Hardy Boys", "Dairy of a Wimpy Kid", "Calvin and Hobbies", "Archie","Watchmen",
						 "Julius Caeser","hamlet","Romeo and Juliet","Macbeth"
					   };
					   
	printf("Game Instructions\n");
	printf("------------------------\n");
	printf("->  The player can choose one of the topics from the presented below.\n\n-> The player will be given six chances to guess the word.\n\n->  The player will be presented with a few dashes wherein the letters of the word would be displayed if the guess is right.\n\n-> If the guess is wrong, at the end of all the chances, the word will be displayed. \n\n->  The player has to ENTER ONLY THE LETTER AND WAIT FOR THE GAME TO CONTINUE.\n\n");

	/***************************************** MENU ****************************************************/
	
	printf("\t\t\t\t\t\t\tMENU\n\n1]TV SHOWS\n\n2]MOVIES\n\n3]NOVELS\n\n4]COMICS\n\n5]PLAYS\n\n\n\t\t\t\t\tChoose your topic : ");
	scanf("%d",&r);
	
	srand(time(0));
	CLRSCR
	switch(r)
	{
		case 1 : printf("\t\t\t\t\t\tTV SHOWS\n");
				 ch = rand()%4;
				 break;
		case 2 : printf("\t\t\t\t\t\tMOVIES\n");
				 ch = rand()%(4)+4;
				 break;
		case 3 : printf("\t\t\t\t\t\tNOVELS\n");
				 ch = rand()%(4)+8;
				 break;
		case 4 : printf("\t\t\t\t\t\tCOMICS\n");
				 ch = rand()%(4)+12;
				 break;
		case 5 : printf("\t\t\t\t\t\tPLAYS\n");
				 ch = rand()%(4)+16;
				 break;
	}
	
	/*************************************** THE DISPLAY FORMAT *********************************************/
	
	char b[50],alpha;
	char d = '_';
	
	c=strlen(&a[ch][0]);
	printf("\n\n\t\t\t ** HANGMAN ** \n");
	printf("\n\t\t\t**************\t\t\t");
	printf("\n\t\t\t..............\n\n\t\t\t  ");
	
	for(j=0; j<c; j++)
	{ 
		if(a[ch][j]!=' ')
		{
			printf("%c ",d);
	  		b[j] = d;
	  		z += 1;
		}
		else
		{
			printf(" ");
			b[j]=' ';
			
		}
	}
	
	printf("\n\n\t\t\t..............\t\t\t");
	printf("\n\n\t\t\t**************");
	
	/****************************** PLAYER INPUT UNTIL ALL CHANCES FINISH ******************************/
	
	while (count<6)
 	{
		flag = 0;
	    printf("\n\n\n\n\n\n\t Enter a character : ");
			alpha = getch();
			printf("%c",alpha);
			Sleep(500);
		for(i=0; i<c; i++)
		{
			if ( ((tolower(alpha) == a[ch][i]) || (toupper(alpha) == a[ch][i]) && (a[ch][i] != ' ')))
		    {	
		   		if(a[ch][i] != b[i])
		   		{
		   			b[i] = a[ch][i];
			   		flag = 1;
					ans++; 
				}
				else
				{
					do
					{
						printf("\n\nThis character is already entered try again :(\n");
						Sleep(1000);
						printf("\n\n\n\n\n\n\t Enter a character : ");
						alpha = getch();
					} while( (tolower(alpha) == b[i]) || (toupper(alpha) == b[i]));
				}
			}
		}

		CLRSCR
		printf("\n\n\t\t\t ** HANGMAN ** \n");
		printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
		
		for(i=0; i<c; i++)
			printf("%c ", b[i]);
			
		printf("\n\n\t\t\t..............\t\t\t");
		printf("\n\n\t\t\t**************");

		if (flag == 0)
		{
			count++;
			printf("\n\n\n\n\t\t%c is a wrong guess",alpha);
			printf("\n\n\t\t (You have %d more guesses)",6-count);
		}

		else
		{
			printf("\n\n\t\t you are correct!!");
		    printf("\n\t\t( You have %d more letters to go)",z-ans);
		}
		if(ans==z) break;
 	}
 	
 	/************************************** RESULT DECLARATION *******************************************/
 	
	if (ans == z) 
	 	{
	 		printf("\a");
	 		printf("\n\n\n\t HURRAY !!! YOU WON!! :) :)");	
		}
 	else 
	 	{
	 		
		printf("\n\n\t\tGAME OVER\n\n \t\t **SORRY  YOU ARE HANGED :( :(**");
	 	printf("\n\t\t\t\t\t\t\tTHE WORD IS:");
	 	for(k=0;k<c;k++)
	 		printf("%c",a[ch][k]);
	 	printf("\n");}
	getchar();

}
