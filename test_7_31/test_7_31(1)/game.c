#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[Row][Col], int row, int col) //��ʼ������  �ſո�ʲô��û��
{
	int i = 0;
	int j = 0;
	/*for (i = 0; i < row; i++)
	{
	for (j = 0; j < col; j++)
	{
	board[i][j] = ' ';
	}
	}*/
	memset(&board[0][0], ' ', sizeof(char)*row*col); //��������:��ʼ���ռ����ʼλ�ã�Ҫ��ʼ���ַ�����ʼ���ֽڴ�С
}

void DisplayBoard(char board[Row][Col], int row, int col)  //��ӡ����
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)      //ʹ���������չ�ԣ��к��ж����Ըı䣬��i��j�ķ�Χ��Ϊrow��col
	{
		// * | * | * 
		for (j = 0; j < col; j++)            //������
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)      //Ϊ���������ۣ�����ӡ���һ��'|'
				printf("|");
		}
		printf("\n");
		//---|---|---
		if (i < row - 1)          //Ϊ���������ۣ�����ӡ���һ��'---|'
		{
			for (j = 0; j < col; j++)         //������
			{
				printf("---");
				if (j < col - 1)  //Ϊ���������ۣ�����ӡ���һ��'|'
					printf("|");
			}
			printf("\n");
		}
	}
}

void playermove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col) //����������������м���Ƿ�Ϸ�
		{
			if (board[x - 1][y - 1] == ' ')  //������һ�����1-3������,���Խ�x��y��һ
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã���������!\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
}

void computermove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)
	{
		x = rand() % row; //����0��2������
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int isfull(char board[Row][Col], int row, int col)//��Ϊ��ʵ��iswin���������Բ��÷���game.h����
{ //static;���κ�����ȫ�ֱ�����ʹ��ֻ���ڵ�ǰԴ�ļ��ڲ�ʹ��
	//       ���ξֲ���������ǿ������������
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char iswin(char board[Row][Col], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++) //�ж��Ƿ���һ��Ԫ����ͬ,��������
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 2; i++)//�ж��Ƿ���һ��Ԫ����ͬ����������
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j])
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 2; i++)//�ж����Խ���(����������)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2])
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 2; i++)//�жϸ��Խ���(����������)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j + 2] != ' ' && board[i][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j])
			{
				return board[i][j + 2];
			}
		}
	}
	//ƽ��
	if (isfull(board, row, col) == 1)
	{
		return 'Q';
	}
	//����
	return 'C';
}
//�������������Ӯ ���Ӯ ƽ�� ���� �����ĸ��ַ�����ͬ��״̬
//          ���������Լ��Խ���