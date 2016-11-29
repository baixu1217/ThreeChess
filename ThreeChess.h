#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define Row 3
#define Col 3
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

//打印棋盘
void PrintChess(char arr[][Col],int row)
{
	printf("%c|%c|%c\n",arr[0][0],arr[0][1],arr[0][2]);
	printf("--------\n");
	printf("%c|%c|%c\n",arr[1][0],arr[1][1],arr[1][2]);
	printf("--------\n");
	printf("%c|%c|%c\n",arr[2][0],arr[2][1],arr[2][2]);
}

//玩家下棋
void Player(char arr[][Col],int row)
{
	int x = 0;
	int y = 0;
	printf("玩家玩\n");
	
	printf("请输入坐标:>");
	scanf("%d%d",&x,&y);
	x = x-1;
	y = y-1;
	while(arr[x][y] != ' ')
	{
		printf("输入数据不合法，请重新输入!\n");
		printf("请输入坐标:>");
		scanf("%d%d",&x,&y);
		x = x-1;       //现实中的坐标和计算机中的坐标相差1，所以横纵坐标各减1
		y = y-1;
	}
	if(arr[x][y] == ' ')
	{
		arr[x][y] = '*';
	}
	PrintChess(arr,row);
}

//电脑下棋
void Computer(char arr[][Col],int row)
{
	int x = rand()%row;
	int y = rand()%Col;
	printf("电脑玩\n");
	
	while(arr[x][y] != ' ')
	{
		x = rand()%row;
		y = rand()%Col;
	}
	if(arr[x][y] == ' ')
	{
		arr[x][y] = '#';
	}
	PrintChess(arr,row);
}

int Check(char arr[][Col])
{
	int j = 0;
	int i = 0;
	int count = 0;
	//判断是否三个坐标为一条线
	for(i = 0;i < 3;i++)
	{
		if((((arr[i][0] == arr[i][1])&&(arr[i][1] == arr[i][2]))&&(arr[i][1]== '*')) ||
							(((arr[0][i] == arr[1][i])&& (arr[1][i]== arr[2][i]))&&(arr[1][i]== '*')) ||
							(((arr[0][0] == arr[1][1])&&(arr[1][1]== arr[2][2]))&&(arr[1][1]== '*')) ||
							(((arr[0][2] == arr[1][1])&&(arr[1][1]== arr[2][0]))&&(arr[1][1]== '*')))
							{	
								return 1; 
							}
		if((((arr[i][0] == arr[i][1])&&(arr[i][1] == arr[i][2]))&&(arr[i][1]== '#')) ||
							(((arr[0][i] == arr[1][i])&& (arr[1][i]== arr[2][i]))&&(arr[1][i]== '#')) ||
							(((arr[0][0] == arr[1][1])&&(arr[1][1]== arr[2][2]))&&(arr[1][1]== '#')) ||
							(((arr[0][2] == arr[1][1])&&(arr[1][1]== arr[2][0]))&&(arr[1][1]== '#')))
							{	
								return -1; 
							}
		for(j = 0; j < 3;j++)
		{
	
			if(arr[i][j] != ' ')
			{
				count++;
			}
		}
	}
	if(count == 9)
	{
		printf("平局\n");
	}
	
}

void Game()
{
	char arr[Row][Col];
	int i = 0;
	int j = 0;
	memset(arr,' ',sizeof(char)*Row*Col);
	PrintChess(arr,Row);
	while(1)
	{
		Player(arr,Row);
		if(Check(arr) == 1)
		{
			printf("玩家赢！\n");
			return;
		}
		Computer(arr,Row);
		if(Check(arr) == -1)
		{
			printf("电脑赢！\n");
			return;
		}
	}
}
		


