#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("************************************\n");
	printf("****   1.开始游戏  2.退出游戏   ****\n");
	printf("************************************\n");
}
void game() {
	char board[ROW][COL] = { 0 };
	//初始化
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	char ret = 0;
	while (1) {
		// 玩家下棋
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("玩家胜利\n");
	}
	else if (ret == '#') {
		printf("电脑胜利\n");
	}
	else {
		printf("平局");
	}
}
void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择>>:");
		scanf("%d", &input);
		switch (input) {
			case 1:
				game();
				break;
			case 2:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入!\n");
				break;
		}
	} while (input!=2);
}

int main() {
	test();
	return 0;
}