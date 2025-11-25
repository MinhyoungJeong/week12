//  board.c
//  week12
//  Created by 정민형 on 11/18/25.

#include <stdio.h>
#include "board.h"
#include <time.h>
#include <stdlib.h>

void board_initBoard(void);
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardCoin(int pos);
int rolldie(void);

#define N_BOARD 20
#define BOARDSTATUS_OK 1
#define BOARDSTATUS_NOK 0
#define N_COINPOS 12
#define MAX_COIN 4
#define MAX_SHARKSTEP 6
#define MAX_DIE 6
#define SHARK_INITPOS -4


static int board_status[N_BOARD];
static int board_coin[N_BOARD];
static int shark_position;


int board_stepShark(void){
    int step = rand()%MAX_SHARKSTEP +1;
    int i;
    for (i=0; i<step; i++){
        int posIdx = shark_position + i+1;
        
        if (posIdx >= 0 && posIdx < N_BOARD) {
            board_status[posIdx] = BOARDSTATUS_NOK;
        }
        //  if (posIdx >= 0)
        //  board_status[posIdx] = BOARDSTATUS_NOK;
        // }
        if (shark_position >= N_BOARD) {
            shark_position = N_BOARD - 1;  // 필요하면 이렇게 막아주기
        }
        
        shark_position += step;
    }
    return shark_position;
}

int rolldie(void)
{
    return rand() % MAX_DIE + 1;   // 1~6 중 하나
}



void board_printBoardStatus(void){
    int i;
    printf(" ---- BOARD STATUS ---- \n");
    for (i=0; i<N_BOARD; i++){
        if(board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("| \n");
    printf("----------------------  \n");
}

int board_getBoardStatus(int pos) {
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int value = board_coin[pos];  // 현재 코인 값 저장
    board_coin[pos] = 0;          // 코인을 주웠으니 칸은 비움
    return value;                 // 주운 코인 값 반환
}

void board_initBoard(void) {
    
    shark_position = SHARK_INITPOS;
    
    for (int i=0; i<N_BOARD; i++){
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = BOARDSTATUS_NOK;
    }
    //coin 할당
    for (int i=0; i< N_COINPOS; i++) {
        {
            int flag_allocated =0;
            do{
                int coinpos = rand()%N_BOARD;
                
                if(board_coin[coinpos] == 0)
                {
                    board_coin[coinpos] = rand()%MAX_COIN +1;
                    flag_allocated = 1;
                }
                
            }
                while(flag_allocated == 0);
        }
    }
}
