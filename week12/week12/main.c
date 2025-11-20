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
#define N_PLAYER 3
#define N_PLAYER 3
#define MAXLENGTH 30

#define PLAYERSTATUS_LIVE 0
#define PLAYERSTATUS_DIE 1
#define PLAYERSTATUS_END 2

char player_name[N_PLAYER][MAXLENGTH];
int player_position[N_PLAYER];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAXLENGTH] = {"Live","Die","End"};

int main(int argc, const char * argv[]) {
    
    srand((unsigned)(time(NULL)));
    printf("------------------------------------\n");
    printf("SHARK GAME STARTED! ARE YOU READY?  \n");
    printf("------------------------------------\n");
    
    //step1. Initialization (player name, variables)
    board_initBoard();
    initPlayer();
    //player init
    
    //step2. turn play(do-while)
    //2-1 player status each
    
    int cnt = 0;
    int pos = 0;
    int coinResult = 0;
    int die_result;
    int turn = 0;
    int dum = 0;

    
    do {
        int die_result;
        
        if (player_status[turn] != PLAYERSTATUS_LIVE) {
            turn = (turn+1)%N_PLAYER;
            continue;
        }
        
        //2-1. status printing
        board_printBoardStatus();
        //2-2. roll die
        printf("%s turn!",player_name[turn]);
        printf("Press any key to roll a die! \n");
        scanf("%d", &dum);
        
        die_result = rolldie();
        
        //2-3. move
        player_position[turn] += die_result;
        //pos %= N_BOARD;   // 수정: 보드 크기만큼 순환시키기
        printf("Die result : %i(die:%i)\n", pos, die_result);
        coinResult += board_getBoardCoin(pos);
        printf("coin : %i\n", coinResult);
        cnt++;
        //change turn
        turn = (turn + 1) % N_PLAYER;
        //shark move
        
        if (turn ==0)
        {
            int shark_pos = board_stepShark();
            printf("Shark moved to %i\n",shark_post);

            checkDie();
        }
        
        
        
    } while(cnt<5);
    
    die_result = rolldie();
    //2-4. change turn, shark move
    //step3. game end(winner printing)
    
    printf("------------------------------------\n");
    printf("YOU WON, CONGRATULATION!\n");
    printf("------------------------------------\n");
    
    return 0;
}


void printPlayerPosition(void) {
    
    for (int player=0; player <N_BOARD; player++){
        
        printf("| \n");
        if(player == player_position[player])
        {
            printf("%c",player_name[player][0]);
        }
        else{
            if (board_getBoardStatus(player))
                printf("BOARD_STATUS_OK");
            else
                printf("X");
        }
    }
    
}

void printPlayerStatus(void){
    int i;
    for(i=0; i<N_PLAYER; i++) {
        printf("%s : pos %i, coin %i, status %s \n",
            player_name[i],
            player_position[i],
            player_coin[i],                          // ← 추가
            player_statusString[player_status[i]]);  // status 문자열
                   }
    }



void initPlayer(void)
{
    int i;
    for(i=0; i< N_PLAYER; i++) {
        
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = 0;
        printf("Player %i's name: ",i);
        scanf("%s",player_name[i]);
        fflush(stdin);
    }
}

int gameEnd(void)
{
    for(i=0; i<N_PLAYER; i++){
        {
            if(player_status[i])
        }
        
    }
}




void checkDie(void){
    int i;
    for(i=0; i<N_PLAYER; i++){
        if (board_getBoardStatus(player_position[i]) {
            player_status[i] = PLAYERSTATUS_DIE;
            printf("So sad player died");
            }
    }
}


