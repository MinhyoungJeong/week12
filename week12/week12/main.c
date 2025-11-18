//
//  main.c
//  week12
//
//  Created by 정민형 on 11/18/25.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "board.h"

int main(int argc, const char * argv[]) {
    
    srand((unsigned)(time(NULL)));
    printf("------------------------------------\n");
    printf("SHARK GAME STARTED! ARE YOU READY?  \n");
    printf("------------------------------------\n");
    
    //step1. Initialization (player name, variables)
    board_initBoard();
    
    //step2. turn play(do-while)
    int cnt = 0;
    int pos = 0;
    int coinResult = 0;
    int die_result;
    
    do {
        //2-1. status printing
        board_printBoardStatus();
        //2-2. roll die
        die_result = rolldie();
        //2-3. move
        pos += die_result;
        pos %= N_BOARD;   // 수정: 보드 크기만큼 순환시키기
        printf("position : %i(die:%i)\n", pos, die_result);
        coinResult += board_getBoardCoin(pos);
        printf("coin : %i\n", coinResult);
        cnt++;
        
    } while(cnt<5);
   
    die_result = rolldie();
    //2-4. change turn, shark move
    //step3. game end(winner printing)
    
    printf("------------------------------------\n");
    printf("YOU WON, CONGRATULATION!\n");
    printf("------------------------------------\n");
    
    return 0;
}
