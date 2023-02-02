#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("************************************\n");
	printf("****   1.��ʼ��Ϸ  2.�˳���Ϸ   ****\n");
	printf("************************************\n");
}
void game() {
	char board[ROW][COL] = { 0 };
	//��ʼ��
	Initboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	char ret = 0;
	while (1) {
		// �������
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//��������
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("���ʤ��\n");
	}
	else if (ret == '#') {
		printf("����ʤ��\n");
	}
	else {
		printf("ƽ��");
	}
}
void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��>>:");
		scanf("%d", &input);
		switch (input) {
			case 1:
				game();
				break;
			case 2:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�����������������!\n");
				break;
		}
	} while (input!=2);
}

int main() {
	test();
	return 0;
}