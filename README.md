更新声明，将主体函数的实现部分挪到了functions.h以后在那里更新函数内容即可

### 打印函数（局部刷新）

1. 打印棋盘
   void printCheckerboard();
   
   类型:void
   
   参数:无

2. 打印棋子
   void printChess();
   
   类型:void
   
   参数:无

3. 打印时间（游戏进行时间）
   void printTime(Time beginTime);
   
   类型:void
   
   参数:Time

4. 打印双方当前回合
   void printRounds();
   
   类型:void
   
   参数:无

~5. 打印移动是否合法bool checkMoveRight()；~

   ~通过棋子的getType方法来查看行走是否合法~


6. 打印开始欢迎引导界面
   void printBegin();
   
   类型:void
   
   参数:无

7. 打印结束界面
   void printEnd();
   
   类型:void
   
   参数:无

8.  小Tips界面
   void printTips();
   
	类型:void

	参数:无

### 棋子类

1. 私有变量
   1. int side;//black or white
   2. bool live;//live or die
   3. string type;//the type of the chess
   4. pair<int, int> position;
2. 公有方法
   1. int getSide();	//get the side of the chess(Black,White)
   2. string getType();    //get the type of the ches(King,Quen,Knight)
   3. pair<int,int> getPos();    //get the position of the chess on the map
   4. virtual bool move() = 0;    //the way chess move(Pure virtual function watiting for the derived class to  

### 全局变量

1. 记录会和是黑方还是白方的状态
2. 双方及总共用时
3. 新建一个二维数组用于存放各个棋子的地址
