#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[Row][Col], int row, int col) //初始化棋盘  放空格，什么都没有
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
	memset(&board[0][0], ' ', sizeof(char)*row*col); //三个参数:初始化空间的起始位置，要初始的字符，初始的字节大小
}

void DisplayBoard(char board[Row][Col], int row, int col)  //打印棋盘
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)      //使代码具有扩展性，行和列都可以改变，则i和j的范围都为row和col
	{
		// * | * | * 
		for (j = 0; j < col; j++)            //数据行
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)      //为了棋盘美观，不打印最后一列'|'
				printf("|");
		}
		printf("\n");
		//---|---|---
		if (i < row - 1)          //为了棋盘美观，不打印最后一行'---|'
		{
			for (j = 0; j < col; j++)         //横线行
			{
				printf("---");
				if (j < col - 1)  //为了棋盘美观，不打印最后一列'|'
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
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col) //对玩家输入的坐标进行检测是否合法
		{
			if (board[x - 1][y - 1] == ' ')  //由于玩家会输入1-3的数据,所以将x和y减一
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，重新输入!\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
}

void computermove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row; //产生0到2的数字
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int isfull(char board[Row][Col], int row, int col)//是为了实现iswin函数，所以不用放在game.h声明
{ //static;修饰函数和全局变量，使得只能在当前源文件内部使用
	//       修饰局部变量，增强它的生命周期
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
	for (i = 0; i < row; i++) //判断是否有一行元素相同,共有三行
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 2; i++)//判断是否有一列元素相同，共有三列
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j])
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 2; i++)//判断主对角线(左上至右下)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2])
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 2; i++)//判断副对角线(左下至右上)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j + 2] != ' ' && board[i][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j])
			{
				return board[i][j + 2];
			}
		}
	}
	//平局
	if (isfull(board, row, col) == 1)
	{
		return 'Q';
	}
	//继续
	return 'C';
}
//四种情况：电脑赢 玩家赢 平局 继续 定义四个字符代表不同的状态
//          三行三列以及对角线