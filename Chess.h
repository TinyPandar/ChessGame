//
// Created by FrankLee on 2022/5/18.
//
#ifndef CHESSGAME_CHESS_H
#define CHESSGAME_CHESS_H
using namespace std;

class Chess{ //Create the chess with new, and when the chess is killed use delete
protected:
    int side;//black or white
    string type;//the type of the chess
    bool live;
    pair<int, int> position;
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
    void setPos(pair<int,int> position){
        this->position = position;
    }
    bool getStatus(){
        return live;
    }
    virtual bool move(){return false;};
};

class King : public Chess{
public:
    King(int sid){
        type = "king";
        side = sid;
        live = true;
    }
    bool move(){

    }
    void killed(){
        live = false;
    }
};
class Queen : public Chess{
    bool move(){

    }
};
class Knight : public Chess{
    bool move(){

    }
};
class Bishop : public Chess{
    bool move(){

    }
};
class Rook : public Chess{
    bool move(){

    }
};
class Pawn : public Chess{
    bool move(){

    }
};
//工厂模式生成棋子
class ChessGenerator{
public:
    Chess* generateChess(string type,int sid){
        if(type == "king"){
            return new King(sid);
        }

        return nullptr;
    }
};
#endif //CHESSGAME_CHESS_H
