# ChessGame



1. 打印函数（局部刷新）
	a. 打印棋盘
		i. void printCheckerboard();
类型:void
参数:无
	b. 打印棋子
		i. void printChess();
类型:void
参数:无
	c. 打印时间（游戏进行时间）
		i. void printTime(Time beginTime);
类型:void
参数:Time
	d. 打印双方当前回合
		i. void printRounds();
类型:void
参数:无
	e. 打印移动是否合法
		i. bool checkMoveRight()；
			1. 通过棋子的getType方法来查看行走是否合法
类型:bool
参数:无
f. 打印开始欢迎引导界面
i. void printBegin();
类型:void
参数:无
g. 打印结束界面
i. void printEnd();
类型:void
参数:无
h. 小Tips界面
i. void printTips
类型:void
参数:无

2. 棋子类
	a. 私有变量
		i. int side;//black or white
		ii. bool live;//live or die
		iii. string type;//the type of the chess
		iv. pair<int, int> position;
	b. 公有方法
		i. int getSide(); //get the side of the chess(Black,White)
		ii. string getType(); //get the type of the ches(King,Quen,Knight)
		iii. pair<int,int> getPos(); //get the position of the chess on the map
		iv. virtual bool move() = 0; //the way chess move(Pure virtual function watiting for the derived class to  

3. 全局变量
1. 记录会和是黑方还是白方的状态
2. 双方及总共用时


新建一个二维数组用于存放各个棋子的地址
