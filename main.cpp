#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

class Chess;

Chess *chessMap[9][9];
bool whiteK = true, blackK = true;
int sideFlag = 0;//mark the term of which side
char select_1, select_2, select_3, select_4, temp;
int intSelect_1, intSelect_2, intSelect_3, intSelect_4;
time_t startTime, blacktime, whitetime, t1, t2;

void gotoxy(int x, int y);

void hideCursor();

void printCheckerboard();

void printChess(Chess &chess);

void printTime(time_t beginTime);

void printRounds();

void printBegin();

void printEnd();

void printTips();

void initialize();

#include "Chess.h"
#include "functions.h"


int main() {
    hideCursor();
    printBegin();
    system("cls");
    printCheckerboard();
    initialize();
    /*
     * 进入核心函数
     */
    int turn = 0;
    while (whiteK && blackK) {
        /*
         * 白方
         */
        if (turn % 2 == 0) {
            temp = getchar();
            gotoxy(36, 28);
            cout << "Now is Turn to White!" << endl;
            cout << "Please select the pieces:(eg:a 2)";

            scanf("%c %c", &select_1, &select_2);
            temp = getchar();
            cout << "Please enter the position of the piece to go:(eg:a 3)";
            scanf("%c %c", &select_3, &select_4);
            intSelect_1 = select_1 - 96, intSelect_2 = select_2 - 48, intSelect_3 = select_3 - 96, intSelect_4 =
                    select_4 - 48;
            if (intSelect_1 <= 8 && intSelect_1 > 0 && intSelect_2 <= 8 && intSelect_2 > 0 && intSelect_3 <= 8 &&
                intSelect_3 > 0 && intSelect_4 <= 8 && intSelect_4 > 0) {
                if (chessMap[intSelect_1][intSelect_2]->getSide() != 0) {
                    system("cls");
                    reFlashChess();
                    gotoxy(36, 26);
                    cout << "ERROR INPUT,Please Input white chess!" << endl;
                    continue;
                }
                if (chessMap[intSelect_1][intSelect_2]->move(intSelect_3, intSelect_4)) {
                    turn++;
                    system("cls");
                    reFlashChess();
                    continue;
                } else {
                    gotoxy(36, 26);
                    system("cls");
                    reFlashChess();
                    cout << "ERROR to move,please try again!" << endl;
                    continue;
                }
            } else {
                system("cls");
                reFlashChess();
                gotoxy(36, 26);
                cout << "ERROR INPUT,please check your Input again!" << endl;
                continue;
            }

        }

        /*
         * 黑方
         */
        if (turn % 2 == 1) {
            temp = getchar();
            gotoxy(36, 28);
            cout << "Now is Turn to Black!" << endl;
            cout << "Please select the pieces:(eg:a 2)";

            scanf("%c %c", &select_1, &select_2);
            temp = getchar();
            cout << "Please enter the position of the piece to go:(eg:a 3)";
            scanf("%c %c", &select_3, &select_4);
            intSelect_1 = select_1 - 96, intSelect_2 = select_2 - 48, intSelect_3 = select_3 - 96, intSelect_4 =
                    select_4 - 48;
            if (intSelect_1 <= 8 && intSelect_1 > 0 && intSelect_2 <= 8 && intSelect_2 > 0 && intSelect_3 <= 8 &&
                intSelect_3 > 0 && intSelect_4 <= 8 && intSelect_4 > 0) {
                if (chessMap[intSelect_1][intSelect_2]->getSide() != 1) {
                    system("cls");
                    reFlashChess();
                    gotoxy(36, 26);
                    cout << "ERROR INPUT,Please Input black chess!" << endl;
                    continue;
                }
                if (chessMap[intSelect_1][intSelect_2]->move(intSelect_3, intSelect_4)) {
                    turn++;
                    system("cls");
                    reFlashChess();
                    continue;
                } else {
                    gotoxy(36, 26);
                    system("cls");
                    reFlashChess();
                    cout << "ERROR to move,please try again!" << endl;
                    continue;
                }
            } else {
                system("cls");
                reFlashChess();
                gotoxy(36, 26);
                cout << "ERROR INPUT,please check your Input again!" << endl;
                continue;
            }

        }

    }

}
