#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define Row 3
#define Col 3

void InitBoard(char board[Row][Col], int row, int col);
void DisplayBoard(char board[Row][Col], int row, int col);
void playermove(char board[Row][Col], int row, int col);
void computermove(char board[Row][Col], int row, int col);
char iswin(char board[Row][Col], int row, int col);//* ���Ӯ��# ����Ӯ����Q��ƽ�֣���C������
