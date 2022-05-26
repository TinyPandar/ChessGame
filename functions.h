#ifndef CHESSGAME_FUNCTIONS_H
#define CHESSGAME_FUNCTIONS_H



using namespace std;



//the function hiding the cursor on the terminal,which is learnt from the internet
void hideCursor() { 
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x, int y) { //Move the cursor to the function of (x,y)
    COORD c;  
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}
int setColor(int c) {//for easier to change color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);      //for easier to change color
    return 0;
}
void changeSide(){//change the side between black and white
    if(sideFlag==0){
        sideFlag=1;
        t1= time(NULL);
        whitetime += t1-t2;
    }else{
        sideFlag=0;
        t1= time(NULL); 
        blacktime += t1-t2;
    }
    gotoxy(74, 22);
    cout << "Now,it turns to ";
    if(sideFlag==1)
        cout<<"Black";
    else cout<<"White";
}
void printBegin(){//print the welcome interface
    gotoxy(49,11);
    cout<<"Chess Game";
    gotoxy(29, 21);
    cout<<"Welcome to the chess";
    gotoxy(29, 23);
    cout<<"Please choose number and press 'ENTER' twice";
    gotoxy(29, 25);
    setColor(11);
    cout<<"[1]play\t\t[2]exist";
    gotoxy(45, 33);
    setColor(7);
    cout<<"Tips:balbala";
    gotoxy(1,1);
    setColor(14);          			//Yellow border
    for (int i = 20; i <= 26; i++) { 	//Output left and right
        for (int j = 27; j <= 74; j++) {//Output upper and lower
            gotoxy(j, i);
            if (i == 20 || i == 26) {
                printf("-");
            } else if (j == 27 || j == 74) {
                printf("|");
            }
        }
    }
    gotoxy(36,28);
    while(1){     //give choice
        int x;
        cin>>x;
        if(x==1){
            setColor(7);
            break;
        }
        else if(x==2){
            exit(0);
        }else
            cout<<"Please put in the given number";
    }
}
void printEnd(int side){//print the end interface
    gotoxy(49,10);
    cout<<"Game Over";
    gotoxy(29, 12);
    cout<<"Congratulations to ";
    setColor(11);
    if(side==1)
        cout<<"The Black won!!";
    else
        cout<<"The White won!!";
    setColor(7);
    gotoxy(29, 14);
    cout<<"total time used:"<<totalTime<<"seconds";
    gotoxy(29, 16);
    cout<<"Black time used:"<<blacktime<<"seconds";
    gotoxy(29, 18);
    cout<<"White time used:"<<whitetime<<"seconds";
    setColor(14);          			//Yellow border
    for (int i = 8; i <= 26; i++) { 	//Output left and right
        for (int j = 27; j <= 74; j++) {//Output upper and lower
            gotoxy(j, i);
            if (i == 8 || i == 26) {
                printf("-");
            } else if (j == 27 || j == 74) {
                printf("|");
            }
        }
    }
    int n;
    cin>>n;
    exit(0);
}

//the function that used to print the unicode character of the given referance of a chess;
void printChess(Chess& chess){
    pair<int, int>pos = chess.getPos();
    gotoxy(pos.first*4, (9-pos.second)*2-1);
    //if the chess is dead so we clear its body
    if(chess.getStatus()==false) {
        wcout<<" ";
        return;
    }
    //the method to print a unicode character in the terminal
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
//print the checker board in unicode
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
//the initializing function that generate the chess and place them on the chessMap
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
    //after place them then we print them
    for (size_t i = 1; i < 9; i++)
    {
        for (size_t j = 1; j < 9; j++)
        {
            if(chessMap[i][j]!=NULL)
                printChess(*chessMap[i][j]);
        }

    }

}
//in order to avoid some bugs on the vitrual system of mac, we use the method to clear the terminal and print the GUI again 
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

void mainMove(int size) {
    fflush(stdin);
    gotoxy(36, 20);
    t2 = time(NULL);
    if (size == 0) {
        cout << "Now is Turn to White!" << endl;
    }
    if (size == 1) {
        cout << "Now is Turn to Black!" << endl;
    }
    cout << "Please select the pieces:(eg:a 2)";

    scanf("%c %c", &select_1, &select_2);
    fflush(stdin);
    cout << "Please enter the position of the piece to go:(eg:a 3)";
    scanf("%c %c", &select_3, &select_4);
    fflush(stdin);
    intSelect_1 = select_1 - 96, intSelect_2 = select_2 - 48, intSelect_3 = select_3 - 96, intSelect_4 =
            select_4 - 48;
    if (intSelect_1 <= 8 && intSelect_1 > 0 && intSelect_2 <= 8 && intSelect_2 > 0 && intSelect_3 <= 8 &&
        intSelect_3 > 0 && intSelect_4 <= 8 && intSelect_4 > 0) {
        if (chessMap[intSelect_1][intSelect_2] == NULL) {
            reFlashChess();
            gotoxy(45, 15);
            cout << "ERROR INPUT,Please check again!" << endl;
            return;
        }
        if (chessMap[intSelect_1][intSelect_2]->getSide() != size) {
            reFlashChess();
            gotoxy(45, 15);
            cout << "ERROR INPUT,Please Input white chess!" << endl;
            return;
        }
        if (chessMap[intSelect_1][intSelect_2]->move(intSelect_3, intSelect_4)) {
            turn++;
            changeSide();
            reFlashChess();
            return;
        } else {
            reFlashChess();
            gotoxy(45, 15);

            cout << "ERROR to move,please try again!" << endl;
            return;
        }
    } else {
        reFlashChess();
        gotoxy(45, 15);
        wcout << "ERROR INPUT,please check your Input again!" << endl;
        return;
    }

}

#endif //CHESSGAME_FUNCTIONS_H
