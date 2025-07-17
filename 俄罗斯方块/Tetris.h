#pragma once
#include<graphics.h>
#include<vector>
#include"Block.h"
using namespace std;
class Tetris
{
public:
	//构造函数
	Tetris(int rows, int cols, int left, int top, int blockSize);
	void init();//初始化
	void play();//开始游戏

private:
	void keyEvent();
	void updateWindow();
	int getDelay();
	void drop();
	void clearLine();
	void moveLeftRight(int offset);
	void rotate();
	void drawScore();
	void checkOver();
	void saveScore();//保存最高分
	void displayOver();

private:
	int delay;
	bool update;

	vector<vector<int>>map;
	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	Block* curBlock;
	Block* nextBlock;//预告方块
	Block bakBlock;  //备份上一个方块

	int score;//当前的分数
	int highestScore;//最高分
	int level;//当前关卡
	int lineCount;//当前消了多少行
	bool gameOver;

	IMAGE imgOver;
	IMAGE imgWin;
};

