#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <wincon.h>
#include "mode1vs2.c"
#include "mode3.c"
#include <stdbool.h>




#define TOPBOARD 3
#define BOTTOMBOARD 35
#define LEFTBOARD 18
#define RIGHBOARD 80
#define CENTER 8

#define UP 2
#define DOWN 4
#define ENTER 5
#define ESC 6

int music = 1;
int choiceMenu;
int choiceMode = 1;
int choiceHiTable = 1;
int exitGame;
int setXMenu = LEFTBOARD + 24;
int setYMenu = TOPBOARD + 18;


void setCursor(){
	bool visible;
	DWORD size;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}


void background(){

	textcolor(10);
	goTo(LEFTBOARD + CENTER + 5, TOPBOARD + 3); printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);     //F
	goTo(LEFTBOARD + CENTER + 5, TOPBOARD + 4); printf("%c%c%c%c%c", 219, 219, 220, 220, 220);
	goTo(LEFTBOARD + CENTER + 5, TOPBOARD + 5); printf("%c%c%c%c%c", 219, 219, 223, 223, 223);
	goTo(LEFTBOARD + CENTER + 5, TOPBOARD + 6); printf("%c%c", 219, 219);
	
	textcolor(4);
	goTo(LEFTBOARD + CENTER + 12, TOPBOARD + 3); printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);  //R
	goTo(LEFTBOARD + CENTER + 12, TOPBOARD + 4); printf("%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 12, TOPBOARD + 5); printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 223);	
	goTo(LEFTBOARD + CENTER + 12, TOPBOARD + 6); printf("%c%c%c%c%c%c", 219, 219, 32, 223, 219, 219);	

	textcolor(14);
	goTo(LEFTBOARD + CENTER + 19, TOPBOARD + 3); printf("%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219); //U
	goTo(LEFTBOARD + CENTER + 19, TOPBOARD + 4); printf("%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 19, TOPBOARD + 5); printf("%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 19, TOPBOARD + 6); printf("%c%c%c%c%c%c", 223, 219, 219, 219, 219, 223);

	textcolor(5);
	goTo(LEFTBOARD + CENTER + 26, TOPBOARD + 3); printf("%c%c", 219, 219);   //I
	goTo(LEFTBOARD + CENTER + 26, TOPBOARD + 4); printf("%c%c", 219, 219);
	goTo(LEFTBOARD + CENTER + 26, TOPBOARD + 5); printf("%c%c", 219, 219);
	goTo(LEFTBOARD + CENTER + 26, TOPBOARD + 6); printf("%c%c", 219, 219);

	textcolor(13);
	goTo(LEFTBOARD + CENTER + 29, TOPBOARD + 3); printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);   //T
	goTo(LEFTBOARD + CENTER + 29, TOPBOARD + 4); printf("%c%c%c%c", 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 29, TOPBOARD + 5); printf("%c%c%c%c", 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 29, TOPBOARD + 6); printf("%c%c%c%c", 32, 32, 219, 219);

	textcolor(6);
	goTo(LEFTBOARD + CENTER + 36, TOPBOARD + 3); printf("%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219);  //Y
	goTo(LEFTBOARD + CENTER + 36, TOPBOARD + 4); printf("%c%c%c%c%c%c", 223, 219, 219, 219, 219, 223);
	goTo(LEFTBOARD + CENTER + 36, TOPBOARD + 5); printf("%c%c%c%c", 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 36, TOPBOARD + 6); printf("%c%c%c%c", 32, 32, 219, 219);

	textcolor(10); //MONSTER
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 6); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 7); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 8); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32);
	
	textcolor(4);
	goTo(LEFTBOARD + 5, TOPBOARD + 10); printf("%c%c%c%c%c%c%c%c%c", 32, 219, 219, 223, 219, 219, 223, 219, 219);   //M   
	goTo(LEFTBOARD + 5, TOPBOARD + 11); printf("%c%c%c%c%c%c%c%c%c", 220, 219, 219, 32, 219, 219, 32, 219, 219);
	goTo(LEFTBOARD + 5, TOPBOARD + 12); printf("%c%c%c%c%c%c%c%c%c", 219, 219, 219, 32, 219, 219, 32, 219, 219);
	goTo(LEFTBOARD + 5, TOPBOARD + 13); printf("%c%c%c%c%c%c%c%c%c", 223, 223, 223, 32, 223, 223, 32, 223, 223);

	
	goTo(LEFTBOARD + 15, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 219, 219);      //O
	goTo(LEFTBOARD + 15, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 220, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 15, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 15, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);

	
	goTo(LEFTBOARD + 23, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 219, 219, 223, 223, 223, 219, 219);      //N
	goTo(LEFTBOARD + 23, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 219, 219, 220, 32, 32, 219, 219);
	goTo(LEFTBOARD + 23, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 23, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 32, 32, 223, 223);

	goTo(LEFTBOARD + 31, TOPBOARD + 10); printf("%c%c%c%c%c%c", 32, 219, 219, 223, 223, 219);      //S
	goTo(LEFTBOARD + 31, TOPBOARD + 11); printf("%c%c%c%c%c%c", 32, 219, 219, 220, 220, 220);
	goTo(LEFTBOARD + 31, TOPBOARD + 12); printf("%c%c%c%c%c%c", 220, 32, 32, 219, 219, 219);
	goTo(LEFTBOARD + 31, TOPBOARD + 13); printf("%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223);

	
	goTo(LEFTBOARD + 38, TOPBOARD + 10); printf("%c%c%c%c%c%c", 223, 223, 219, 219, 223, 223);      //T
	goTo(LEFTBOARD + 38, TOPBOARD + 11); printf("%c%c%c%c%c%c", 32, 220, 219, 219, 32, 32);
	goTo(LEFTBOARD + 38, TOPBOARD + 12); printf("%c%c%c%c%c%c", 32, 219, 219, 219, 32, 32);
	goTo(LEFTBOARD + 38, TOPBOARD + 13); printf("%c%c%c%c%c%c", 32, 223, 223, 223, 32, 32);

	goTo(LEFTBOARD + 45, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 223, 223);      //E
	goTo(LEFTBOARD + 45, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 220, 219, 219, 220, 220, 220, 220);
	goTo(LEFTBOARD + 45, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + 45, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);

	goTo(LEFTBOARD + 53, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 219, 219, 223, 223, 219, 219, 32);      //R
	goTo(LEFTBOARD + 53, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 219, 219, 220, 220, 219, 219, 220);
	goTo(LEFTBOARD + 53, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 53, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 32, 32, 223, 223);		
	textcolor(7);
}

void drawBoard()   // ve khung phia ngoai
{
	int i;
	for (i = TOPBOARD + 1; i < BOTTOMBOARD; i++){
		goTo(LEFTBOARD, i);
		printf("%c", 186);
		goTo(RIGHBOARD, i);
		printf("%c", 186);
	}
	for (i = LEFTBOARD + 1; i < RIGHBOARD; i++){
		goTo(i, TOPBOARD);
		printf("%c", 205);
		goTo(i, BOTTOMBOARD);
		printf("%c", 205);
	}  
	goTo(LEFTBOARD, TOPBOARD); printf("%c", 201);
	goTo(RIGHBOARD, TOPBOARD); printf("%c", 187);
	goTo(LEFTBOARD, BOTTOMBOARD); printf("%c", 200);
	goTo(RIGHBOARD, BOTTOMBOARD); printf("%c", 188);	
}


// HIGHSCORES
typedef struct Highscores{
	char *rank; 
	char *name; 	//ten player
	int hiScore; 	//diem player
} highscores;

highscores player[5]; //so luong player dc luu lai


void readHighscores() { //doc file highscore.txt de lay ten va diem player vao game
	int i;
	FILE *readFile;
	switch (choiceHiTable){
		case 1: {
			readFile = fopen ("highscoresMode1.txt", "r");
			break;
		}
		case 2: {
			readFile = fopen ("highscoresMode2.txt", "r");
			break;
		}
		case 3: {
			readFile = fopen ("highscoresMode3.txt", "r");
			break;
		}
		case RESET: {
			readFile = fopen ("standard.txt", "r");
			break;
			break;
		}
	}
	for(i = 0; i < 5; i++)
	{
		player[i].rank = malloc(sizeof(char)*3);
		player[i].name = malloc(sizeof(char)*10);
		fscanf(readFile, "%5s%12s%7d", player[i].rank, player[i].name, &player[i].hiScore);
	}
	fclose(readFile);
}

void writeHighscores(){
	int i;
	FILE *writeFile;
		switch (choiceHiTable){
		case 1: {
			writeFile = fopen ("highscoresMode1.txt", "w+");
			break;
		}
		case 2: {
			writeFile = fopen ("highscoresMode2.txt", "w+");
			break;
		}
		case 3: {
			writeFile = fopen ("highscoresMode3.txt", "w+");
			break;
		}
	}
	for (i = 0; i < 5; i++)
	{	
		fprintf(writeFile, "%5s%12s%7d\n", player[i].rank, player[i].name, player[i].hiScore);
	}
	fclose(writeFile);
}

void printHighscores(){
	readHighscores();
	int i;
	for (i = 0; i < 5; i++){
		goTo(setXMenu, setYMenu + i*2); printf("%5s%12s%7d", player[i].rank, player[i].name, player[i].hiScore);
	}
}

int checkScore(){
	int i;
	readHighscores();
	for (i = 0; i < 5; i++){
		if (score > player[i].hiScore) return (i + 1);
	}
	return 0;
}

void updateHighscores(int i){
	goTo(LEFTBOARD + 20, TOPBOARD + 16); printf("WOAH! NEW HIGH SCORES!");
	Sleep(1500);
	goTo(LEFTBOARD + 20, TOPBOARD + 18); printf("Enter your name:");
	char str[10], real[10];
	int a = 0, b;
	while(1){
		if (kbhit()){
			
				char tmp;
				tmp = getch();
				if (tmp == 13 && a > 0) break;
				if ((isalnum(tmp) || ispunct(tmp) || tmp == 8) && tmp != 72 && tmp != 75 && tmp != 77 && tmp != 80){
					if (tmp == 8){
						if (a > 0){
							goTo(LEFTBOARD + 36 + a, TOPBOARD + 18); printf("%c", 32);
							a--;
						}
					}
					else if (a < 7){
						goTo(LEFTBOARD + 37 + a, TOPBOARD + 18); printf("%c", tmp);
						str[a] = tmp;
						a++;
					}
				}
			
		}
	}
	for (b = 0; b < a; b++){
		real[b] = str[b];
	}
	player[i - 1].name = real;
	player[i - 1].hiScore = score;
	writeHighscores();
}

void highscoresProcessing(){
	if (checkScore()){
		setXMenu = LEFTBOARD + 18;
		setYMenu = TOPBOARD + 20;
		if (switchMusic == ON)PlaySound(TEXT("HISCORES.wav"), NULL, SND_ASYNC); 
		updateHighscores(checkScore());
		printHighscores();
	}
	else {
		setXMenu = LEFTBOARD + 18;
		setYMenu = TOPBOARD + 18;
		printHighscores();
	}
}


void printHiscores(){
	textcolor(10); //MONSTER
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 32, 32);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 6); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 7); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 32, 32, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + CENTER + 44, TOPBOARD + 8); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32);
	textcolor(7);
	
	goTo(LEFTBOARD + 18, TOPBOARD + 4); printf("%c%c%c%c%c%c%c", 32, 219, 219, 32, 32, 219, 219);      //H
	goTo(LEFTBOARD + 18, TOPBOARD + 5); printf("%c%c%c%c%c%c%c", 220, 219, 219, 220, 220, 219, 219);
	goTo(LEFTBOARD + 18, TOPBOARD + 6); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 18, TOPBOARD + 7); printf("%c%c%c%c%c%c%c", 223, 223, 223, 32, 32, 223, 223);
	
	goTo(LEFTBOARD + 26, TOPBOARD + 4); printf("%c%c%c", 32, 219, 219);      //I
	goTo(LEFTBOARD + 26, TOPBOARD + 5); printf("%c%c%c", 220, 219, 219);
	goTo(LEFTBOARD + 26, TOPBOARD + 6); printf("%c%c%c", 219, 219, 219);
	goTo(LEFTBOARD + 26, TOPBOARD + 7); printf("%c%c%c", 223, 223, 223);
	
	goTo(LEFTBOARD + 30, TOPBOARD + 4); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 219, 219);      //G
	goTo(LEFTBOARD + 30, TOPBOARD + 5); printf("%c%c%c%c%c%c%c", 220, 219, 219, 32, 220, 220, 220);
	goTo(LEFTBOARD + 30, TOPBOARD + 6); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 30, TOPBOARD + 7); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);
	
	goTo(LEFTBOARD + 38, TOPBOARD + 4); printf("%c%c%c%c%c%c%c", 32, 219, 219, 32, 32, 219, 219);      //H
	goTo(LEFTBOARD + 38, TOPBOARD + 5); printf("%c%c%c%c%c%c%c", 220, 219, 219, 220, 220, 219, 219);
	goTo(LEFTBOARD + 38, TOPBOARD + 6); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 38, TOPBOARD + 7); printf("%c%c%c%c%c%c%c", 223, 223, 223, 32, 32, 223, 223);
	
	goTo(LEFTBOARD + 15, TOPBOARD + 9);	printf("%c%c%c%c%c", 219, 223, 223, 223, 223);		//S
	goTo(LEFTBOARD + 15, TOPBOARD + 10); printf("%c%c%c%c%c", 223, 223, 223, 219, 219);
	goTo(LEFTBOARD + 15, TOPBOARD + 11); printf("%c%c%c%c%c", 219, 220, 220, 219, 219);
	
	goTo(LEFTBOARD + 21, TOPBOARD + 9);	printf("%c%c%c%c%c", 219, 223, 223, 223, 219);		//C
	goTo(LEFTBOARD + 21, TOPBOARD + 10); printf("%c%c%c%c%c", 219, 219, 32, 32, 32);
	goTo(LEFTBOARD + 21, TOPBOARD + 11); printf("%c%c%c%c%c", 219, 219, 220, 220 , 219);
	
	goTo(LEFTBOARD + 27, TOPBOARD + 9);	printf("%c%c%c%c%c", 219, 223, 223, 219, 219);		//O
	goTo(LEFTBOARD + 27, TOPBOARD + 10); printf("%c%c%c%c%c", 219, 32, 32, 32, 219);
	goTo(LEFTBOARD + 27, TOPBOARD + 11); printf("%c%c%c%c%c", 219, 220 , 220, 220, 219);
	
	goTo(LEFTBOARD + 33, TOPBOARD + 9);	printf("%c%c%c%c%c", 219, 223, 223, 219, 32);		//R
	goTo(LEFTBOARD + 33, TOPBOARD + 10); printf("%c%c%c%c%c", 219, 219, 223, 223, 219);
	goTo(LEFTBOARD + 33, TOPBOARD + 11); printf("%c%c%c%c%c", 219, 219, 32, 32, 219);
	
	goTo(LEFTBOARD + 39, TOPBOARD + 9);	printf("%c%c%c%c", 219, 223, 223, 223);		//E
	goTo(LEFTBOARD + 39, TOPBOARD + 10); printf("%c%c%c%c", 219, 219, 223, 223);
	goTo(LEFTBOARD + 39, TOPBOARD + 11); printf("%c%c%c%c", 219, 219, 220, 220);
	
	goTo(LEFTBOARD + 44, TOPBOARD + 9);	printf("%c%c%c%c%c", 219, 223, 223, 223, 223);		//S
	goTo(LEFTBOARD + 44, TOPBOARD + 10); printf("%c%c%c%c%c", 223, 223, 223, 219, 219);
	goTo(LEFTBOARD + 44, TOPBOARD + 11); printf("%c%c%c%c%c", 219, 220, 220, 219, 219);
	
	
	goTo(LEFTBOARD + 10, TOPBOARD + 16); textcolor(79); printf("  MODE 1  "); textcolor(7);
	setXMenu = LEFTBOARD + 18;
	setYMenu = TOPBOARD + 19;
	choiceHiTable = 1;
	printHighscores();
	setXMenu = LEFTBOARD + 10;
	setYMenu = TOPBOARD + 16;
	
	goTo(LEFTBOARD + 25, TOPBOARD + 16); printf("  MODE 2  ");
	goTo(LEFTBOARD + 40, TOPBOARD + 16); printf("  MODE 3  ");
}

void moveHitable(){	
	switch (choiceMenu){
		case LEFT: {
		
			if (setXMenu == LEFTBOARD + 25){
				goTo (setXMenu, setYMenu);
				printf("  MODE 2  ");
				
			}
			if (setXMenu == LEFTBOARD + 40){
				goTo (setXMenu, setYMenu);
				printf("  MODE 3  ");
				
			}
			setXMenu -= 15;
			if (setXMenu == LEFTBOARD + 25){
				goTo (setXMenu, setYMenu);
				textcolor(79); printf("  MODE 2  "); textcolor(7);
				
				setXMenu = LEFTBOARD + 18;
				setYMenu = TOPBOARD + 19;
				choiceHiTable = 2;
				printHighscores();
				setXMenu = LEFTBOARD + 25;
				setYMenu = TOPBOARD + 16;
				
				
			}
			if (setXMenu == LEFTBOARD + 10){
				goTo (setXMenu, setYMenu);
				textcolor(79); printf("  MODE 1  "); textcolor(7);
				
				setXMenu = LEFTBOARD + 18;
				setYMenu = TOPBOARD + 19;
				choiceHiTable = 1;
				printHighscores();
				setXMenu = LEFTBOARD + 10;
				setYMenu = TOPBOARD + 16;
				
				
			}
			break;
		}
		case RIGHT: {
			if (setXMenu == LEFTBOARD + 25){
				goTo (setXMenu, setYMenu);
				printf("  MODE 2  ");
				
			}
			if (setXMenu == LEFTBOARD + 10){
				goTo (setXMenu, setYMenu);
				printf("  MODE 1  ");
				
			}
			setXMenu += 15;
			if (setXMenu == LEFTBOARD + 25){
				goTo (setXMenu, setYMenu);
				textcolor(79); printf("  MODE 2  "); textcolor(7);
			
				setXMenu = LEFTBOARD + 18;
				setYMenu = TOPBOARD + 19;
				choiceHiTable = 2;
				printHighscores();
				setXMenu = LEFTBOARD + 25;
				setYMenu = TOPBOARD + 16;
				
				
			}
			if (setXMenu == LEFTBOARD + 40){
				goTo (setXMenu, setYMenu);
				textcolor(79); printf("  MODE 3  "); textcolor(7);
				
				setXMenu = LEFTBOARD + 18;
				setYMenu = TOPBOARD + 19;
				choiceHiTable = 3;
				printHighscores();
				setXMenu = LEFTBOARD + 40;
				setYMenu = TOPBOARD + 16;
				
				
			}
			break;
		}
	}
}

void printOptions(){
	drawBoard();
	background();
	goTo(LEFTBOARD + 20, TOPBOARD + 18);
	if (switchMusic == ON){
		textcolor(79); printf("   MUSIC: ON    "); textcolor(7);
	}
	else {
		textcolor(79); printf("   MUSIC: OFF   "); textcolor(7);
	}
	goTo(LEFTBOARD + 20, TOPBOARD + 22); printf("   RESET HIGHSCORES   ");

}

void printResetTable(){
	goTo(LEFTBOARD + 20, TOPBOARD + 18); textcolor(79); printf("   HIGHSCORES MODE 1  "); textcolor(7);
	goTo(LEFTBOARD + 20, TOPBOARD + 22); printf("   HIGHSCORES MODE 2   ");
	goTo(LEFTBOARD + 20, TOPBOARD + 26); printf("   HIGHSCORES MODE 3   ");
}

void moveModeReset()
{
	switch (choiceMenu){
		case UP: {
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				printf("   HIGHSCORES MODE 2   ");
			}
			if (setYMenu == TOPBOARD + 26){
				goTo(setXMenu, setYMenu);  
				printf("   HIGHSCORES MODE 3   ");
			}
			setYMenu -= 4;
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   HIGHSCORES MODE 1   "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   HIGHSCORES MODE 2   "); textcolor(7);
			}
			break;
		}
		case DOWN: {
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu);  
				printf("   HIGHSCORES MODE 1   ");
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				printf("   HIGHSCORES MODE 2   ");
			}
			setYMenu += 4;
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   HIGHSCORES MODE 2   "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 26){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   HIGHSCORES MODE 3   "); textcolor(7);
			}
			break;
		}
		case ENTER: {
			if (setYMenu == TOPBOARD + 18){
				choiceHiTable = RESET;
				readHighscores();
				choiceHiTable = 1;
				writeHighscores();
			}
			if (setYMenu == TOPBOARD + 22){
				choiceHiTable = RESET;
				readHighscores();
				choiceHiTable = 2;
				writeHighscores();
			}
			if (setYMenu == TOPBOARD + 26){
				choiceHiTable = RESET;
				readHighscores();
				choiceHiTable = 3;
				writeHighscores();
			}
			choiceHiTable = 1;
			break;
		}
	}	
}

void getChoiceMenu ()    // nhan phim dieu khien cua nguoi dung
{
	int key;
	if (kbhit()){
		key = getch();
		if (key == 'W' || key == 'w' || key == 72 || key == 's' || key == 'S' || key == 80 || key == 'a' || key == 'A' || key == 75 || key == 'd' || key == 'D' || key == 77 || key == 13 || key == 27){
			
			if ((key == 'w' || key == 'W' || key == 72) && setYMenu > TOPBOARD + 18) choiceMenu = UP;
			if ((key == 's' || key == 'S' || key == 80) && setYMenu < TOPBOARD + 26) choiceMenu = DOWN;
			if ((key == 'a' || key == 'A' || key == 75) && setXMenu > LEFTBOARD + 10) choiceMenu = LEFT;
			if ((key == 'd' || key == 'D' || key == 77) && setXMenu < LEFTBOARD + 40) choiceMenu = RIGHT;		
			if (key == 13) choiceMenu = ENTER;
			if (key == 27) choiceMenu = ESC;
		}
		else choiceMenu = NOPE;
	}
	else choiceMenu = NOPE;
}

void printGameOver(){
	textcolor(12);
	goTo(LEFTBOARD + 15, TOPBOARD + 5); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 219, 219);      //G
	goTo(LEFTBOARD + 15, TOPBOARD + 6); printf("%c%c%c%c%c%c%c", 220, 219, 219, 32, 220, 220, 220);
	goTo(LEFTBOARD + 15, TOPBOARD + 7); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 15, TOPBOARD + 8); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);
	
	goTo(LEFTBOARD + 23, TOPBOARD + 5); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 219, 219, 32);      //A
	goTo(LEFTBOARD + 23, TOPBOARD + 6); printf("%c%c%c%c%c%c%c", 220, 219, 219, 220, 219, 219, 220);
	goTo(LEFTBOARD + 23, TOPBOARD + 7); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 23, TOPBOARD + 8); printf("%c%c%c%c%c%c%c", 223, 223, 223, 32, 32, 223, 223);
	
	goTo(LEFTBOARD + 31, TOPBOARD + 5); printf("%c%c%c%c%c%c%c%c%c", 32, 219, 219, 223, 219, 219, 223, 219, 219);   //M   
	goTo(LEFTBOARD + 31, TOPBOARD + 6); printf("%c%c%c%c%c%c%c%c%c", 220, 219, 219, 32, 219, 219, 32, 219, 219);
	goTo(LEFTBOARD + 31, TOPBOARD + 7); printf("%c%c%c%c%c%c%c%c%c", 219, 219, 219, 32, 219, 219, 32, 219, 219);
	goTo(LEFTBOARD + 31, TOPBOARD + 8); printf("%c%c%c%c%c%c%c%c%c", 223, 223, 223, 32, 223, 223, 32, 223, 223);
	
	goTo(LEFTBOARD + 41, TOPBOARD + 5); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 223, 223);      //E
	goTo(LEFTBOARD + 41, TOPBOARD + 6); printf("%c%c%c%c%c%c%c", 220, 219, 219, 220, 220, 220, 220);
	goTo(LEFTBOARD + 41, TOPBOARD + 7); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + 41, TOPBOARD + 8); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);
	
	goTo(LEFTBOARD + 16, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 219, 219);      //O
	goTo(LEFTBOARD + 16, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 220, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 16, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 16, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);
	
	goTo(LEFTBOARD + 24, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 219, 219, 32, 32, 32, 219, 219);      //V
	goTo(LEFTBOARD + 24, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 219, 219, 32, 32, 220, 219, 219);
	goTo(LEFTBOARD + 24, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 223, 219, 220, 32, 219, 219, 219);
	goTo(LEFTBOARD + 24, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 32, 32, 223, 223, 223, 223, 32);
	
	goTo(LEFTBOARD + 32, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 32, 219, 219, 223, 223, 223, 223);      //E
	goTo(LEFTBOARD + 32, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 220, 219, 219, 220, 220, 220, 220);
	goTo(LEFTBOARD + 32, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 32, 32);
	goTo(LEFTBOARD + 32, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);
	
	goTo(LEFTBOARD + 40, TOPBOARD + 10); printf("%c%c%c%c%c%c%c", 219, 219, 223, 223, 219, 219, 32);      //R
	goTo(LEFTBOARD + 40, TOPBOARD + 11); printf("%c%c%c%c%c%c%c", 219, 219, 220, 220, 219, 219, 220);
	goTo(LEFTBOARD + 40, TOPBOARD + 12); printf("%c%c%c%c%c%c%c", 219, 219, 219, 32, 32, 219, 219);
	goTo(LEFTBOARD + 40, TOPBOARD + 13); printf("%c%c%c%c%c%c%c", 223, 223, 223, 32, 32, 223, 223);
	textcolor(7);
}

void printMenu()
{
	goTo(LEFTBOARD + 24, TOPBOARD + 18); textcolor(79); printf("  START GAME  "); textcolor(7); 
	goTo(LEFTBOARD + 24, TOPBOARD + 20); printf("  MODE  "); 
	goTo(LEFTBOARD + 24, TOPBOARD + 22); printf("  HIGHSCORES  "); 
	goTo(LEFTBOARD + 24, TOPBOARD + 24); printf("  OPTIONS  "); 
	goTo(LEFTBOARD + 24, TOPBOARD + 26); printf("  EXIT  ");
}

void printMode()
{
	goTo(LEFTBOARD + 20, TOPBOARD + 18); textcolor(79); printf("   MODE 1: CLASSIC   "); textcolor(7);
	goTo(LEFTBOARD + 20, TOPBOARD + 22); printf("   MODE 2: TIME   ");
	goTo(LEFTBOARD + 20, TOPBOARD + 26); printf("   MODE 3: PICKY MONSTER   ");
}

void moveMode()
{
	switch (choiceMenu){
		case UP: {
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				printf("   MODE 2: TIME   ");
			}
			if (setYMenu == TOPBOARD + 26){
				goTo(setXMenu, setYMenu);  
				printf("   MODE 3: PICKY MONSTER   ");
			}
			setYMenu -= 4;
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   MODE 1: CLASSIC   "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   MODE 2: TIME   "); textcolor(7);
			}
			break;
		}
		case DOWN: {
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu);  
				printf("   MODE 1: CLASSIC   ");
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				printf("   MODE 2: TIME   ");
			}
			setYMenu += 4;
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   MODE 2: TIME   "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 26){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   MODE 3: PICKY MONSTER   "); textcolor(7);
			}
			break;
		}
		case ENTER: {
			if (setYMenu == TOPBOARD + 18){
				choiceMode = 1;
			}
			if (setYMenu == TOPBOARD + 22){
				choiceMode = 2;
			}
			if (setYMenu == TOPBOARD + 26){
				choiceMode = 3;
			}
			break;
		}
	}	
}

void moveOptions(){
	switch (choiceMenu){
		case DOWN: {
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu);  
				if (switchMusic == ON){
					printf("   MUSIC: ON    ");
				}
				else{
					printf("   MUSIC: OFF   ");
				}
			}
			if (setYMenu < TOPBOARD + 22 )setYMenu += 4;
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("   RESET HIGHSCORES   "); textcolor(7);
			}
			break;
		}
		case UP: {
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu); 
				printf("   RESET HIGHSCORES   ");
			}
			if (setYMenu > TOPBOARD + 18 )setYMenu -= 4;
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu);  
				if (switchMusic == ON){
					textcolor(79); printf("   MUSIC: ON    "); textcolor(7);
				}
				else{
					textcolor(79); printf("   MUSIC: OFF   "); textcolor(7);
				}
			}
			break;
		}
		case ENTER: {
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu);  
				if (switchMusic == ON){
					switchMusic = OFF;
					textcolor(79); printf("   MUSIC: OFF   "); textcolor(7);
					PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
					music = 0;
				}
				else {
					switchMusic = ON;
					textcolor(79); printf("   MUSIC: ON    "); textcolor(7);
					music = 1;
				}
				choiceMenu = ESC;  // switch music xong out ra
			}
			if (setYMenu == TOPBOARD + 22){
				clrscr();
				setYMenu = TOPBOARD + 18;
				setXMenu = LEFTBOARD + 20;
				drawBoard();
				background();
				printResetTable();
				goTo(LEFTBOARD + 15, BOTTOMBOARD - 1); printf("Press the ESC key to return Menu");
				while(1){
					setCursor();
					getChoiceMenu();
					if (choiceMenu != NOPE) moveModeReset();
					if (choiceMenu == ESC || choiceMenu == ENTER) break;
				}
				clrscr();
				setYMenu = TOPBOARD + 18;
				setXMenu = LEFTBOARD + 20;
				choiceMenu = NOPE;
				printOptions();
				goTo(LEFTBOARD + 15, BOTTOMBOARD - 1); printf("Press the ESC key to return Menu");
			}
			break;
		}
	}
}

void menu(){
	drawBoard();
	background();
	printMenu();
}

void gameOver(){
	setCursor();
	music = 1;
	drawBoard();
	printGameOver();
	if (switchMusic == ON) PlaySound(TEXT("GAMEOVER.wav"), NULL, SND_SYNC);
	highscoresProcessing();
	goTo(LEFTBOARD + 15, BOTTOMBOARD - 1); printf("Press the ESC key to return Menu");
	while (1){
		getChoiceMenu();
		if (choiceMenu == ESC) break;
	}
}

void mode1() {
	setCursor();
	int check = 1;
	life = 3;
	score = 0;
	madnessSwitch = 0;
	inputchange = 0;
	min += 5;
	count += 5;
	
	
	setMonster();
	printMonster();
	drawWall();
	spawnFruit();	
	count++;
	printLifeScore();
	while (1){
		setCursor();
		printGuide();
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		if (check % 10 == 0){
			if (check % 3 == 0){
				spawnSpecial();
				count++;	
			}
			else {
				spawnFruit();	
				count++;
			}
		}
		printFruit();
	
		check++;
		
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}	
		
		
		
		Sleep(150 - speed());
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		checkFruit();
		printLifeScore();
		printMonster();
		moveFruit();
		
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		if (checkGame()){
			Sleep(1000);
			break;
		}
	}
	clrscr();
	gameOver();
}


void mode2() {
	setCursor();
	int check = 1;
	int checkTime = 0, checkTime2 = 0;
	timeCount = 60;
	score = 0;
	madnessSwitch = 0;
	inputchange = 0;
	minMode2 += 5;
	countMode2 += 5;
	
	
	
	setMonster();
	printMonster();
	drawWall();
	spawnFruitMode2();
	countMode2++;
	printTimeScore();
	while (1){
		setCursor();
		printGuideMode2();
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		
		if (check % 10 == 0){
			if (check % 3 == 0){
				spawnSpecialMode2();
				countMode2++;	
			}
			else {
				spawnFruitMode2();	
				countMode2++;
			}
		}
		printFruitMode2();
	
		check++;
		
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}	
		
		
		
		Sleep(150 - speed());
		checkTime += (110 - speed());
		if (checkTime / 780 > checkTime2) {
			timeCount--;
			checkTime2++;
		}
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		checkFruitMode2();
		printTimeScore();
		printMonster();
		moveFruitMode2();
		
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		if (checkGameMode2()){
			Sleep(1000);
			break;
		}
	}
	clrscr();
	gameOver();
}


void mode3() {
	setCursor();
	int check = 0;
	life = 3;
	score = 0;
	madnessSwitch = 0;
	inputchange = 0;
	needFruit = 1;
	typeFruit = 0;
	minMode3 += 5;
	countMode3 += 5;
	
	
	setMonster();
	printMonster();
	drawWall();
	fruitNeedToEat();
	printLifeScoreMode3();
	while (1){
		setCursor();
		printGuideMode3();
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		if (check % 10 == 0){
			spawnFruitMode3();	
			countMode3++;
		}
		printFruitMode3();
	
		check++;
		
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}	
		
		
		
		Sleep(150 - speed());
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		checkFruitMode3();
		fruitNeedToEat();
		printLifeScoreMode3();
		printMonster();
		moveFruitMode3();
		
		
		getChoice();
		if (choice != NOPE){
			movement();
			printMonster();
			deleteOldMonster();
		}
		
		if (checkGame()){
			Sleep(1000);
			break;
		}
	}
	clrscr();
	gameOver();
}


void moveMenu()
{	
	switch (choiceMenu){
	
		case UP: {
			if (setYMenu == TOPBOARD + 20){
				goTo(setXMenu, setYMenu);  
				printf("  MODE  ");
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				printf("  HIGHSCORES  ");
			}
			if (setYMenu == TOPBOARD + 24){
				goTo(setXMenu, setYMenu);  
				printf("  OPTIONS  ");
			}
			if (setYMenu == TOPBOARD + 26){
				goTo(setXMenu, setYMenu);  
				printf("  EXIT  ");
			}		
			
			setYMenu -= 2;
			
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu); 
				textcolor(79); printf("  START GAME  "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 20){
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  MODE  "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  HIGHSCORES  "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 24){
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  OPTIONS  "); textcolor(7);
			}
			break;
		}
		case DOWN: {
			if (setYMenu == TOPBOARD + 18){
				goTo(setXMenu, setYMenu);  
				printf("  START GAME  ");
			}
			if (setYMenu == TOPBOARD + 20){
				goTo(setXMenu, setYMenu);  
				printf("  MODE  ");
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				printf("  HIGHSCORES  ");
			}
			if (setYMenu == TOPBOARD + 24){
				goTo(setXMenu, setYMenu);  
				printf("  OPTIONS  ");
			}
			setYMenu += 2;
			if (setYMenu == TOPBOARD + 20){		
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  MODE  "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 22){
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  HIGHSCORES  "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 24){
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  OPTIONS  "); textcolor(7);
			}
			if (setYMenu == TOPBOARD + 26){
				goTo(setXMenu, setYMenu);  
				textcolor(79); printf("  EXIT  "); textcolor(7);
			}
			break;
		}
		case ENTER: {
			if (setYMenu == TOPBOARD + 18){    //Start game
				PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
				clrscr();
				if (choiceMode == 1) {
					choiceHiTable = choiceMode;
					mode1();
				}
				if (choiceMode == 2){
					choiceHiTable = choiceMode;
					mode2();
				}
				if (choiceMode == 3){
					choiceHiTable = choiceMode;
					mode3();
				}
				clrscr();
				setXMenu = LEFTBOARD + 24;
				setYMenu = TOPBOARD + 18;
				menu();
			}
			if (setYMenu == TOPBOARD + 20){		// Mode
				clrscr();
				setYMenu = TOPBOARD + 18;
				setXMenu = LEFTBOARD + 20;
				drawBoard();
				background();
				printMode();
				goTo(LEFTBOARD + 15, BOTTOMBOARD - 1); printf("Press the ESC key to return Menu");
				while(1){
					setCursor();
					getChoiceMenu();
					if (choiceMenu != NOPE) moveMode();
					if (choiceMenu == ESC || choiceMenu == ENTER) break;
				}
				clrscr();
				setXMenu = LEFTBOARD + 24;
				setYMenu = TOPBOARD + 18;
				menu();
			}
			if (setYMenu == TOPBOARD + 22){     //Highscores
				clrscr();
				setXMenu = LEFTBOARD + 10;
				setYMenu = TOPBOARD + 16;
				drawBoard();
				printHiscores();
				goTo(LEFTBOARD + 15, BOTTOMBOARD - 1); printf("Press the ESC key to return Menu");
				while(1){
					setCursor();
					getChoiceMenu();
					if (choiceMenu != NOPE) moveHitable();
					if (choiceMenu == ESC) break;
				}
				clrscr();
				setXMenu = LEFTBOARD + 24;
				setYMenu = TOPBOARD + 18;
				menu();
			}
			if (setYMenu == TOPBOARD + 24){		//OPTIONS
				clrscr();
				setYMenu = TOPBOARD + 18;
				setXMenu = LEFTBOARD + 20;
				printOptions();
				goTo(LEFTBOARD + 15, BOTTOMBOARD - 1); printf("Press the ESC key to return Menu");
				while(1){
					setCursor();
					getChoiceMenu();
					if (choiceMenu != NOPE) moveOptions();
					if (choiceMenu == ESC) break;
				}
				clrscr();
				setXMenu = LEFTBOARD + 24;
				setYMenu = TOPBOARD + 18;
				menu();
			}
			if (setYMenu == TOPBOARD + 26){		// Exit
				exitGame = 1;
				break;
			}
			break;
		}
	}
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = {0};
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &info);
}


int main(){
	resizeConsole(800, 600);
	setFontSize(19);
	setCursor();
	menu();
	while (1){
		setCursor();
		if (music == 1 && switchMusic == ON){
			PlaySound(TEXT("MENU.wav"), NULL, SND_ASYNC); // chay trong khi chuong trinh chay
			music = 0;
		}
		getChoiceMenu();
		if (choiceMenu != NOPE){
	
			moveMenu();
			
		}
		if (exitGame) break;
	}
	clrscr();
	return 0;
}
