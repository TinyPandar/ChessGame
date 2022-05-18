#include <iostream>
#include <fcntl.h>
#include "io.h"
#include <ctime>
#include "Chess.h"
using namespace std;
void printMap();
void printChess(Chess& chess);
Chess* chessMap[9][9];

int main(){

}


void printChess(Chess& chess){
    _setmode(_fileno(stdout), _O_U16TEXT);
    if(chess.getSide() == 0){
        if(chess.getType() == "Kn") wcout<<L"\x265E";
    }
    _setmode(_fileno(stdout),O_TEXT);
}
