#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   
void Displayboard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		for (j = 0; j < col; j++) {
			if (i < row - 1) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void Playermove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家行棋\n");
	while (1) {
		printf("请输入坐标>>:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x-1][y-1] == ' ') {
				board[x-1][y-1] = '*';
				break;
			}
			else {
				printf("该坐标被占用，请重新输入\n");
			}
		}
		else {
			printf("坐标非法，请重新输入！\n");
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑行棋>>:\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了
}
char IsWin(char board[ROW][COL], int row, int col) {
	int i = 0;
	//横三行
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//竖三列
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (1 == IsFull(board, ROW, COL)) {
		return 'Q';
	}
	return 'C';
}