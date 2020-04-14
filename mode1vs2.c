
#define LEFT 1
#define RIGHT 3
#define NOPE 0

#define TOPWALL 5
#define BOTTOMWALL 30
#define LEFTWALL 42
#define RIGHTWALL 67 

#define APPLE 1
#define WALNUT 2
#define ORANGE 3
#define BOOM 4
#define MADNESS 5
#define ADDLIFE 6
#define TIMEBONUSMODE2 7
#define REVERSE 7
#define REVERSEMODE2 6

#define ON 1
#define OFF 0
#define RESET 4


int switchMusic = ON;
int choice;
int setX = LEFTWALL + 7;
int setY = BOTTOMWALL - 2;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct coordinates {
	int x;
	int y;
	int shape;
	int swit;
} coor;

coor monster[30];
coor oldMonster[30];

// function can dung

void textcolor(int x)   // set mau ki tu
{ 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, x);
}

void goTo(int x, int y)   // di chuyen den toa do x, y 
{
	HANDLE EX;
	EX = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD location = {x, y};
	SetConsoleCursorPosition(EX, location);
}

void clrscr()   		 // xoa toan bo man hinh
{
	system("cls");
}

// ABOUT MONSTER

void setMonster()
{
	int i;
	monster[0].x = setX; 						monster[0].y = setY;						monster[0].shape = 223;
	monster[1].x = monster[0].x + 5;			monster[1].y = monster[0].y;				monster[1].shape = 223;
	monster[2].x = monster[0].x;				monster[2].y = monster[0].y + 1;			monster[2].shape = 242;
	monster[3].x = monster[0].x + 1;			monster[3].y = monster[0].y + 1;			monster[3].shape = 202;
	monster[4].x = monster[0].x + 2;			monster[4].y = monster[0].y + 1;			monster[4].shape = 202;
	monster[5].x = monster[0].x + 3;			monster[5].y = monster[0].y + 1;			monster[5].shape = 202;
	monster[6].x = monster[0].x + 4;			monster[6].y = monster[0].y + 1;			monster[6].shape = 202;
	monster[7].x = monster[0].x + 5;			monster[7].y = monster[0].y + 1;			monster[7].shape = 243;
}

void printMonster()
{
	goTo(monster[0].x, monster[0].y);
	textcolor(2); printf("%c", monster[0].shape); textcolor(7);
	
	goTo(monster[1].x, monster[1].y);
	textcolor(2); printf("%c", monster[1].shape); textcolor(7);
	
	goTo(monster[2].x, monster[2].y);
	textcolor(10); printf("%c", monster[2].shape); textcolor(7);
	
	goTo(monster[3].x, monster[3].y);
	textcolor(8); printf("%c", monster[3].shape); textcolor(7);
	
	goTo(monster[4].x, monster[4].y);
	textcolor(8); printf("%c", monster[4].shape); textcolor(7);
	 
	goTo(monster[5].x, monster[5].y);
	textcolor(8); printf("%c", monster[5].shape); textcolor(7);
	
	goTo(monster[6].x, monster[6].y);
	textcolor(8); printf("%c", monster[6].shape); textcolor(7);
	
	goTo(monster[7].x, monster[7].y);
	textcolor(10); printf("%c", monster[7].shape); textcolor(7);
	
}

void deleteOldMonster()
{
	int i;
	for (i = 0; i <= 7; i++){
		goTo(oldMonster[i].x, oldMonster[i].y);
		printf("%c", 32);
	}
	
}

void drawWall()   // ve khung phia ngoai
{
	int i; int j;
	for (i = TOPWALL + 1; i < BOTTOMWALL; i++){
		goTo(LEFTWALL, i);
		printf("%c", 221);
		goTo(RIGHTWALL, i);
		printf("%c", 222);
	}
	for (i = LEFTWALL; i <= RIGHTWALL; i++){
		goTo(i, TOPWALL);
		printf("%c", 220);
		goTo(i, BOTTOMWALL);
		printf("%c", 223);
	}
	
	//Tuong phu ben trai
	for (i = TOPWALL + 1; i < BOTTOMWALL; i++){     
		goTo(LEFTWALL - 1, i);
		printf("%c", 186);
		goTo(LEFTWALL - 28, i);
		printf("%c", 186);
	}
	for (i = LEFTWALL - 28; i < LEFTWALL - 1; i++){
		goTo(i, TOPWALL);
		printf("%c", 205);
		goTo(i, BOTTOMWALL);
		printf("%c", 205);
	}  
	goTo(LEFTWALL - 28, TOPWALL); printf("%c", 201);
	goTo(LEFTWALL - 1, TOPWALL); printf("%c", 187);
	goTo(LEFTWALL - 28, BOTTOMWALL); printf("%c", 200);
	goTo(LEFTWALL - 1, BOTTOMWALL); printf("%c", 188);	
	
	//Tuong phu ben phai
	for (i = TOPWALL + 1; i < BOTTOMWALL; i++){     
		goTo(RIGHTWALL + 1, i);
		printf("%c", 186);
		goTo(RIGHTWALL + 19, i);
		printf("%c", 186);
	}
	for (i = RIGHTWALL + 1; i < RIGHTWALL + 19; i++){
		goTo(i, TOPWALL);
		printf("%c", 205);
		goTo(i, BOTTOMWALL);
		printf("%c", 205);
	}  
	goTo(RIGHTWALL + 1, TOPWALL); printf("%c", 201);
	goTo(RIGHTWALL + 19, TOPWALL); printf("%c", 187);
	goTo(RIGHTWALL + 1, BOTTOMWALL); printf("%c", 200);
	goTo(RIGHTWALL + 19, BOTTOMWALL); printf("%c", 188);
	
}

int inputchange = 0;

void getChoice ()    // nhan phim dieu khien cua nguoi dung
{
	int key;
	if (kbhit()){
		key = getch();
		if (key == 'a' || key == 'A' || key == 75 || key == 'd' || key == 'D' || key == 77){
			if(inputchange == 0){
				if ((key == 'a' || key == 'A' || key == 75) && setX > (LEFTWALL + 1)) choice = LEFT;
				if ((key == 'd' || key == 'D' || key == 77) && setX < (RIGHTWALL - 7)) choice = RIGHT;
			}
			else choice = NOPE;
			if(inputchange == 1){
				if ((key == 'a' || key == 'A' || key == 75) && setX < (RIGHTWALL - 7)) choice = RIGHT; 
				if ((key == 'd' || key == 'D' || key == 77) && setX > (LEFTWALL + 1)) choice = LEFT; 
			}
		}
		else choice = NOPE;
	}
	else choice = NOPE;
}


void movement()   // di chuyen cua monster
{
	int i;
	for (i = 0; i <= 7; i++){
		oldMonster[i].x = monster[i].x;
		oldMonster[i].y = monster[i].y;
	}
	switch (choice){
		case LEFT: {
			setX -= 6;
			setMonster();
			break;
		}
		case RIGHT: {
			setX += 6;
			setMonster();
			break;
		}
	}
}

// ABOUT FRUIT, LIFE AND SCORE



coor fruit[9999999];
coor oldFruit[9999999];

int count;
int min;
int life;
int score;
int madnessSwitch;

int speed(){
	return ((score / 100 * 2) + (madnessSwitch == 1 ? 15 : 0)) ;
}

void spawnFruit()
{
	srand(time(NULL));
	fruit[count].swit =  rand() % 2;
	fruit[count].y = TOPWALL + 1;
	fruit[count].shape = 1 + rand() % 3;
	if (fruit[count].shape == APPLE){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 3);
		if (fruit[count].x == RIGHTWALL - 3 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
	}
	if (fruit[count].shape == WALNUT){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 1);
		if (fruit[count].x == RIGHTWALL - 1 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
	}
	if (fruit[count].shape == ORANGE){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruit[count].x == RIGHTWALL - 2 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
	}	
}

void spawnSpecial(){
	srand(time(NULL));
	fruit[count].swit =  rand() % 2;
	fruit[count].y = TOPWALL + 1;
	fruit[count].shape = 4 + rand() % 4;
	if (fruit[count].shape == BOOM){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 1);
		if (fruit[count].x == RIGHTWALL - 1 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
		
	}
	if (fruit[count].shape == ADDLIFE){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruit[count].x == RIGHTWALL - 2 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
	}
	if (fruit[count].shape == MADNESS){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruit[count].x == RIGHTWALL - 2 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
	}
	if (fruit[count].shape == REVERSE){
		srand(time(NULL));
		fruit[count].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruit[count].x == RIGHTWALL - 2 && fruit[count].swit == 0) fruit[count].swit = 1;
		if (fruit[count].x == LEFTWALL + 1 && fruit[count].swit == 1) fruit[count].swit = 0;
	}
}

void printFruit(){
	int i;
	for (i = min; i < count + 1; i++){
		goTo(fruit[i].x, fruit[i].y);
		if (fruit[i].shape == APPLE){
			textcolor(2); printf("%c%c", 32, 194); textcolor(7);
			goTo(fruit[i].x , fruit[i].y + 1);
			textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
			
		}
		if (fruit[i].shape == WALNUT){
			textcolor(8); printf("%c", 235); textcolor(7);
			
		}
		if (fruit[i].shape == ORANGE){
			textcolor(238); printf("%c%c", 32, 32); textcolor(7);
			
		}
		if (fruit[i].shape == BOOM){
			printf("%c", 203);
			goTo(fruit[i].x, fruit[i].y + 1);
			printf("%c", 219);
			
		}
		if (fruit[i].shape == ADDLIFE){
			textcolor(79); printf("%c%c", 43, 43); textcolor(7);
			
		}
		if (fruit[i].shape == MADNESS){
			textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
			goTo(fruit[i].x, fruit[i].y + 1);
			textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
			
		}
		if (fruit[i].shape == REVERSE){
			textcolor(154); printf("%c", 60); textcolor(7);
			goTo(fruit[i].x + 1, fruit[i].y);
			textcolor(169); printf("%c", 62); textcolor(7);
			
		}
		oldFruit[i] = fruit[i];
	}
}

void madnessMove()
{
	int i;
	for (i = min; i < count + 1; i++){    //  0 qua trai, 1 qua phai
		if (fruit[i].x <= LEFTWALL + 1){
			fruit[i].swit = 1;
			fruit[i].x++;
		}
		if (fruit[i].x >= RIGHTWALL - 3){
			fruit[i].swit = 0;
			fruit[i].x--;	
		}	
		
		goTo(oldFruit[i].x, oldFruit[i].y);
		if (fruit[i].shape == APPLE){
			printf("%c%c", 32, 32);
			goTo(oldFruit[i].x, oldFruit[i].y + 1);
			printf("%c%c%c", 32, 32, 32);
			
		}
		if (fruit[i].shape == WALNUT){
			printf("%c", 32); 
			
		}
		if (fruit[i].shape == ORANGE){
			printf("%c%c", 32, 32);
			
		}
		if (fruit[i].shape == BOOM){
			printf("%c", 32);
			goTo(oldFruit[i].x, oldFruit[i].y + 1);
			printf("%c", 32);
			
		}
		if (fruit[i].shape == ADDLIFE){
			printf("%c%c", 32, 32);
			
		}
		if (fruit[i].shape == MADNESS){
			printf("%c%c", 32, 32);
			goTo(oldFruit[i].x, oldFruit[i].y + 1);
			printf("%c%c", 32, 32);
			
		}
		if (fruit[i].shape == REVERSE){
			printf("%c%c", 32, 32);	
			
		}			
	}
}

void normalMove(){
	int i;
	for (i = min; i < count + 1; i++){
		goTo(oldFruit[i].x, oldFruit[i].y);
		if (fruit[i].shape == APPLE){
			printf("%c%c", 32, 32);
			goTo(oldFruit[i].x, oldFruit[i].y + 1);
			printf("%c%c%c", 32, 32, 32);	
		}
		if (fruit[i].shape == WALNUT){
			printf("%c", 32);
			
		}
		if (fruit[i].shape == ORANGE){
			printf("%c%c", 32, 32);
			
		}
		if (fruit[i].shape == BOOM){
			printf("%c", 32);
			goTo(oldFruit[i].x, oldFruit[i].y + 1);
			printf("%c", 32);
			
		}
		if (fruit[i].shape == ADDLIFE){
			printf("%c%c", 32, 32);
			
		}
		if (fruit[i].shape == MADNESS){
			printf("%c%c", 32, 32);
			goTo(oldFruit[i].x, oldFruit[i].y + 1);
			printf("%c%c", 32, 32);
			
		}
		if (fruit[i].shape == REVERSE){
			printf("%c%c", 32, 32);
			
		}
	}
}



void moveFruit(){
	if (madnessSwitch == 1)
		madnessMove();
	else normalMove();
}

int conditions(int i){
	if (fruit[i].shape == APPLE){
		if (fruit[i].x == monster[0].x && (fruit[i].y + 1 == monster[0].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[0].x && (fruit[i].y + 1 == monster[0].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[0].x && (fruit[i].y + 1 == monster[0].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		
		
		if (fruit[i].x == monster[1].x && (fruit[i].y + 1 == monster[1].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[1].x && (fruit[i].y + 1 == monster[1].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[1].x && (fruit[i].y + 1 == monster[1].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x == monster[2].x && (fruit[i].y + 1 == monster[2].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[2].x && (fruit[i].y + 1 == monster[2].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[2].x && (fruit[i].y + 1 == monster[2].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x == monster[3].x && (fruit[i].y + 1 == monster[3].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[3].x && (fruit[i].y + 1 == monster[3].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[3].x && (fruit[i].y + 1 == monster[3].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		
		if (fruit[i].x == monster[4].x && (fruit[i].y + 1 == monster[4].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[4].x && (fruit[i].y + 1 == monster[4].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[4].x && (fruit[i].y + 1 == monster[4].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
	
		if (fruit[i].x == monster[5].x && (fruit[i].y + 1 == monster[5].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[5].x && (fruit[i].y + 1 == monster[5].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[5].x && (fruit[i].y + 1 == monster[5].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}	
		
		if (fruit[i].x == monster[6].x && (fruit[i].y + 1 == monster[6].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[6].x && (fruit[i].y + 1 == monster[6].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[6].x && (fruit[i].y + 1 == monster[6].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x == monster[7].x && (fruit[i].y + 1 == monster[7].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[7].x && (fruit[i].y + 1 == monster[7].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 2 == monster[7].x && (fruit[i].y + 1 == monster[7].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}		
		if (fruit[i].y + 1 == BOTTOMWALL - 1){
			life--;
			if (switchMusic == ON){
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		
	}

	if (fruit[i].shape == WALNUT){
		if (fruit[i].x == monster[0].x && fruit[i].y == monster[0].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[1].x && fruit[i].y == monster[1].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[2].x && fruit[i].y == monster[2].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[3].x && fruit[i].y == monster[3].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[4].x && fruit[i].y == monster[4].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[5].x && fruit[i].y == monster[5].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[6].x && fruit[i].y == monster[6].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].x == monster[7].x && fruit[i].y == monster[7].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruit[i].y == BOTTOMWALL - 1){
			life--;
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}		
	}

	if (fruit[i].shape == ORANGE){
		if (fruit[i].x == monster[0].x && (fruit[i].y == monster[0].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[0].x && (fruit[i].y == monster[0].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
		if (fruit[i].x == monster[1].x && (fruit[i].y == monster[1].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[1].x && (fruit[i].y == monster[1].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[2].x && (fruit[i].y == monster[2].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[2].x && (fruit[i].y == monster[2].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[3].x && (fruit[i].y == monster[3].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[3].x && (fruit[i].y == monster[3].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
		if (fruit[i].x == monster[4].x && (fruit[i].y == monster[4].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[4].x && (fruit[i].y == monster[4].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruit[i].x == monster[5].x && (fruit[i].y == monster[5].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[5].x && (fruit[i].y == monster[5].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruit[i].x == monster[6].x && (fruit[i].y == monster[6].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[6].x && (fruit[i].y == monster[6].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruit[i].x == monster[7].x && (fruit[i].y == monster[7].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[7].x && (fruit[i].y == monster[7].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruit[i].y == BOTTOMWALL - 1){
			life--;
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
	}

	if (fruit[i].shape == BOOM){
		if (fruit[i].x == monster[0].x && fruit[i].y + 1 == monster[0].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[1].x && fruit[i].y + 1 == monster[1].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[2].x && fruit[i].y + 1 == monster[2].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[3].x && fruit[i].y + 1 == monster[3].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[4].x && fruit[i].y + 1 == monster[4].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[5].x && fruit[i].y + 1 == monster[5].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[6].x && fruit[i].y + 1 == monster[6].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].x == monster[7].x && fruit[i].y + 1 == monster[7].y - 1) {
			life = 0;
			return 1;
		}
		if (fruit[i].y + 1 == BOTTOMWALL - 1){
			return 1;
		}	
	}
	
	if (fruit[i].shape == ADDLIFE){
		if (fruit[i].x == monster[0].x && (fruit[i].y == monster[0].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[0].x && (fruit[i].y == monster[0].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++;
	 		return 1;
	 	}
		if (fruit[i].x == monster[1].x && (fruit[i].y == monster[1].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[1].x && (fruit[i].y == monster[1].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++;
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[2].x && (fruit[i].y == monster[2].y - 1)) {
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[2].x && (fruit[i].y == monster[2].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++;
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[3].x && (fruit[i].y == monster[3].y - 1)) {
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[3].x && (fruit[i].y == monster[3].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++;
	 		return 1;
	 	}
		if (fruit[i].x == monster[4].x && (fruit[i].y == monster[4].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[4].x && (fruit[i].y == monster[4].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++;
	 		return 1;	
		}
		if (fruit[i].x == monster[5].x && (fruit[i].y == monster[5].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[5].x && (fruit[i].y == monster[5].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++;
	 		return 1;	
		}
		if (fruit[i].x == monster[6].x && (fruit[i].y == monster[6].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[6].x && (fruit[i].y == monster[6].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++; 
	 		return 1;	
		}
		if (fruit[i].x == monster[7].x && (fruit[i].y == monster[7].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		life++;
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[7].x && (fruit[i].y == monster[7].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			life++; 
	 		return 1;	
		}
		if (fruit[i].y == BOTTOMWALL - 1){
			return 1;
		}
	}
	
	if (fruit[i].shape == MADNESS){
		if (fruit[i].x == monster[0].x && (fruit[i].y + 1 == monster[0].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[0].x && (fruit[i].y + 1 == monster[0].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
		if (fruit[i].x == monster[1].x && (fruit[i].y + 1 == monster[1].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[1].x && (fruit[i].y + 1 == monster[1].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[2].x && (fruit[i].y + 1 == monster[2].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[2].x && (fruit[i].y + 1 == monster[2].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[3].x && (fruit[i].y + 1 == monster[3].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[3].x && (fruit[i].y + 1 == monster[3].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
		if (fruit[i].x == monster[4].x && (fruit[i].y + 1 == monster[4].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[4].x && (fruit[i].y + 1 == monster[4].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruit[i].x == monster[5].x && (fruit[i].y + 1 == monster[5].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[5].x && (fruit[i].y + 1 == monster[5].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruit[i].x == monster[6].x && (fruit[i].y + 1 == monster[6].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[6].x && (fruit[i].y + 1 == monster[6].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruit[i].x == monster[7].x && (fruit[i].y + 1 == monster[7].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[7].x && (fruit[i].y + 1 == monster[7].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruit[i].y + 1 == BOTTOMWALL - 1){
			return 1;
		}
	}
	
	if (fruit[i].shape == REVERSE){
		if (fruit[i].x == monster[0].x && (fruit[i].y == monster[0].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[0].x && (fruit[i].y == monster[0].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
		if (fruit[i].x == monster[1].x && (fruit[i].y == monster[1].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[1].x && (fruit[i].y == monster[1].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[2].x && (fruit[i].y == monster[2].y - 1)) {
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[2].x && (fruit[i].y == monster[2].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
	 	if (fruit[i].x == monster[3].x && (fruit[i].y == monster[3].y - 1)) {
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[3].x && (fruit[i].y == monster[3].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
		if (fruit[i].x == monster[4].x && (fruit[i].y == monster[4].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[4].x && (fruit[i].y == monster[4].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruit[i].x == monster[5].x && (fruit[i].y == monster[5].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[5].x && (fruit[i].y == monster[5].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruit[i].x == monster[6].x && (fruit[i].y == monster[6].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[6].x && (fruit[i].y == monster[6].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruit[i].x == monster[7].x && (fruit[i].y == monster[7].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruit[i].x + 1 == monster[7].x && (fruit[i].y == monster[7].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruit[i].y == BOTTOMWALL - 1){
			return 1;
		}
	}
	return 0;
}

void checkFruit(){
	int i;
	for (i = min; i < count + 1; i++){
		if (conditions(i)){
			goTo(fruit[i].x, fruit[i].y);
			if (fruit[i].shape == APPLE){
				printf("%c%c", 32, 32);
				goTo(fruit[i].x, fruit[i].y + 1);
				printf("%c%c%c", 32, 32, 32);
				
			}
			if (fruit[i].shape == WALNUT){
				printf("%c", 32);
				
			}
			if (fruit[i].shape == ORANGE){
				printf("%c%c", 32, 32);
				
			}
			if (fruit[i].shape == BOOM){
				printf("%c", 32);
				goTo(fruit[i].x, fruit[i].y + 1);
				printf("%c", 32);
				
			}
			if (fruit[i].shape == ADDLIFE){
				printf("%c%c", 32, 32);
				
			}
			if (fruit[i].shape == MADNESS){
				printf("%c%c", 32, 32);
				
				goTo(fruit[i].x, fruit[i].y + 1);
				printf("%c%c", 32, 32);
				
			}
			if (fruit[i].shape == REVERSE){
				printf("%c%c", 32, 32);
				
			}
			min++;
		}
		else {
			fruit[i].y++;
			if(madnessSwitch == 1){
				if(fruit[i].swit == 0)
					fruit[i].x--;
				if(fruit[i].swit == 1)
					fruit[i].x++;
			}
		}
	}
}

void printLifeScore(){
	goTo(RIGHTWALL + 5, TOPWALL + 7);
	printf("SCORES: %d", score);
	goTo(RIGHTWALL + 5, TOPWALL + 10);
	printf("LIFE: %d", life);
	
}

int checkGame(){
	if (life == 0) return 1;
	return 0;
}


void printGuide(){
	goTo(LEFTWALL - 22, TOPWALL + 2);
	textcolor(2); printf("%c%c", 32, 194); textcolor(7);
	goTo(LEFTWALL - 22, TOPWALL + 3);
	textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 3);
	printf(" 10 point");

	goTo(LEFTWALL - 22, TOPWALL + 5);	
	textcolor(238); printf("%c%c", 32, 32); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 5);
	printf(" 20 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 7);
	textcolor(8); printf("%c", 235); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 7);
	printf(" 30 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 8);
	printf("%c", 203);
	goTo(LEFTWALL - 22, TOPWALL + 9);
	printf("%c", 219);
	goTo(LEFTWALL - 17, TOPWALL + 9);
	printf(" Game over");
	
	goTo(LEFTWALL - 22, TOPWALL + 11);
	textcolor(79); printf("%c%c", 43, 43); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 11);
	printf(" +1 life");
	
	goTo(LEFTWALL - 25, TOPWALL + 14);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 25, TOPWALL + 15);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 20, TOPWALL + 14);
	printf(" Mad move");
	goTo(LEFTWALL - 20, TOPWALL + 15);
	printf(" & x3 point");
	
	goTo(LEFTWALL - 25, TOPWALL + 18);
	textcolor(154); printf("%c", 60); textcolor(7);
	goTo(LEFTWALL - 24, TOPWALL + 18);
	textcolor(169); printf("%c", 62); textcolor(7);
	goTo(LEFTWALL - 20, TOPWALL + 18);
	printf(" Reverse control");
	goTo(LEFTWALL - 20, TOPWALL + 19);
	printf(" & x2 point");
	
	goTo(LEFTWALL - 25, TOPWALL + 21);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 25, TOPWALL + 22);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 22, TOPWALL + 22); printf("+");
	goTo(LEFTWALL - 20, TOPWALL + 22);
	textcolor(154); printf("%c", 60); textcolor(7);
	goTo(LEFTWALL - 19, TOPWALL + 22);
	textcolor(169); printf("%c", 62); textcolor(7);
	goTo(LEFTWALL - 16, TOPWALL + 22);
	printf(" x5 point");	
}











// Bat dau Mode 2


coor fruitMode2[9999999];
coor oldFruitMode2[9999999];

int countMode2;
int minMode2;
int timeCount;


void printGuideMode2(){
	goTo(LEFTWALL - 22, TOPWALL + 2);
	textcolor(2); printf("%c%c", 32, 194); textcolor(7);
	goTo(LEFTWALL - 22, TOPWALL + 3);
	textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 3);
	printf(" 10 point");

	goTo(LEFTWALL - 22, TOPWALL + 5);	
	textcolor(238); printf("%c%c", 32, 32); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 5);
	printf(" 20 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 7);
	textcolor(8); printf("%c", 235); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 7);
	printf(" 30 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 8);
	printf("%c", 203);
	goTo(LEFTWALL - 22, TOPWALL + 9);
	printf("%c", 219);
	goTo(LEFTWALL - 17, TOPWALL + 9);
	printf(" Game over");
	
	goTo(LEFTWALL - 22, TOPWALL + 11);
	printf("%c%c%c", 40, 32, 41);
	goTo(LEFTWALL - 21, TOPWALL + 11);
	textcolor(112); printf("%c", 53); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 11);
	printf(" +5 second");
	
	goTo(LEFTWALL - 25, TOPWALL + 14);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 25, TOPWALL + 15);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 20, TOPWALL + 14);
	printf(" Mad move");
	goTo(LEFTWALL - 20, TOPWALL + 15);
	printf(" & x3 point");
	
	goTo(LEFTWALL - 25, TOPWALL + 18);
	textcolor(154); printf("%c", 60); textcolor(7);
	goTo(LEFTWALL - 24, TOPWALL + 18);
	textcolor(169); printf("%c", 62); textcolor(7);
	goTo(LEFTWALL - 20, TOPWALL + 18);
	printf(" Reverse control");
	goTo(LEFTWALL - 20, TOPWALL + 19);
	printf(" & x2 point");
	
	goTo(LEFTWALL - 25, TOPWALL + 21);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 25, TOPWALL + 22);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 22, TOPWALL + 22); printf("+");
	goTo(LEFTWALL - 20, TOPWALL + 22);
	textcolor(154); printf("%c", 60); textcolor(7);
	goTo(LEFTWALL - 19, TOPWALL + 22);
	textcolor(169); printf("%c", 62); textcolor(7);
	goTo(LEFTWALL - 16, TOPWALL + 22);
	printf(" x5 point");	
}


void spawnFruitMode2()
{
	srand(time(NULL));
	fruitMode2[countMode2].swit =  rand() % 2;
	fruitMode2[countMode2].y = TOPWALL + 1;
	fruitMode2[countMode2].shape = 1 + rand() % 3;
	if (fruitMode2[countMode2].shape == APPLE){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 3);
		if (fruitMode2[countMode2].x == RIGHTWALL - 3 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0;
	}
	if (fruitMode2[countMode2].shape == WALNUT){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 1);
		if (fruitMode2[countMode2].x == RIGHTWALL - 1 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0;
	}
	if (fruitMode2[countMode2].shape == ORANGE){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode2[countMode2].x == RIGHTWALL - 2 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0;
	}

}

void spawnSpecialMode2(){
	srand(time(NULL));
	fruitMode2[countMode2].swit =  rand() % 2;
	fruitMode2[countMode2].y = TOPWALL + 1;
	fruitMode2[countMode2].shape = 4 + rand() % 4;	
	if (fruitMode2[countMode2].shape == BOOM){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 1);
		if (fruitMode2[countMode2].x == RIGHTWALL - 1 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0;
		
	}
	if (fruitMode2[countMode2].shape == MADNESS){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode2[countMode2].x == RIGHTWALL - 2 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0; 
	}
	if (fruitMode2[countMode2].shape == REVERSEMODE2){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode2[countMode2].x == RIGHTWALL - 2 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0; 
	}
	if (fruitMode2[countMode2].shape == TIMEBONUSMODE2){
		srand(time(NULL));
		fruitMode2[countMode2].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 3);
		if (fruitMode2[countMode2].x == RIGHTWALL - 3 && fruitMode2[countMode2].swit == 0) fruitMode2[countMode2].swit = 1;
		if (fruitMode2[countMode2].x == LEFTWALL + 1 && fruitMode2[countMode2].swit == 1) fruitMode2[countMode2].swit = 0; 
	}
}

void printFruitMode2(){
	int i;
	for (i = minMode2; i < countMode2 + 1; i++){
		goTo(fruitMode2[i].x, fruitMode2[i].y);
		if (fruitMode2[i].shape == APPLE){
			textcolor(2); printf("%c%c", 32, 194); textcolor(7);
			goTo(fruitMode2[i].x , fruitMode2[i].y + 1);
			textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
			
		}
		if (fruitMode2[i].shape == WALNUT){
			textcolor(8); printf("%c", 235); textcolor(7);
			
		}
		if (fruitMode2[i].shape == ORANGE){
			textcolor(238); printf("%c%c", 32, 32); textcolor(7);
			
		}
		if (fruitMode2[i].shape == BOOM){
			printf("%c", 203);
			goTo(fruitMode2[i].x, fruitMode2[i].y + 1);
			printf("%c", 219);
			
		}
		if (fruitMode2[i].shape == MADNESS){
			textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
			goTo(fruitMode2[i].x, fruitMode2[i].y + 1);
			textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
			
		}
		if (fruitMode2[i].shape == REVERSEMODE2){
			textcolor(154); printf("%c", 60); textcolor(7);
			goTo(fruitMode2[i].x + 1, fruitMode2[i].y);
			textcolor(169); printf("%c", 62); textcolor(7);
			
		}
		if (fruitMode2[i].shape == TIMEBONUSMODE2){
			printf("%c%c%c", 40, 32, 41);
			goTo(fruitMode2[i].x + 1, fruitMode2[i].y);
			textcolor(112); printf("%c", 53); textcolor(7);
			
		}
		oldFruitMode2[i] = fruitMode2[i];
	}
}

void madnessMoveMode2()
{
	int i;
	for (i = minMode2; i < countMode2 + 1; i++){    //  0 qua trai, 1 qua phai
		if (fruitMode2[i].x <= LEFTWALL + 1){
			fruitMode2[i].swit = 1;
			fruitMode2[i].x++;
		}
		if (fruitMode2[i].x >= RIGHTWALL - 3){
			fruitMode2[i].swit = 0;
			fruitMode2[i].x--;	
		}	
		
		goTo(oldFruitMode2[i].x, oldFruitMode2[i].y);
		if (fruitMode2[i].shape == APPLE){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode2[i].x, oldFruitMode2[i].y + 1);
			printf("%c%c%c", 32, 32, 32);
			
		}
		if (fruitMode2[i].shape == WALNUT){
			printf("%c", 32);
			
		}
		if (fruitMode2[i].shape == ORANGE){
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode2[i].shape == BOOM){
			printf("%c", 32);
			goTo(oldFruitMode2[i].x, oldFruitMode2[i].y + 1);
			printf("%c", 32);
			
		}
		if (fruitMode2[i].shape == MADNESS){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode2[i].x, oldFruitMode2[i].y + 1);
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode2[i].shape == REVERSEMODE2){
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode2[i].shape == TIMEBONUSMODE2){
			printf("%c%c%c", 32, 32, 32);
			
		}
	}
	//	goTo(0, 10);
}

void normalMoveMode2(){
	int i;
	for (i = minMode2; i < countMode2 + 1; i++){
		goTo(oldFruitMode2[i].x, oldFruitMode2[i].y);
		if (fruitMode2[i].shape == APPLE){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode2[i].x, oldFruitMode2[i].y + 1);
			printf("%c%c%c", 32, 32, 32);
			
		}
		if (fruitMode2[i].shape == WALNUT){
			printf("%c", 32);
			
		}
		if (fruitMode2[i].shape == ORANGE){
			printf("%c%c", 32, 32);	
		}
		if (fruitMode2[i].shape == BOOM){
			printf("%c", 32);
			goTo(oldFruitMode2[i].x, oldFruitMode2[i].y + 1);
			printf("%c", 32);
			
		}
		if (fruitMode2[i].shape == MADNESS){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode2[i].x, oldFruitMode2[i].y + 1);
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode2[i].shape == REVERSEMODE2){
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode2[i].shape == TIMEBONUSMODE2){
			printf("%c%c%c", 32, 32, 32);
			
		}
	//	goTo(0, 10);
	}
}

void moveFruitMode2(){
	if (madnessSwitch == 1)
		madnessMoveMode2();
	else normalMoveMode2();
}

int conditionsMode2(int i){
	if (fruitMode2[i].shape == APPLE){
		if (fruitMode2[i].x == monster[0].x && (fruitMode2[i].y + 1 == monster[0].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[0].x && (fruitMode2[i].y + 1 == monster[0].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[0].x && (fruitMode2[i].y + 1 == monster[0].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		
		
		if (fruitMode2[i].x == monster[1].x && (fruitMode2[i].y + 1 == monster[1].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[1].x && (fruitMode2[i].y + 1 == monster[1].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[1].x && (fruitMode2[i].y + 1 == monster[1].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		
		if (fruitMode2[i].x == monster[2].x && (fruitMode2[i].y + 1 == monster[2].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[2].x && (fruitMode2[i].y + 1 == monster[2].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[2].x && (fruitMode2[i].y + 1 == monster[2].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		
		if (fruitMode2[i].x == monster[3].x && (fruitMode2[i].y + 1 == monster[3].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[3].x && (fruitMode2[i].y + 1 == monster[3].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[3].x && (fruitMode2[i].y + 1 == monster[3].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		
		if (fruitMode2[i].x == monster[4].x && (fruitMode2[i].y + 1 == monster[4].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[4].x && (fruitMode2[i].y + 1 == monster[4].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[4].x && (fruitMode2[i].y + 1 == monster[4].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
	
		if (fruitMode2[i].x == monster[5].x && (fruitMode2[i].y + 1 == monster[5].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[5].x && (fruitMode2[i].y + 1 == monster[5].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[5].x && (fruitMode2[i].y + 1 == monster[5].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}	
		
		if (fruitMode2[i].x == monster[6].x && (fruitMode2[i].y + 1 == monster[6].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[6].x && (fruitMode2[i].y + 1 == monster[6].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[6].x && (fruitMode2[i].y + 1 == monster[6].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		
		if (fruitMode2[i].x == monster[7].x && (fruitMode2[i].y + 1 == monster[7].y - 1)) {
	 		score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[7].x && (fruitMode2[i].y + 1 == monster[7].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[7].x && (fruitMode2[i].y + 1 == monster[7].y - 1)){
			score += 10 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		return 1;
		}
				
		if (fruitMode2[i].y + 1 == BOTTOMWALL - 1){
			return 1;
		}
		
	}

	if (fruitMode2[i].shape == WALNUT){
		if (fruitMode2[i].x == monster[0].x && fruitMode2[i].y == monster[0].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[1].x && fruitMode2[i].y == monster[1].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[2].x && fruitMode2[i].y == monster[2].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[3].x && fruitMode2[i].y == monster[3].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[4].x && fruitMode2[i].y == monster[4].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[5].x && fruitMode2[i].y == monster[5].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[6].x && fruitMode2[i].y == monster[6].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].x == monster[7].x && fruitMode2[i].y == monster[7].y - 1) {
			score += 30 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
			return 1;
		}
		if (fruitMode2[i].y == BOTTOMWALL - 1){
			return 1;
		}		
	}

	if (fruitMode2[i].shape == ORANGE){
		if (fruitMode2[i].x == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
		if (fruitMode2[i].x == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
	 	if (fruitMode2[i].x == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
	 	if (fruitMode2[i].x == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
	 	}
		if (fruitMode2[i].x == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)) {
	 		score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
	 		if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)){
			score += 20 * ((inputchange == 1? 2 : 1) + (madnessSwitch == 1 ? 3: 0));
			if (switchMusic == ON) {
	 			if(madnessSwitch == 0)
	 			PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
	 		}
	 		return 1;	
		}
		if (fruitMode2[i].y == BOTTOMWALL - 1){
			return 1;
		}
	}

	if (fruitMode2[i].shape == BOOM){
		if (fruitMode2[i].x == monster[0].x && fruitMode2[i].y + 1 == monster[0].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[1].x && fruitMode2[i].y + 1 == monster[1].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[2].x && fruitMode2[i].y + 1 == monster[2].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[3].x && fruitMode2[i].y + 1 == monster[3].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[4].x && fruitMode2[i].y + 1 == monster[4].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[5].x && fruitMode2[i].y + 1 == monster[5].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[6].x && fruitMode2[i].y + 1 == monster[6].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].x == monster[7].x && fruitMode2[i].y + 1 == monster[7].y - 1) {
			timeCount = 0;
			return 1;
		}
		if (fruitMode2[i].y + 1 == BOTTOMWALL - 1){
			return 1;
		}	
	}
	
	
	if (fruitMode2[i].shape == MADNESS){
		if (fruitMode2[i].x == monster[0].x && (fruitMode2[i].y + 1 == monster[0].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[0].x && (fruitMode2[i].y + 1 == monster[0].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
		if (fruitMode2[i].x == monster[1].x && (fruitMode2[i].y + 1 == monster[1].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[1].x && (fruitMode2[i].y + 1 == monster[1].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
	 	if (fruitMode2[i].x == monster[2].x && (fruitMode2[i].y + 1 == monster[2].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[2].x && (fruitMode2[i].y + 1 == monster[2].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
	 	if (fruitMode2[i].x == monster[3].x && (fruitMode2[i].y + 1 == monster[3].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[3].x && (fruitMode2[i].y + 1 == monster[3].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
	 	}
		if (fruitMode2[i].x == monster[4].x && (fruitMode2[i].y + 1 == monster[4].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[4].x && (fruitMode2[i].y + 1 == monster[4].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[5].x && (fruitMode2[i].y + 1 == monster[5].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[5].x && (fruitMode2[i].y + 1 == monster[5].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[6].x && (fruitMode2[i].y + 1 == monster[6].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[6].x && (fruitMode2[i].y + 1 == monster[6].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[7].x && (fruitMode2[i].y + 1 == monster[7].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[7].x && (fruitMode2[i].y + 1 == monster[7].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
			if (switchMusic == ON){
				if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 	}
	 		return 1;	
		}
		if (fruitMode2[i].y + 1 == BOTTOMWALL - 1){
			return 1;
		}
	}
	if (fruitMode2[i].shape == REVERSEMODE2){
		if (fruitMode2[i].x == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
		if (fruitMode2[i].x == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
	 	if (fruitMode2[i].x == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)) {
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
	 	if (fruitMode2[i].x == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)) {
	 		if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;
	 	}
		if (fruitMode2[i].x == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruitMode2[i].x == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
	 		inputchange = abs(inputchange - 1);
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			inputchange = abs(inputchange - 1);
	 		return 1;	
		}
		if (fruitMode2[i].y == BOTTOMWALL - 1){
			return 1;
		}
	}
	
	
	if (fruitMode2[i].shape == TIMEBONUSMODE2){
		if (fruitMode2[i].x == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[0].x && (fruitMode2[i].y == monster[0].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		
		
		if (fruitMode2[i].x == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[1].x && (fruitMode2[i].y == monster[1].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[2].x && (fruitMode2[i].y == monster[2].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		
		if (fruitMode2[i].x == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[3].x && (fruitMode2[i].y == monster[3].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		
		if (fruitMode2[i].x == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[4].x && (fruitMode2[i].y == monster[4].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
	
		if (fruitMode2[i].x == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[5].x && (fruitMode2[i].y == monster[5].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}	
		
		if (fruitMode2[i].x == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[6].x && (fruitMode2[i].y == monster[6].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)) {
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 1 == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}
		if (fruitMode2[i].x + 2 == monster[7].x && (fruitMode2[i].y == monster[7].y - 1)){
			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			timeCount += 5;
	 		return 1;
		}		
		if (fruitMode2[i].y == BOTTOMWALL - 1){
			return 1;
		}	
	}
	return 0;
}

void checkFruitMode2(){
	int i;
	for (i = minMode2; i < countMode2 + 1; i++){
		if (conditionsMode2(i)){
			goTo(fruitMode2[i].x, fruitMode2[i].y);
			if (fruitMode2[i].shape == APPLE){
				printf("%c%c", 32, 32);
				goTo(fruitMode2[i].x, fruitMode2[i].y + 1);
				printf("%c%c%c", 32, 32, 32);
				
			}
			if (fruitMode2[i].shape == WALNUT){
				printf("%c", 32);
				
			}
			if (fruitMode2[i].shape == ORANGE){
				printf("%c%c", 32, 32);
				
			}
			if (fruitMode2[i].shape == BOOM){
				printf("%c", 32);
				goTo(fruitMode2[i].x, fruitMode2[i].y + 1);
				printf("%c", 32);
				
			}
			if (fruitMode2[i].shape == MADNESS){
				printf("%c%c", 32, 32);
				goTo(fruitMode2[i].x, fruitMode2[i].y + 1);
				printf("%c%c", 32, 32);
				
			}
			if (fruitMode2[i].shape == REVERSEMODE2){
				printf("%c%c", 32, 32);
				
			}
			if (fruitMode2[i].shape == TIMEBONUSMODE2){
				printf("%c%c%c", 32, 32, 32);
				
			}
			minMode2++;
		}
		else {
			fruitMode2[i].y++;
			if(madnessSwitch == 1){
				if(fruitMode2[i].swit == 0)
					fruitMode2[i].x--;
				if(fruitMode2[i].swit == 1)
					fruitMode2[i].x++;
			}
		}
	}
}

void printTimeScore(){
	goTo(RIGHTWALL + 5, TOPWALL + 7);
	printf("SCORES: %d", score);
	goTo(RIGHTWALL + 5, TOPWALL + 10);
	printf("TIME: %d ", timeCount);
	
}

int checkGameMode2(){
	if (timeCount == 0) return 1;
	return 0;
}




