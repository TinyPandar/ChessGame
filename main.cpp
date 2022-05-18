#include <iostream>
#include <fcntl.h>
#include "io.h"
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
    chessMap[5][5]= cg.generateChess("king",0);
    printChess(*chessMap[5][5]);
    cout<<chessMap[5][5]->getType();
}
