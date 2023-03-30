#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include<conio.h>

using namespace std;

void Keyboard(bool* playing, int puzzle[5][5], int* x, int* y)
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && *x < 4)
	{
		Swap(&puzzle[*y][*x], &puzzle[*y][*x + 1]);
		(*x)++;
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && *x > 0)
	{
		Swap(&puzzle[*y][*x], &puzzle[*y][*x - 1]);
		(*x)--;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000 && *y > 0)
	{
		Swap(&puzzle[*y][*x], &puzzle[*y - 1][*x]);
		(*y)--;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && *y > 4)
	{
		Swap(&puzzle[*y][*x], &puzzle[*x][*x + 1]);
		(*x)++;
	}
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		*playing = false;
}

void Draw(HANDLE hOP, int x, int y, char* str, WORD color)
{
	DWORD dwCharsWritten;
	COORD cdFill = { x,y };

	FillConsoleOutputAttribute(hOP, color, strlen(str), cdFill, &dwCharsWritten);
	WriteConsoleOutputCharacter(hOP, str, strlen(str), cdFill, &dwCharsWritten);
}


void InitPuzzle(int puzzle[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			puzzle[i][j] = i * 5 + j + 1;
	}

	for (int i = 0; i < 1000; i++)
	{
		int nDestX = rand() % 5;
		int nDestY = rand() % 5;

		int nSrcX = rand() % 5;
		int nSrcY = rand() % 5;

		if ((nDestX = 4 && nDestY == 4) || (nSrcX == 4 && nSrcY == 4) || (nDestX == nSrcX && nDestY == nSrcY))
		{
			i--;
			continue;
		}


		int nTemp = puzzle[nDestY][nDestX];
		puzzle[nDestY][nDestX] = puzzle[nSrcY][nSrcX];
		puzzle[nSrcY][nSrcX] = nTemp;
	}
}

void Print(HANDLE hOP, int puzzle[5][5], int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char* szTemp = new char;
			if (j == x && i == y)
				DrawBlock(hOP, 10 + j * 6, 5 + i * 3, (char*)"бс", BG_WHITE | FG_BLACK);
			else
				DrawBlock(hOP, 10 + j * 6, 5 + i * 3, itoa(puzzle[i][j], szTemp, 10), BG_WHITE | FG_BLACK);
		}
	}

}
void DrawBlock(HANDLE hOP, int x, int y, char* str, WORD color)
{
	Draw(hOP, x + 0, y + 0, str, color);
	Draw(hOP, x + 2, y + 0, (char*)"бс", color);
	Draw(hOP, x + 0, y + 1, (char*)"бс", color);
	Draw(hOP, x + 2, y + 1, (char*)"бс", color);
}
void Swap(int* prevBlock, int* currBlock)
{
	int nTemp = *prevBlock;
	*prevBlock = *currBlock;
	*currBlock = nTemp;

}
bool Check(int puzzle[5][5])
{
	bool isComplete = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 4 && j == 4)
				isComplete = true;
			if (puzzle[i][j] != j + 1 + i * 5)
				break;

		}
	}
	return isComplete;
}


