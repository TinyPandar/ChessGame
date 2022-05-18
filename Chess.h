//
// Created by FrankLee on 2022/5/18.
//
#ifndef CHESSGAME_CHESS_H
#define CHESSGAME_CHESS_H
using namespace std;

class Chess{ //Create the chess with new, and when the chess is killed use delete
private:
    int side;//black or white
    string type;//the type of the chess
    pair<int, int> position;
public:
    Chess(int s,string tp){
        this->side = s;
        this->type = tp;
    }
    Chess(const Chess& obj){
        //copy function
    }
    ~Chess(){
        //when the chess was killed, perform this part
    }
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
    virtual bool move() = 0;
};

class King : Chess{
    bool move(){

    }
};
class Queen : Chess{
    bool move(){

    }
};
class Knight : Chess{
    bool move(){

    }
};
class Bishop : Chess{
    bool move(){

    }
};
class Rook : Chess{
    bool move(){

    }
};
class Pawn : Chess{
    bool move(){

    }
};

#endif //CHESSGAME_CHESS_H
