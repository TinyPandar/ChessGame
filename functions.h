#ifndef CHESSGAME_FUNCTIONS_H
#define CHESSGAME_FUNCTIONS_H



using namespace std;
void hideCursor() { //隐藏光标
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x, int y) { //移动光标到（x，y）的函数
    COORD c;  //COORD为windows API中定义的一种结构，表示一个字符再控制台屏幕上的坐标
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); //此函数是API中定位光标位置的函数
}
int setColor(int c) {//for easier to change color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
    return 0;
}
void changeSide(){//切换黑白下棋方
    if(sideFlag==0){
        sideFlag=1;
        t1= time(NULL);
        whitetime+=t1-t2;
    }else{
        sideFlag=0;
        t2= time(NULL);
        blacktime+=t2-t1;
    }
}
void printBegin(){
    gotoxy(49,11);
    cout<<"Chess Game";
    gotoxy(29, 21);
    cout<<"Welcome to the chess";
    gotoxy(29, 23);
    cout<<"Please choose number and press 'ENTER' twice";
    gotoxy(29, 25);
    cout<<"[1]play\t\t[2]exist";
    gotoxy(45, 33);
    cout<<"Tips:balbala";
    gotoxy(1,1);
    setColor(14);          			//黄色边框
    for (int i = 20; i <= 26; i++) { 	//输出上下边框┅
        for (int j = 27; j <= 74; j++) { //输出左右边框┇
            gotoxy(j, i);
            if (i == 20 || i == 26) {
                printf("-");
            } else if (j == 27 || j == 74) {
                printf("|");
            }
        }
    }
    gotoxy(36,28);
    while(1){
        int x;
        cin>>x;
        temp = getchar();
        if(x==1){
            break;
        }
        else if(x==2){
            exit(0);
        }else
            cout<<"Please put in the given number";
    }
}
void printChess(Chess& chess){
    pair<int, int>pos = chess.getPos();
    gotoxy(pos.first*4, (9-pos.second)*2-1);
    if(chess.getStatus()==false) {
        wcout<<" ";
        return;
    }
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
                if(j!=7)wcout << L"\x2501\x2501\x2501\x254B";
                else wcout << L"\x2501\x2501\x2501\x252B";
            }
            wcout << endl;
        }
    }
    wcout<<"    a   b   c   d   e   f   g   h\n";
    _setmode(_fileno(stdout),O_TEXT);
}

void initialize(){
    ChessGenerator cg;
    chessMap[4][1]=cg.generateChess("king",0)->setPos(make_pair(4,1));
    chessMap[4][8]=cg.generateChess("king",1)->setPos(make_pair(4,8));
    chessMap[5][1]=cg.generateChess("queen",0)->setPos(make_pair(5,1));
    chessMap[5][8]=cg.generateChess("queen",1)->setPos(make_pair(5,8));
    chessMap[3][1]=cg.generateChess("bishop",0)->setPos(make_pair(3,1));
    chessMap[6][1]=cg.generateChess("bishop",0)->setPos(make_pair(6,1));
    chessMap[3][8]=cg.generateChess("bishop",1)->setPos(make_pair(3,8));
    chessMap[6][8]=cg.generateChess("bishop",1)->setPos(make_pair(6,8));
    chessMap[2][1]=cg.generateChess("knight",0)->setPos(make_pair(2,1));
    chessMap[7][1]=cg.generateChess("knight",0)->setPos(make_pair(7,1));
    chessMap[2][8]=cg.generateChess("knight",1)->setPos(make_pair(2,8));
    chessMap[7][8]=cg.generateChess("knight",1)->setPos(make_pair(7,8));
    chessMap[1][1]=cg.generateChess("rook",0)->setPos(make_pair(1,1));
    chessMap[8][1]=cg.generateChess("rook",0)->setPos(make_pair(8,1));
    chessMap[1][8]=cg.generateChess("rook",1)->setPos(make_pair(1,8));
    chessMap[8][8]=cg.generateChess("rook",1)->setPos(make_pair(8,8));
    chessMap[1][2]=cg.generateChess("pawn",0)->setPos(make_pair(1,2));
    chessMap[2][2]=cg.generateChess("pawn",0)->setPos(make_pair(2,2));
    chessMap[3][2]=cg.generateChess("pawn",0)->setPos(make_pair(3,2));
    chessMap[4][2]=cg.generateChess("pawn",0)->setPos(make_pair(4,2));
    chessMap[5][2]=cg.generateChess("pawn",0)->setPos(make_pair(5,2));
    chessMap[6][2]=cg.generateChess("pawn",0)->setPos(make_pair(6,2));
    chessMap[7][2]=cg.generateChess("pawn",0)->setPos(make_pair(7,2));
    chessMap[8][2]=cg.generateChess("pawn",0)->setPos(make_pair(8,2));
    chessMap[1][7]=cg.generateChess("pawn",1)->setPos(make_pair(1,7));
    chessMap[2][7]=cg.generateChess("pawn",1)->setPos(make_pair(2,7));
    chessMap[3][7]=cg.generateChess("pawn",1)->setPos(make_pair(3,7));
    chessMap[4][7]=cg.generateChess("pawn",1)->setPos(make_pair(4,7));
    chessMap[5][7]=cg.generateChess("pawn",1)->setPos(make_pair(5,7));
    chessMap[6][7]=cg.generateChess("pawn",1)->setPos(make_pair(6,7));
    chessMap[7][7]=cg.generateChess("pawn",1)->setPos(make_pair(7,7));
    chessMap[8][7]=cg.generateChess("pawn",1)->setPos(make_pair(8,7));
    for (size_t i = 1; i < 9; i++)
    {
        for (size_t j = 1; j < 9; j++)
        {
            if(chessMap[i][j]!=NULL)
                printChess(*chessMap[i][j]);
        }

    }

}

void reFlashChess(){
    system("cls");
    printCheckerboard();
    for (size_t i = 1; i < 9; i++)
    {
        for (size_t j = 1; j < 9; j++)
        {
            if(chessMap[i][j]!=NULL)
                printChess(*chessMap[i][j]);
        }

    }
}


#endif //CHESSGAME_FUNCTIONS_H
