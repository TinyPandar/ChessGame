#include <iostream>
#include <fcntl.h>
#include "io.h"
#include "Chess.h"
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

}


void printChess(Chess& chess){
    _setmode(_fileno(stdout), _O_U16TEXT);
    if(chess.getSide() == 0){
        if(chess.getType() == "Kn") wcout<<L"\x265E";
    }
    _setmode(_fileno(stdout),O_TEXT);
}
