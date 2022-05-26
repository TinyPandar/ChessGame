#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <mutex>
#include <pthread.h>


using namespace std;

class Chess;

Chess *chessMap[9][9];
bool whiteK = true, blackK = true;
int sideFlag = 0;//mark the term of which side
int turn = 0;
char select_1, select_2, select_3, select_4, temp;
int intSelect_1, intSelect_2, intSelect_3, intSelect_4, win = 2;
time_t startTime, blacktime, whitetime, t1, t2;

void gotoxy(int x, int y);

void hideCursor();

void printCheckerboard();

void printChess(Chess &chess);

void printTime(time_t beginTime);

void printRounds();

void printBegin();


void printTips();

void initialize();

void mainMove(int size);

#include "Chess.h"
#include "functions.h"


int main() {
    hideCursor();
    printBegin();
    temp = getchar();
    system("cls");
    printCheckerboard();
    startTime = time(NULL);
    initialize();
    /*
     * 进入核心函数
     */
    while (whiteK && blackK) {
        mainMove(turn % 2);
    }
    t1 = time(NULL);
    if (whiteK == false){
        win = 1;
        blacktime += t1 - t2;
    }else{
        win = 0;
        whitetime += t1 - t2;
    }
    system("cls");
    printEnd(win);
    return 0;
}

void mainMove(int size) {
    fflush(stdin);
    gotoxy(36, 20);
    t1 = time(NULL);
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
            gotoxy(40, 15);
            cout << "ERROR INPUT,Please check again!" << endl;
            return;
        }
        if (chessMap[intSelect_1][intSelect_2]->getSide() != size) {
            reFlashChess();
            gotoxy(40, 15);
            cout << "ERROR INPUT,Please Input white chess!" << endl;
            return;
        }
        if (chessMap[intSelect_1][intSelect_2]->move(intSelect_3, intSelect_4)) {
            turn++;
            changeSide();
            reFlashChess();
            return;
        } else {
            gotoxy(40, 15);
            reFlashChess();
            cout << "ERROR to move,please try again!" << endl;
            return;
        }
    } else {
        reFlashChess();
        gotoxy(40, 15);
        wcout << "ERROR INPUT,please check your Input again!" << endl;
        return;
    }

}
