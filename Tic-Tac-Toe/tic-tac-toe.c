#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("****   1. play   0. exit    ****\n");
	printf("********************************\n");
}

void game()
{
	char ret = 0;
	//Array - store board information
	char board[ROW][COL] = {0}; //all spaces
	//Initialize the board
	InitBoard(board, ROW, COL);
	//Print board
	DisplayBoard(board, ROW, COL);
	//Play chess
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//Judge win or lose
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') 
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("Player win\n");
	}
	else if (ret == '#')
	{
		printf("Computer win\n");
	}
	else
	{
		printf("Draw\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Tic-Tic-Toe\n");
			game();
			break;
		case 0:
			printf("Exit Game\n");
			break;
		default:
			printf("Select error, please try again\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}