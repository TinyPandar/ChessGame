#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <windows.h>
#include "Chess.h"
#include "functions.h"
using namespace std;
void printCheckerboard();
void printChess(Chess& chess);
void printTime(time_t beginTime);
void printRounds();
void printBegin();
void printEnd();
void printTips();
Chess* chessMap[9][9];
int sideFlag=0;//mark the term of which side
time_t startTime;
int main(){
    ChessGenerator cg;
    printCheckerboard();
    chessMap[1][8]= cg.generateChess("queen",0);
    chessMap[1][8]->setPos(make_pair(1,8));
    printChess(*chessMap[5][5]);
    gotoxy(10,10);
    getch();
    return 0;
}



