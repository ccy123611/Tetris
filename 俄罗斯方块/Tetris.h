#pragma once
#include<graphics.h>
#include<vector>
#include"Block.h"
using namespace std;
class Tetris
{
public:
	//���캯��
	Tetris(int rows, int cols, int left, int top, int blockSize);
	void init();//��ʼ��
	void play();//��ʼ��Ϸ

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
	void saveScore();//������߷�
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
	Block* nextBlock;//Ԥ�淽��
	Block bakBlock;  //������һ������

	int score;//��ǰ�ķ���
	int highestScore;//��߷�
	int level;//��ǰ�ؿ�
	int lineCount;//��ǰ���˶�����
	bool gameOver;

	IMAGE imgOver;
	IMAGE imgWin;
};

