#ifndef CHESSGAME_CHESS_H
#define CHESSGAME_CHESS_H
using namespace std;

class Chess{
protected:
    int side;// 0 refer to white and 1 refer to black
    string type;//the type of the chess
    bool live;//the staus whether the chess is still alive or dead
    pair<int, int> position;//first X second Y
    int step[500];
public:
    //the generator that has no parameter
    Chess() {}
    //the function that get the side of the chess. In order to protect the inner data, we used these functions to avoid changing them
    int getSide(){
        return side;
    }
    //get the type of the chess
    string getType(){
        return type;
    }
    //get the position of the chess
    pair<int,int> getPos(){
        return position;
    }
    //set the position of the chess, I used the Chess* to return because it's easier to store them in chessMap
    Chess* setPos(const pair<int,int> pos){
        chessMap[pos.first][pos.second] = this;
        this->position = pos;
        printChess(*chessMap[position.first][position.second]);
        return this;
    }
    //get whether the chess is still alive or dead
    bool getStatus(){
        return live;
    }
    //make some chess killed and if the chess is king then the game is over
    void killed(){
        live = false;
        if(this->getType()=="king"){
            if(this->getSide() == 0) whiteK = false;
            else blackK = false;
        }
    }
    //virtual method to make the function dynamic linked
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
    //the generator of the son class
    King(int sid){
        type = "king";
        side = sid;
        live = true;
    }
    //the move function of the chess return whether the chess moved and make sure the road is legal
     bool move(int targetX,int targetY){
        if(targetY==position.second && targetX==position.first)return false;
        if(chessMap[targetX][targetY] != NULL && chessMap[targetX][targetY]->getSide()==getSide()) return false;
        if(abs(targetY-position.second)>1 || abs(targetX-position.first)>1) return false;
        if(chessMap[targetX][targetY]!=NULL){
            chessMap[targetX][targetY]->killed();
            printChess(*chessMap[targetX][targetY]);
        }
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        return true;
     }
};
class Queen : public Chess{
public:
    //the generator of the son class
    Queen(int sid){
        type = "queen";
        side = sid;
        live = true;
    }
    //the move function of the chess return whether the chess moved and make sure the road is legal
    bool move(int targetX,int targetY){
        if(targetY==position.second && targetX==position.first)return false;
        if(chessMap[targetX][targetY] != NULL && chessMap[targetX][targetY]->getSide()==getSide()) return false;
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
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        return true;
    }
};
class Knight : public Chess{
public:
    //the generator of the son class
    Knight(int sid){
        type = "knight";
        side = sid;
        live = true;
    }
    //the move function of the chess return whether the chess moved and make sure the road is legal
    bool move(int targetX,int targetY){
         if(targetY==position.second && targetX==position.first)return false;
        if(chessMap[targetX][targetY] != NULL && chessMap[targetX][targetY]->getSide()==getSide()) return false;
         //check whether the movement of Knight is correct
         if(!( (abs(targetY - position.second) == 2 && abs(targetX - position.first) == 1) 
         || (abs(targetY - position.second) == 1 && abs(targetX - position.first) == 2) )) return false;

         if(chessMap[targetX][targetY] != NULL){
             if( (*chessMap[targetX][targetY]).getSide() == (*chessMap[position.first][position.second]).getSide() ) return false;
             chessMap[targetX][targetY]->killed();
             printChess(*chessMap[targetX][targetY]);
         }
         chessMap[position.first][position.second]=NULL;
         setPos(make_pair(targetX,targetY));
         return true;
     }
};
class Bishop : public Chess{
public:
    //the generator of the son class
    Bishop(int sid){
        type = "bishop";
        side = sid;
        live = true;
    }
    //the move function of the chess return whether the chess moved and make sure the road is legal
    bool move(int targetX,int targetY){
         if(targetY==position.second && targetX==position.first)return false;
        if(chessMap[targetX][targetY] != NULL && chessMap[targetX][targetY]->getSide()==getSide()) return false;
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
         chessMap[position.first][position.second]=NULL;
         setPos(make_pair(targetX,targetY));
         return true;
     }
};
class Rook : public Chess{
public:
    //the generator of the son class
    Rook(int sid){
        type = "rook";
        side = sid;
        live = true;
    }
    //the move function of the chess return whether the chess moved and make sure the road is legal
    bool move(int targetX,int targetY){
        if(targetY==position.second && targetX==position.first)return false;
        if(chessMap[targetX][targetY] != NULL && chessMap[targetX][targetY]->getSide()==getSide()) return false;
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
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        return true;
    }
};
class Pawn : public Chess{
    //private attributes that make sure the pawn move foward and the correct steps
    bool first=true;
    int dir;
public:
    //the generator of the son class
    Pawn(int sid){
        type = "pawn";
        side = sid;
        live = true;
        if(side) dir = 1;
        else dir = -1;
    }
    //the move function of the chess return whether the chess moved and make sure the road is legal
    bool move(int targetX,int targetY){
        if(targetY==position.second) return false;
        if(dir*(targetY-position.second) > 0) return false;
        if(chessMap[targetX][targetY] != NULL && chessMap[targetX][targetY]->getSide()==getSide()) return false;
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
        chessMap[position.first][position.second]=NULL;
        setPos(make_pair(targetX,targetY));
        //Promotion / 兵升变
        if(position.second == 8 && this->getSide() == 0){
            gotoxy(36, 23);
            cout << "Promotion! : " << endl;
            gotoxy(36, 24);
            cout << "Input : Q / K / B / R  to transform pawn into Queen / Knight / Bishop / Rook :";
            char choice;
            cin >> choice;
            if(choice == 'Q'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Queen(0);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
            if(choice == 'K'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Knight(0);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
            if(choice == 'B'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Bishop(0);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
            if(choice == 'R'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Rook(0);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
        }
        if(position.second == 1 && this->getSide() == 1){
            gotoxy(36, 23);
            cout << "Promotion! " << endl;
            gotoxy(36, 24);
            cout << "Input : Q / K / B / R  to transform pawn into Queen / Knight / Bishop / Rook :";
            char choice;
            cin >> choice;
            if(choice == 'Q'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Queen(1);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
            if(choice == 'K'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Knight(1);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
            if(choice == 'B'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Bishop(1);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
            if(choice == 'R'){
                chessMap[targetX][targetY] -> killed();
                chessMap[targetX][targetY] = new Rook(1);
                chessMap[targetX][targetY] -> setPos(make_pair(targetX, targetY));
            }
        }
        first = false;
        return true;
     }
};

//use the factory method to generate the chess object
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
