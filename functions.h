#ifndef CHESSGAME_FUNCTIONS_H
#define CHESSGAME_FUNCTIONS_H



using namespace std;
void gotoxy(int x, int y) { //移动光标到（x，y）的函数
    COORD c;  //COORD为windows API中定义的一种结构，表示一个字符再控制台屏幕上的坐标
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); //此函数是API中定位光标位置的函数
}
void printChess(Chess& chess){
    pair<int, int>pos = chess.getPos();
    gotoxy(pos.first*4, (9-pos.second)*2-1);
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

void printCheckerboard(){
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout<<L"  \x250F\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2533\x2501\x2501\x2501\x2513\n";
    for (int i = 1; i <= 8; ++i) {
        wcout<<9-i<<" ";
        for (int j = 0; j <= 8; j++) {
            wcout<<L"\x2503   ";
        }
        wcout<<endl;
        if(i==8)wcout<<L"  \x2517\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x253B\x2501\x2501\x2501\x251B\n";
        else{
            wcout << L"  \x2523";
            for (int j = 0; j < 8; j++) {
                wcout << L"\x2501\x2501\x2501\x254B";
            }
            wcout << endl;
        }
    }
    wcout<<"    a   b   c   d   e   f   g   h\n";
    cout << endl;
    _setmode(_fileno(stdout),O_TEXT);
}



#endif //CHESSGAME_FUNCTIONS_H
