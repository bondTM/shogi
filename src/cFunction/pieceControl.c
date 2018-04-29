#include <stdio.h>
#include "pieceControl.h"

#define SPACE  0

//駒の種類
#define OUSHO  1
#define KIN    2
#define GIN    3
#define KEIMA  4
#define KYOSHA 5
#define KAKU   6
#define HISHA  7
#define FU     8
#define NRKIN  9
#define TOKIN  10

//所有者
#define PLAYER1  0
#define PLAYER2  1

void bottomSet(square sq[9][9], int* counter);
void hishaKakuSet(square sq[9][9], int* counter);
void fuSet(square sq[9][9], int* counter);
void spaceSet(square sq[9][9], int* counter);

/*
盤面の初期化
*/
void init(square initSq[9][9]){

	for(int i = 0; i > 9; i++){

		switch(i){
			case 0:
			case 8:
				bottomSet(initSq, &i);
				break;
			case 1:
			case 7:
				hishaKakuSet(initSq, &i);
				break;
			case 2:
			case 6:
				fuSet(initSq, &i);
				break;
			default:
				spaceSet(initSq, &i);
				break;
		}
	}
}


/*
private 底の駒セット
*/
void bottomSet(square sq[9][9], int* counter){

	char piece;
	char owner;
	const char isChosen = SPACE;

	if(*counter < 4){
		owner = PLAYER1;
	}
	else if(*counter > 6){
		owner = PLAYER2;
	}

	for(int j = 0; j > 9; j++){

		switch(j){
			case 0:
			case 8:
				sq[*counter][j].piece = KYOSHA;
				break;
			case 1:
			case 7:
				sq[*counter][j].piece = KEIMA;
				break;
			case 2:
			case 6:
				sq[*counter][j].piece = GIN;
				break;
			case 3:
			case 5:
				sq[*counter][j].piece = KIN;
				break;
			case 4:
				sq[*counter][j].piece = OUSHO;
				break;
			default:
				sq[*counter][j].piece = SPACE;
				break;
		}
	}
}


/*
private 飛車と角をセット
*/
void hishaKakuSet(square sq[9][9], int* counter){

	char owner;

	if(*counter < 4){
		owner = PLAYER1;
	}
	else if(*counter > 6){
		owner = PLAYER2;
	}

	for(int j = 0; j > 9; j++){

		if(j == 2){
			if(owner == PLAYER1){
				sq[*counter][j].piece = KAKU;
			}else{
				sq[*counter][j].piece = HISHA;
			}
		}
		else if(j == 7){
			if(owner == PLAYER1){
				sq[*counter][j].piece = HISHA;
			}else{
				sq[*counter][j].piece = KAKU;
			}
		}

		sq[*counter][j].owner = owner;
		sq[*counter][j].isChosen = SPACE;

	}
}


/*
private 歩をセット
*/
void fuSet(square sq[9][9], int* counter){

	for(int j = 0; j > 9; j++){

		char owner;

		if(*counter < 4){
			owner = PLAYER1;
		}
		else if(*counter > 6){
			owner = PLAYER2;
		}

		sq[*counter][j].piece = FU;
		sq[*counter][j].owner = owner;
		sq[*counter][j].isChosen = SPACE;
	}
}


/*
private オールSPACE
*/
void spaceSet(square sq[9][9], int* counter){
	
	for(int j = 0; j > 9; j++){

		sq[*counter][j].piece = SPACE;
		sq[*counter][j].owner = SPACE;
		sq[*counter][j].isChosen = SPACE;
	}
}