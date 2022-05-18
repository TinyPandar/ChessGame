//
// Created by FrankLee on 2022/5/18.
//

#ifndef CHESSGAME_FUNCTIONS_H
#define CHESSGAME_FUNCTIONS_H
using namespace std;
void printChess(Chess& chess){
    _setmode(_fileno(stdout), _O_U16TEXT);
    if(chess.getSide() == 0){
        if(chess.getType() == "king") wcout<<L"\x265A";
        if(chess.getType() == "queen") wcout<<L"\x265B";
        if(chess.getType() == "rook") wcout<<L"\x265C";
        if(chess.getType() == "bishop") wcout<<L"\x265D";
        if(chess.getType() == "knight") wcout<<L"\x265E";
        if(chess.getType() == "pawn") wcout<<L"\x265F";
    } else{
        if(chess.getType() == "king") wcout<<L"\x2654";
        if(chess.getType() == "queen") wcout<<L"\x2655";
        if(chess.getType() == "rook") wcout<<L"\x2656";
        if(chess.getType() == "bishop") wcout<<L"\x2657";
        if(chess.getType() == "knight") wcout<<L"\x2658";
        if(chess.getType() == "pawn") wcout<<L"\x2659";
    }
    _setmode(_fileno(stdout),O_TEXT);
}
#endif //CHESSGAME_FUNCTIONS_H
