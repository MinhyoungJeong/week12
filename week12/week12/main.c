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
#define N_BOARD 20
#define PLAYERSTATUS_LIVE 0
#define PLAYERSTATUS_DIE 1
#define PLAYERSTATUS_END 2

static int board_status[N_BOARD];
static int board_coin[N_BOARD];
static int shark_position;

char player_name[N_PLAYER][MAXLENGTH];
int player_position[N_PLAYER];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAXLENGTH] = {"Live","Die","End"};
void checkDie(void);
void printPlayerStatus(void);
void checkDie(void);
int gameEnd(void);

int main(int argc, const char * argv[]) {
    
    srand((unsigned)(time(NULL)));
    printf("------------------------------------\n");
    printf("SHARK GAME STARTED! ARE YOU READY?  \n");
    printf("------------------------------------\n");
    
    //step1. Initialization (player name, variables)
    board_initBoard();
    //player init
    initPlayer();
    //step2. turn play(do-while)

    int cnt = 0;
    int pos = 0;

    int die_result;
    int turn = 0;
    int dum = 0;
    int shark_pos;
    
    do {
        int die_result;
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn+1)%N_PLAYER;
            continue;
        }
        
        //2-1. status printing
        board_printBoardStatus();
        printPlayerStatus();
        //player status
        
        //2-2. roll die
        printf("%s turn!",player_name[turn]); //player turn
        printf("Press any key to roll a die! \n");
        scanf("%d", &dum);
        fflush(stdin);
        die_result = rolldie();
        
        //2-3. move
        player_position[turn] += die_result;
        
        if (player_position[turn]>= N_BOARD-1)
        {
            player_position[turn] = N_BOARD-1;
            player_status[turn] = PLAYERSTATUS_END;
        }
        printf("Die result : %i, %s moved to %i \n", die_result, player_name[turn], player_position[turn]);
        

        player_coin[turn] += board_getBoardCoin(player_position[turn]);
        printf("Lucky! %s got coin : %i \n", player_name[turn], player_coin[turn]);
        
        //change turn
        turn = (turn + 1) % N_PLAYER;
        //shark move
        

        cnt++;

        if (turn ==0)
        {
            int shark_pos = board_stepShark();
            printf("Shark moved to %i\n",shark_pos);
            checkDie();
        }
        cnt++;
        
    } while(gameEnd() == 0); //game end condition
        
    die_result = rolldie();
    //2-4. change turn, shark move
    //step3. game end(winner printing)
    //ending
    printf("------------------------------------\n");
    printf("YOU WON, CONGRATULATION!\n");
    printf("------------------------------------\n");
    
    return 0;
}


void printPlayerPosition(int player) {
    
    int i;
    for (i=0; i <N_BOARD; i++){
        
        printf("|");
        
        if(i == player_position[player])
        {
            printf("%c",player_name[player][0]);
        }
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_OK )
                printf(" ");
            
            else
                printf("X");
        }
    }
    printf("| \n");
    
}

void printPlayerStatus(void){
    int i;
    for(i=0; i<N_PLAYER; i++) {
        printf("%s : pos %i, coin %i, status %s \n",
            player_name[i],
            player_position[i],
            player_coin[i],                          // ← 추가
            player_statusString[player_status[i]]);
        // printPlayerPosition(i)
                   }
    }

void initPlayer(void)
{
    int i;
    for(i=0; i<N_PLAYER; i++) {
        
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ",i);
        scanf("%s",player_name[i]);
        fflush(stdin);
    }
}

int gameEnd(void)
{
    int i;
    int flag_end = 1;
    for(i=0; i<N_PLAYER; i++)
        {
            if(player_status [i] == PLAYERSTATUS_LIVE)
                flag_end = 0;
        }
    return flag_end;
}

    
    
void checkDie(void){
    int i;
    for(i=0; i<N_PLAYER; i++){
        if (board_getBoardStatus(player_position[i])) {
            player_status[i] = PLAYERSTATUS_DIE;
            printf("So sad player %s died at position %i\n", player_name[i],player_position[i]);
        }
        }
}
