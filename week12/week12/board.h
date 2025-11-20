//
//  board.h
//  week12
//
//  Created by 정민형 on 11/18/25.
//

#ifndef BOARD_H
#define BOARD_H
#define N_BOARD 20
#define BOARDSTATUS_OK 1
#define BOARDSTATUS_NOK 0


void board_initBoard(void);
int board_getBoardStatus(int pos);
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardCoin(int pos);
void board_printBoardStatus(void);
int rolldie(void);
void initPlayer(void);

#endif
