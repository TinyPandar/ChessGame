#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
class Chess;
Chess* chessMap[9][9];
bool whiteK=true,blackK=true;
int sideFlag=0;//mark the term of which side
time_t startTime,blacktime,whitetime,t1,t2;
void gotoxy(int x, int y);
void hideCursor();
void printCheckerboard();
void printChess(Chess& chess);
void printTime(time_t beginTime);
void printRounds();
void printBegin();
void printEnd();
void printTips();
void initialize();
#include "Chess.h"
#include "functions.h"


int main(){
     hideCursor();
     printBegin();
     system("cls");
     printCheckerboard();
     initialize();
     while(1){
          int a,b,c,d;
          gotoxy(0,20);
          cin>>a>>b>>c>>d;
          chessMap[a][b]->move(c,d);
          gotoxy(0,20);
          cout<<"        ";
     }
     
}



