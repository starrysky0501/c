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
	char board[Row][Col] = { 0 };  //记录
	char ret = 0;
	InitBoard(board, Row, Col);
	DisplayBoard(board, Row, Col);
	while (1) //玩家走，电脑走，循环起来   
	{
		playermove(board, Row, Col);  //逻辑：输入坐标，看是否合法，接着看是否被占用，没有被占用，可以放一个字符，如果非法或被占用，则重新输入
		ret = iswin(board, Row, Col);//判断输赢，在玩家和电脑后面分别判断输赢
		if (ret != 'C')
			break;
		DisplayBoard(board, Row, Col);//逻辑：随机走，随便找一个位置，如果被占用，则重新输入
		computermove(board, Row, Col);
		ret = iswin(board, Row, Col);
		if (ret != 'C')
			break;
		DisplayBoard(board, Row, Col);
	}
	if (ret == '*')  //测试逻辑
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	DisplayBoard(board, Row, Col);  //break跳出循环后，没有打印棋盘最后的情况
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //整个程序只用调用一次
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误,请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}