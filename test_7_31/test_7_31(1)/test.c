#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("***********************************\n");
	printf("**********1.play  0.exit***********\n");
	printf("***********************************\n");
}
void game()
{
	char board[Row][Col] = { 0 };  //��¼
	char ret = 0;
	InitBoard(board, Row, Col);
	DisplayBoard(board, Row, Col);
	while (1) //����ߣ������ߣ�ѭ������   
	{
		playermove(board, Row, Col);  //�߼����������꣬���Ƿ�Ϸ������ſ��Ƿ�ռ�ã�û�б�ռ�ã����Է�һ���ַ�������Ƿ���ռ�ã�����������
		ret = iswin(board, Row, Col);//�ж���Ӯ������Һ͵��Ժ���ֱ��ж���Ӯ
		if (ret != 'C')
			break;
		DisplayBoard(board, Row, Col);//�߼�������ߣ������һ��λ�ã������ռ�ã�����������
		computermove(board, Row, Col);
		ret = iswin(board, Row, Col);
		if (ret != 'C')
			break;
		DisplayBoard(board, Row, Col);
	}
	if (ret == '*')  //�����߼�
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, Row, Col);  //break����ѭ����û�д�ӡ�����������
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //��������ֻ�õ���һ��
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����,����������\n");
			break;
		}
	} while (input);
	return 0;
}