//  board.c
//  week12
//  Created by 정민형 on 11/18/25.

#include <stdio.h>
#include "board.h"
int board_initBoard(void);
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardCoin(int pos);

#define N_BOARD 20
#define BOARDSTATUS_OK 1
#define BOARDSTATUS_NOK 0
#define N_COINPOS 12


static int board_status[N_BOARD];
static int board_coin[N_BOARD];
static int shark_position;

void board_printBoardStatus(void){
    int i;
    printf(" ---- BOARD STATUS ---- \n");
    for (i=0; i<N_BOARD; i++){
        if(board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
        printf("| \n");
    }
}

int board_getBoardStatus(int pos) {
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    return board_coin[pos];
}

