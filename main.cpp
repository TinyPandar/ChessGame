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
time_t startTime, blacktime, whitetime, t1, t2, totalTime;

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
     * Enter the core loop
     */
    while (whiteK && blackK) {
        mainMove(turn % 2);
    }
    totalTime = time(NULL) - startTime;
    if (whiteK == false){
        win = 1;
        blacktime = totalTime - whitetime;
    }else{
        win = 0;
        whitetime = totalTime - blacktime;
    }
    system("cls");
    printEnd(win);
    return 0;
}

