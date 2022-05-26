//
// Created by PBemmm on 2022/5/18.
//
#ifndef CHESSGAME_CHESS_H
#define CHESSGAME_CHESS_H
using namespace std;

class Chess{
protected:
    int side;// 0 refer to white and 1 refer to black
    string type;//the type of the chess
    bool live;
    pair<int, int> position;//first X second Y
    int step[500];
public:
    Chess(const Chess& obj){
        //copy function

    }

    Chess() {}

    int getSide(){
        return side;
    }
    string getType(){
        return type;
    }
    pair<int,int> getPos(){
        return position;
    }
    Chess* setPos(const pair<int,int> pos){
        chessMap[pos.first][pos.second] = this;
        this->position = pos;
        printChess(*chessMap[position.first][position.second]);
        return this;
    }
    void dislove(){
        pair<int, int>pos = this->getPos();
        gotoxy(pos.first*4, (9-pos.second)*2-1);
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout<<L"  ";
        _setmode(_fileno(stdout),O_TEXT);
    }
    bool getStatus(){
        return live;
    }
    void killed(){
        live = false;
        if(this->getType()=="king"){
            if(this->getSide() == 0) whiteK = false;
            else blackK = false;
        }
        dislove();
    }
    virtual bool move(int targetX,int targetY){return false;};
    void setStep(int Turn, int Step){
        this->step[Turn] = Step; 
    }
    int getStep(int Turn){
        return this->step[Turn];
    }
};

class King : public Chess{
public:
    King(int sid){
        type = "king";
        side = sid;
        live = true;
    }

     bool move(int targetX,int targetY){
        if(targetY==position.second && targetX==position.first)return false;
        if(abs(targetY-position.second)>1 || abs(targetX-position.first)>1) return false;
        if(chessMap[targetX][targetY]!=NULL){
            chessMap[targetX][targetY]->killed();
            printChess(*chessMap[targetX][targetY]);
        }
        chessMap[position.first][position.second]->dislove();
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        return true;
     }
};
class Queen : public Chess{
public:
    Queen(int sid){
        type = "queen";
        side = sid;
        live = true;
    }
    bool move(int targetX,int targetY){
        if(targetY==position.second && targetX==position.first)return false;
        
        if(targetX == position.first || targetY == position.second){
            for (int i = position.first; i <= targetX; ++i) {
                for (int j = position.second; j <= targetY; ++j) {
                    if(i==position.first && j==position.second) continue;
                    if(i == targetX && j == targetY) break;
                    if(chessMap[i][j]!=NULL) return false;
                }
            }
        }else if(abs((targetX-position.first)/(targetY-position.second)) == 1){
            int frX,toX,frY,toY;
            frX=min(targetX,position.first)+1,toX=max(targetX,position.first);
            frY=min(targetY,position.second)+1,toY=max(targetY,position.second);
            while (frX!=toX && frY!=toY){
                if(chessMap[frX][frY]!=NULL) return false;
                frX++,frY++;
            }
        } else{
            return false;
        }

        if(chessMap[targetX][targetY]!=NULL){
            chessMap[targetX][targetY]->killed();
            printChess(*chessMap[targetX][targetY]);
        }
        chessMap[position.first][position.second]->dislove();
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        return true;
    }
};
class Knight : public Chess{
public:
    Knight(int sid){
        type = "knight";
        side = sid;
        live = true;
    }
    bool move(int targetX,int targetY){
         if(targetY==position.second && targetX==position.first)return false;
        
         //check whether the movement of Knight is correct
         if(!( (abs(targetY - position.second) == 2 && abs(targetX - position.first) == 1) 
         || (abs(targetY - position.second) == 1 && abs(targetX - position.first) == 2) )) return false;

         if(chessMap[targetX][targetY] != NULL){
             if( (*chessMap[targetX][targetY]).getSide() == (*chessMap[position.first][position.second]).getSide() ) return false;
             chessMap[targetX][targetY]->killed();
             printChess(*chessMap[targetX][targetY]);
         }
         chessMap[position.first][position.second]->dislove();
         chessMap[position.first][position.second]=NULL;
         setPos(make_pair(targetX,targetY));
         return true;
     }
};
class Bishop : public Chess{
public:
    Bishop(int sid){
        type = "bishop";
        side = sid;
        live = true;
    }
    bool move(int targetX,int targetY){
         if(targetY==position.second && targetX==position.first)return false;

         if(abs((targetX-position.first)/(targetY-position.second)) == 1){
             int frX,toX,frY,toY;
             frX=min(targetX,position.first)+1,toX=max(targetX,position.first);
             frY=min(targetY,position.second)+1,toY=max(targetY,position.second);
             while (frX!=toX && frY!=toY){
                 if(chessMap[frX][frY]!=NULL) return false;
                 frX++,frY++;
             }
         } else{
             return false;
         }

         if(chessMap[targetX][targetY]!=NULL){
             chessMap[targetX][targetY]->killed();
             printChess(*chessMap[targetX][targetY]);
         }
         chessMap[position.first][position.second]->dislove();
         chessMap[position.first][position.second]=NULL;
         setPos(make_pair(targetX,targetY));
         return true;
     }
};
class Rook : public Chess{
public:
    Rook(int sid){
        type = "rook";
        side = sid;
        live = true;
    }
    bool move(int targetX,int targetY){
        if(targetY==position.second && targetX==position.first)return false;

        if(targetX == position.first || targetY == position.second){
            for (int i = position.first; i <= targetX; ++i) {
                for (int j = position.second; j <= targetY; ++j) {
                    if(i==position.first && j==position.second) continue;
                    if(i == targetX && j == targetY) break;
                    if(chessMap[i][j]!=NULL) return false;
                }
            }
        }else{
            return false;
        }
        if(chessMap[targetX][targetY]!=NULL){
            chessMap[targetX][targetY]->killed();
            printChess(*chessMap[targetX][targetY]);
        }
        chessMap[position.first][position.second]->dislove();
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        return true;
    }
};
class Pawn : public Chess{
    bool first=true;
    int dir;
public:
    Pawn(int sid){
        type = "pawn";
        side = sid;
        live = true;
        if(side) dir = 1;
        else dir = -1;
    }
    bool move(int targetX,int targetY){
        if(targetY==position.second) return false;
        if(dir*(targetY-position.second) > 0) return false;

        if(targetX==position.first){
            if(abs(targetY - position.second) == 2){
                if(!first) return false;
                if(chessMap[targetX][targetY]!=NULL || chessMap[targetX][targetY+dir]!=NULL) return false;
            }else if(abs(targetY - position.second) == 1){
                if(chessMap[targetX][targetY]!=NULL) return false;
                
            }else{
                return false;
            }
        }else if(abs(targetX-position.first) == 1){
            if(chessMap[targetX][targetY] == NULL){
                if(chessMap[targetX][position.second] == NULL) 
                    return false;
                //过路卒
                if(this->getSide() != chessMap[targetX][position.second]->getSide() && chessMap[targetX][position.second]->getStep(turn-1) == 2){
                    chessMap[targetX][position.second]->killed();
                }
                else return false;
            }
            else chessMap[targetX][targetY]->killed();
        }
        this->setStep(turn, abs(position.second - targetY));
        chessMap[position.first][position.second]->dislove();
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        //兵变：输出当前兵子可以变了，然后提供变化的选项


        //
        //chessMap[targetX][targetY]->killed();
        //chessMap[targetX][targetY] = 要变成的棋子
        return true;
     }
};

//工厂模式生成棋子
class ChessGenerator{
public:
    Chess* generateChess(string type,int sid){
        if(type == "king"){
            return new King(sid);
        }
        if(type == "queen"){
            return new Queen(sid);
        }
        if(type == "bishop"){
            return new Bishop(sid);
        }
        if(type == "knight"){
            return new Knight(sid);
        }
        if(type == "rook"){
            return new Rook(sid);
        }
        if(type == "pawn"){
            return new Pawn(sid);
        }
        return NULL;
    }
};
#endif //CHESSGAME_CHESS_H
