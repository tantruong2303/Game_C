


#define REVERSEMODE3 4

int needFruit;
int typeFruit;

coor fruitMode3[9999999];
coor oldFruitMode3[9999999];

int countMode3;
int minMode3;


void printGuideMode3(){	
	goTo(LEFTWALL - 25, TOPWALL + 3);
	printf("WRONG FRUIT: -1 life");
	
	goTo(LEFTWALL - 22, TOPWALL + 5);
	textcolor(2); printf("%c%c", 32, 194); textcolor(7);
	goTo(LEFTWALL - 22, TOPWALL + 6);
	textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 6);
	printf(" 50 point");

	goTo(LEFTWALL - 22, TOPWALL + 8);	
	textcolor(238); printf("%c%c", 32, 32); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 8);
	printf(" 50 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 10);
	textcolor(8); printf("%c", 235); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 10);
	printf(" 50 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 12);
	textcolor(79); printf("%c%c", 43, 43); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 12);
	printf(" +1 life");
	goTo(LEFTWALL - 17, TOPWALL + 13);
	printf(" 50 point");
	
	goTo(LEFTWALL - 22, TOPWALL + 16);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 22, TOPWALL + 17);
	textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
	goTo(LEFTWALL - 17, TOPWALL + 16);
	printf(" Mad move");
	goTo(LEFTWALL - 17, TOPWALL + 17);
	printf(" 50 point");
	
	goTo(LEFTWALL - 25, TOPWALL + 20);
	textcolor(154); printf("%c", 60); textcolor(7);
	goTo(LEFTWALL - 24, TOPWALL + 20);
	textcolor(169); printf("%c", 62); textcolor(7);
	goTo(LEFTWALL - 20, TOPWALL + 20);
	printf(" Reverse control");
	goTo(LEFTWALL - 20, TOPWALL + 21);
	printf(" 50 point");
}


void spawnFruitMode3()
{
	srand(time(NULL));
	fruitMode3[countMode3].swit =  rand() % 2;
	fruitMode3[countMode3].y = TOPWALL + 1;
	fruitMode3[countMode3].shape = 1 + rand() % 6;
	if (fruitMode3[countMode3].shape == APPLE){
		srand(time(NULL));
		fruitMode3[countMode3].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 3);
		if (fruitMode3[countMode3].x == RIGHTWALL - 3 && fruitMode3[countMode3].swit == 0) fruitMode3[countMode3].swit = 1;
		if (fruitMode3[countMode3].x == LEFTWALL + 1 && fruitMode3[countMode3].swit == 1) fruitMode3[countMode3].swit = 0;
	}
	if (fruitMode3[countMode3].shape == WALNUT){
		srand(time(NULL));
		fruitMode3[countMode3].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 1);
		if (fruitMode3[countMode3].x == RIGHTWALL - 1 && fruitMode3[countMode3].swit == 0) fruitMode3[countMode3].swit = 1;
		if (fruitMode3[countMode3].x == LEFTWALL + 1 && fruitMode3[countMode3].swit == 1) fruitMode3[countMode3].swit = 0;
	}
	if (fruitMode3[countMode3].shape == ORANGE){
		srand(time(NULL));
		fruitMode3[countMode3].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode3[countMode3].x == RIGHTWALL - 2 && fruitMode3[countMode3].swit == 0) fruitMode3[countMode3].swit = 1;
		if (fruitMode3[countMode3].x == LEFTWALL + 1 && fruitMode3[countMode3].swit == 1) fruitMode3[countMode3].swit = 0;
	}
	if (fruitMode3[countMode3].shape == ADDLIFE){
		srand(time(NULL));
		fruitMode3[countMode3].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode3[countMode3].x == RIGHTWALL - 2 && fruitMode3[countMode3].swit == 0) fruitMode3[countMode3].swit = 1;
		if (fruitMode3[countMode3].x == LEFTWALL + 1 && fruitMode3[countMode3].swit == 1) fruitMode3[countMode3].swit = 0;
	}
	if (fruitMode3[countMode3].shape == MADNESS){
		srand(time(NULL));
		fruitMode3[countMode3].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode3[countMode3].x == RIGHTWALL - 2 && fruitMode3[countMode3].swit == 0) fruitMode3[countMode3].swit = 1;
		if (fruitMode3[countMode3].x == LEFTWALL + 1 && fruitMode3[countMode3].swit == 1) fruitMode3[countMode3].swit = 0;
	}
	if (fruitMode3[countMode3].shape == REVERSEMODE3){
		srand(time(NULL));
		fruitMode3[countMode3].x = LEFTWALL + 1 + rand() % (RIGHTWALL - LEFTWALL - 2);
		if (fruitMode3[countMode3].x == RIGHTWALL - 2 && fruitMode3[countMode3].swit == 0) fruitMode3[countMode3].swit = 1;
		if (fruitMode3[countMode3].x == LEFTWALL + 1 && fruitMode3[countMode3].swit == 1) fruitMode3[countMode3].swit = 0;
	}
}

void printFruitMode3(){
	int i;
	for (i = minMode3; i < countMode3 + 1; i++){
		goTo(fruitMode3[i].x, fruitMode3[i].y);
		if (fruitMode3[i].shape == APPLE){
			textcolor(2); printf("%c%c", 32, 194); textcolor(7);
			goTo(fruitMode3[i].x , fruitMode3[i].y + 1);
			textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
			
		}
		if (fruitMode3[i].shape == WALNUT){
			textcolor(8); printf("%c", 235); textcolor(7);
			
		}
		if (fruitMode3[i].shape == ORANGE){
			textcolor(238); printf("%c%c", 32, 32); textcolor(7);
			
		}
		if (fruitMode3[i].shape == ADDLIFE){
			textcolor(79); printf("%c%c", 43, 43); textcolor(7);
			
		}
		if (fruitMode3[i].shape == MADNESS){
			textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
			goTo(fruitMode3[i].x, fruitMode3[i].y + 1);
			textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
			
		}
		if (fruitMode3[i].shape == REVERSEMODE3){
			textcolor(154); printf("%c", 60); textcolor(7);
			goTo(fruitMode3[i].x + 1, fruitMode3[i].y);
			textcolor(169); printf("%c", 62); textcolor(7);
			
		}
		oldFruitMode3[i] = fruitMode3[i];
	//	goTo(0, 10);
	}
}

void madnessMoveMode3()
{
	int i;
	for (i = minMode3; i < countMode3 + 1; i++){    //  0 qua trai, 1 qua phai
		if (fruitMode3[i].x <= LEFTWALL + 1){
			fruitMode3[i].swit = 1;
			fruitMode3[i].x++;
		}
		if (fruitMode3[i].x >= RIGHTWALL - 3){
			fruitMode3[i].swit = 0;
			fruitMode3[i].x--;	
		}	
		
		goTo(oldFruitMode3[i].x, oldFruitMode3[i].y);
		if (fruitMode3[i].shape == APPLE){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode3[i].x, oldFruitMode3[i].y + 1);
			printf("%c%c%c", 32, 32, 32);
			
		}
		if (fruitMode3[i].shape == WALNUT){
			printf("%c", 32);
			
		}
		if (fruitMode3[i].shape == ORANGE){
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode3[i].shape == ADDLIFE){
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode3[i].shape == MADNESS){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode3[i].x, oldFruitMode3[i].y + 1);
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode3[i].shape == REVERSEMODE3){
			printf("%c%c", 32, 32);
			
		}			
	}
	//	goTo(0, 10);
}

void normalMoveMode3(){
	int i;
	for (i = minMode3; i < countMode3 + 1; i++){
		goTo(oldFruitMode3[i].x, oldFruitMode3[i].y);
		if (fruitMode3[i].shape == APPLE){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode3[i].x, oldFruitMode3[i].y + 1);
			printf("%c%c%c", 32, 32, 32);
			
		}
		if (fruitMode3[i].shape == WALNUT){
			printf("%c", 32);
			
		}
		if (fruitMode3[i].shape == ORANGE){
			printf("%c%c", 32, 32);	
		}
		if (fruitMode3[i].shape == ADDLIFE){
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode3[i].shape == MADNESS){
			printf("%c%c", 32, 32);
			goTo(oldFruitMode3[i].x, oldFruitMode3[i].y + 1);
			printf("%c%c", 32, 32);
			
		}
		if (fruitMode3[i].shape == REVERSEMODE3){
			printf("%c%c", 32, 32);
			
		}
	//	goTo(0, 10);
	}
}



void moveFruitMode3(){
	if (madnessSwitch == 1)
		madnessMoveMode3();
	else normalMoveMode3();
}



void fruitNeedToEat(){
	if(needFruit == 1){
		goTo(RIGHTWALL + 5, TOPWALL + 13);
		if(typeFruit == APPLE)
		{
			printf("%c%c", 32, 32);
			goTo(RIGHTWALL + 5, TOPWALL + 14);
			printf("%c%c%c", 32, 32, 32);
			
		}
		if (typeFruit == WALNUT){
			printf("%c", 32);
			
		}
		if (typeFruit == ORANGE){
			printf("%c%c", 32, 32);
		}
		if (typeFruit == ADDLIFE){
			printf("%c%c", 32, 32);
			
		}
		if (typeFruit == MADNESS){
			printf("%c%c", 32, 32);
			goTo(RIGHTWALL + 5, TOPWALL + 14);
			printf("%c%c", 32, 32);
			
		}
		if (typeFruit == REVERSEMODE3){
			printf("%c%c", 32, 32);
			
		}
		srand(time(NULL));
		typeFruit = 1 + rand() % 6;
		needFruit = 0;
	}
}

void printLifeScoreMode3(){
	goTo(RIGHTWALL + 5, TOPWALL + 7);
	printf("SCORES: %d", score);
	goTo(RIGHTWALL + 5, TOPWALL + 10);
	printf("LIFE: %d", life);
	goTo(RIGHTWALL + 5, TOPWALL + 13);
	if(typeFruit == APPLE){
		textcolor(2); printf("%c%c", 32, 194); textcolor(7);
		goTo(RIGHTWALL + 5, TOPWALL + 14);
		textcolor(12); printf("%c%c%c", 178, 178, 178); textcolor(7);
		
	}
	if (typeFruit == WALNUT){
		textcolor(8); printf("%c", 235); textcolor(7);
		
	}
	if (typeFruit == ORANGE){
		textcolor(238); printf("%c%c", 32, 32); textcolor(7);

		
	}
	if (typeFruit == ADDLIFE){
		textcolor(79); printf("%c%c", 43, 43); textcolor(7);
		
	}
	if (typeFruit == MADNESS){
		textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
		goTo(RIGHTWALL + 5, TOPWALL + 14);
		textcolor(1 + rand() % 15); printf("%c%c",128 + rand() % 126, 128 + rand() % 126); textcolor(7);
		
	}
	if (typeFruit == REVERSEMODE3){
		textcolor(154); printf("%c", 60); textcolor(7);
		goTo(RIGHTWALL + 6, TOPWALL + 13);
		textcolor(169); printf("%c", 62); textcolor(7);
		
	}
}

int conditionsMode3(int i){
	if (fruitMode3[i].shape == APPLE){
		if (fruitMode3[i].x == monster[0].x && (fruitMode3[i].y + 1 == monster[0].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[0].x && (fruitMode3[i].y + 1 == monster[0].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[0].x && (fruitMode3[i].y + 1 == monster[0].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		
		
		if (fruitMode3[i].x == monster[1].x && (fruitMode3[i].y + 1 == monster[1].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[1].x && (fruitMode3[i].y + 1 == monster[1].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[1].x && (fruitMode3[i].y + 1 == monster[1].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x == monster[2].x && (fruitMode3[i].y + 1 == monster[2].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[2].x && (fruitMode3[i].y + 1 == monster[2].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[2].x && (fruitMode3[i].y + 1 == monster[2].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x == monster[3].x && (fruitMode3[i].y + 1 == monster[3].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[3].x && (fruitMode3[i].y + 1 == monster[3].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[3].x && (fruitMode3[i].y + 1 == monster[3].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		
		if (fruitMode3[i].x == monster[4].x && (fruitMode3[i].y + 1 == monster[4].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[4].x && (fruitMode3[i].y + 1 == monster[4].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[4].x && (fruitMode3[i].y + 1 == monster[4].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
	
		if (fruitMode3[i].x == monster[5].x && (fruitMode3[i].y + 1 == monster[5].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[5].x && (fruitMode3[i].y + 1 == monster[5].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[5].x && (fruitMode3[i].y + 1 == monster[5].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}	
		
		if (fruitMode3[i].x == monster[6].x && (fruitMode3[i].y + 1 == monster[6].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[6].x && (fruitMode3[i].y + 1 == monster[6].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[6].x && (fruitMode3[i].y + 1 == monster[6].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x == monster[7].x && (fruitMode3[i].y + 1 == monster[7].y - 1)) {
	 		if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[7].x && (fruitMode3[i].y + 1 == monster[7].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 2 == monster[7].x && (fruitMode3[i].y + 1 == monster[7].y - 1)){
			if(APPLE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}		
		if (fruitMode3[i].y + 1 == BOTTOMWALL - 1){
			if(APPLE == typeFruit){
				if (switchMusic == ON) {
	 				if(madnessSwitch == 0)
	 				PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 			}
				life --;
			}
			return 1;
		}
		
	}

	if (fruitMode3[i].shape == WALNUT){
		if (fruitMode3[i].x == monster[0].x && fruitMode3[i].y == monster[0].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[1].x && fruitMode3[i].y == monster[1].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[2].x && fruitMode3[i].y == monster[2].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[3].x && fruitMode3[i].y == monster[3].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[4].x && fruitMode3[i].y == monster[4].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[5].x && fruitMode3[i].y == monster[5].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[6].x && fruitMode3[i].y == monster[6].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].x == monster[7].x && fruitMode3[i].y == monster[7].y - 1) {
			if(WALNUT == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
			return 1;
		}
		if (fruitMode3[i].y == BOTTOMWALL - 1){
			if(WALNUT == typeFruit){
				if (switchMusic == ON) {
	 				if(madnessSwitch == 0)
	 				PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 			}
				
				life --;
			}
			return 1;
		}
	}

	if (fruitMode3[i].shape == ORANGE){
		if (fruitMode3[i].x == monster[0].x && (fruitMode3[i].y == monster[0].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[0].x && (fruitMode3[i].y == monster[0].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[1].x && (fruitMode3[i].y == monster[1].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[1].x && (fruitMode3[i].y == monster[1].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[2].x && (fruitMode3[i].y == monster[2].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[2].x && (fruitMode3[i].y == monster[2].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[3].x && (fruitMode3[i].y == monster[3].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[3].x && (fruitMode3[i].y == monster[3].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[4].x && (fruitMode3[i].y == monster[4].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[4].x && (fruitMode3[i].y == monster[4].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[5].x && (fruitMode3[i].y == monster[5].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[5].x && (fruitMode3[i].y == monster[5].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[6].x && (fruitMode3[i].y == monster[6].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[6].x && (fruitMode3[i].y == monster[6].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[7].x && (fruitMode3[i].y == monster[7].y - 1)) {
	 		if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[7].x && (fruitMode3[i].y == monster[7].y - 1)){
			if(ORANGE == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("GETPOINT.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) {
					if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				}
				life --;
			}
	 		return 1;	
		}
		if (fruitMode3[i].y == BOTTOMWALL - 1){
			if (ORANGE == typeFruit){
				if (switchMusic == ON) {
	 				if(madnessSwitch == 0)
	 				PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 			}
				life --;
			}
			return 1;
		}
	}
	
	if (fruitMode3[i].shape == ADDLIFE){
		if (fruitMode3[i].x == monster[0].x && (fruitMode3[i].y == monster[0].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[0].x && (fruitMode3[i].y == monster[0].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[1].x && (fruitMode3[i].y == monster[1].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[1].x && (fruitMode3[i].y == monster[1].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[2].x && (fruitMode3[i].y == monster[2].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[2].x && (fruitMode3[i].y == monster[2].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[3].x && (fruitMode3[i].y == monster[3].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[3].x && (fruitMode3[i].y == monster[3].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
			} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[4].x && (fruitMode3[i].y == monster[4].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		}
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[4].x && (fruitMode3[i].y == monster[4].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		}
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[5].x && (fruitMode3[i].y == monster[5].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		}
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[5].x && (fruitMode3[i].y == monster[5].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[6].x && (fruitMode3[i].y == monster[6].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[6].x && (fruitMode3[i].y == monster[6].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			} 
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[7].x && (fruitMode3[i].y == monster[7].y - 1)) {
	 		if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		} 
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[7].x && (fruitMode3[i].y == monster[7].y - 1)){
			if(ADDLIFE == typeFruit) {
	 			life ++;
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LIFEUP.wav"), NULL, SND_ASYNC);
	 		}
			else {
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			} 
	 		return 1;	
		}
		if (fruitMode3[i].y == BOTTOMWALL - 1){
			if (ADDLIFE == typeFruit){
				if (switchMusic == ON) {
	 				if(madnessSwitch == 0)
	 				PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 			}
				life --;
			}
			return 1;
		}
	}
	
	if (fruitMode3[i].shape == MADNESS){
		if (fruitMode3[i].x == monster[0].x && (fruitMode3[i].y + 1 == monster[0].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
	 			}
			} 
			else{
				if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
	 			}
				life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[0].x && (fruitMode3[i].y + 1 == monster[0].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
	 			}
	 		}
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
				life --;	
			}
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[1].x && (fruitMode3[i].y + 1 == monster[1].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[1].x && (fruitMode3[i].y + 1 == monster[1].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[2].x && (fruitMode3[i].y + 1 == monster[2].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[2].x && (fruitMode3[i].y + 1 == monster[2].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
					else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
					else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[3].x && (fruitMode3[i].y + 1 == monster[3].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
					else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
					else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[3].x && (fruitMode3[i].y + 1 == monster[3].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
					else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[4].x && (fruitMode3[i].y + 1 == monster[4].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
					if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
					else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[4].x && (fruitMode3[i].y + 1 == monster[4].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x == monster[5].x && (fruitMode3[i].y + 1 == monster[5].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
				life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[5].x && (fruitMode3[i].y + 1 == monster[5].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
				if (switchMusic == ON) {
		 			if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
		 			else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x == monster[6].x && (fruitMode3[i].y + 1 == monster[6].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[6].x && (fruitMode3[i].y + 1 == monster[6].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x == monster[7].x && (fruitMode3[i].y + 1 == monster[7].y - 1)) {
	 		madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[7].x && (fruitMode3[i].y + 1 == monster[7].y - 1)){
			madnessSwitch = abs(madnessSwitch - 1);
	 		if(MADNESS == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
			} 
			else{
				if (switchMusic == ON) {
			 		if(madnessSwitch == 1) PlaySound(TEXT("madness.wav"), NULL, SND_ASYNC);
			 		else PlaySound(TEXT("empty.wav"), NULL, SND_ASYNC);
		 		}
	 			life --;	
			}
	 		return 1;	
		}
		if (fruitMode3[i].y + 1 == BOTTOMWALL - 1){
			if(MADNESS == typeFruit){
				if (switchMusic == ON) {
	 				if(madnessSwitch == 0)
	 				PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
	 			}
				life --;
			}
			return 1;
		}
	}
	
	if (fruitMode3[i].shape == REVERSEMODE3){
		if (fruitMode3[i].x == monster[0].x && (fruitMode3[i].y == monster[0].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[0].x && (fruitMode3[i].y == monster[0].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[1].x && (fruitMode3[i].y == monster[1].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[1].x && (fruitMode3[i].y == monster[1].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[2].x && (fruitMode3[i].y == monster[2].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			}
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[2].x && (fruitMode3[i].y == monster[2].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
	 	}
	 	if (fruitMode3[i].x == monster[3].x && (fruitMode3[i].y == monster[3].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[3].x && (fruitMode3[i].y == monster[3].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
	 	}
		if (fruitMode3[i].x == monster[4].x && (fruitMode3[i].y == monster[4].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[4].x && (fruitMode3[i].y == monster[4].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[5].x && (fruitMode3[i].y == monster[5].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[5].x && (fruitMode3[i].y == monster[5].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[6].x && (fruitMode3[i].y == monster[6].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[6].x && (fruitMode3[i].y == monster[6].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;	
		}
		if (fruitMode3[i].x == monster[7].x && (fruitMode3[i].y == monster[7].y - 1)) {
	 		inputchange = abs(inputchange - 1);
	 		if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;
		}
		if (fruitMode3[i].x + 1 == monster[7].x && (fruitMode3[i].y == monster[7].y - 1)){
			inputchange = abs(inputchange - 1);
			if(REVERSEMODE3 == typeFruit) {
	 			score += 50;
	 			needFruit = 1;
	 			if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("reverse.wav"), NULL, SND_ASYNC);
			} 
	 		return 1;	
		}
		if (fruitMode3[i].y == BOTTOMWALL - 1){
			if (REVERSEMODE3 == typeFruit){
				if (switchMusic == ON) if(madnessSwitch == 0) PlaySound(TEXT("LOSELIFE.wav"), NULL, SND_ASYNC);
				life --;
			}	
			return 1;
		}
	}
	return 0;
}

void checkFruitMode3(){
	int i;
	for (i = minMode3; i < countMode3 + 1; i++){
		if (conditionsMode3(i)){
			goTo(fruitMode3[i].x, fruitMode3[i].y);
			if (fruitMode3[i].shape == APPLE){
				printf("%c%c", 32, 32);
				goTo(fruitMode3[i].x, fruitMode3[i].y + 1);
				printf("%c%c%c", 32, 32, 32);
				
			}
			if (fruitMode3[i].shape == WALNUT){
				printf("%c", 32);
				
			}
			if (fruitMode3[i].shape == ORANGE){
				printf("%c%c", 32, 32);
				
			}
			if (fruitMode3[i].shape == ADDLIFE){
				printf("%c%c", 32, 32);
				
			}
			if (fruitMode3[i].shape == MADNESS){
				printf("%c%c", 32, 32);
				goTo(fruitMode3[i].x, fruitMode3[i].y + 1);
				printf("%c%c", 32, 32);
				
			}
			if (fruitMode3[i].shape == REVERSEMODE3){
				printf("%c%c", 32, 32);
				
			}
			minMode3++;
		}
		else {
			fruitMode3[i].y++;
			if(madnessSwitch == 1){
				if(fruitMode3[i].swit == 0)
					fruitMode3[i].x--;
				if(fruitMode3[i].swit == 1)
					fruitMode3[i].x++;
			}
		}
	}
}

