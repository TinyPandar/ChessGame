//
// Update by FrankLee on 2022/5/19.
//
#ifndef CHESSGAME_CHESS_H
#define CHESSGAME_CHESS_H
using namespace std;

class Chess{
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
    void setPos(pair<int,int> pos){
        this->position = pos;
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
    void killed(){
        live = false;
    }
    bool move(){

    }
};
class Queen : public Chess{
public:
    Queen(int sid){
        type = "queen";
        side = sid;
        live = true;
    }
    void killed(){
        live = false;
    }
    bool move(){

    }
};
class Knight : public Chess{
public:
    Knight(int sid){
        type = "knight";
        side = sid;
        live = true;
    }
    void killed(){
        live = false;
    }
    bool move(){

    }
};
class Bishop : public Chess{
public:
    Bishop(int sid){
        type = "bishop";
        side = sid;
        live = true;
    }
    void killed(){
        live = false;
    }
    bool move(){

    }
};
class Rook : public Chess{
public:
    Rook(int sid){
        type = "rook";
        side = sid;
        live = true;
    }
    void killed(){
        live = false;
    }
    bool move(){

    }
};
class Pawn : public Chess{
public:
    Pawn(int sid){
        type = "pawn";
        side = sid;
        live = true;
    }
    void killed(){
        live = false;
    }
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
        return nullptr;
    }
};
#endif //CHESSGAME_CHESS_H
