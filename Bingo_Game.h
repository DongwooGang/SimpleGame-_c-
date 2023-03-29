#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

void InitTable(int* table)
{
	for (int i = 0; i < 25; i++)
	{
		table[i] = i + 1;
	}
	int nSrc;
	int nDest;
	int nTemp;

	for (int i = 0; i < 250; i++)
	{
		nSrc = rand() % 25;
		nDest = rand() % 25;
		nTemp = table[nSrc];
		table[nSrc] = table[nDest];
		table[nDest] = nTemp;
	}
}

void ShowTable(int* table)
{
	cout << "====================================" << endl;
	for (int i = 0; i < 25; i++)
	{
		cout << "| " << table[i] << "\t";
		if (i % 5 == 4)
		{
			cout << endl;
			cout << "====================================" << endl;
		}
	}
}

void HideTable(int* table)
{
	cout << "====================================" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (table[i] == 0)
			cout << "| 0\t|";
		else
			cout << "| ?\t|";
		if (i % 5 == 4)
		{
			cout << endl;
			cout << "====================================" << endl;
		}
	}
}

void UserSelect(int* userTable, int* comTable)
{
	int nSelect;
	cout << "선택(1~25) : ";
	cin >> nSelect;

	for (int i = 0; i < 25; i++)
	{
		if (nSelect == userTable[i])
		{
			userTable[i] = 0;
			for (int j = 0; j < 25; j++)
			{
				if (nSelect == comTable[j])
				{
					comTable[j] = 0;
					break;
				}
			}
			break;
		}
		if (i == 24)
		{
			cout << "제대로 선택하세요." << endl;
			Sleep(1000);
		}
	}
}

void ComSelect(int* userTable, int* comTable)
{
	int nIndex = 0;
	int nSelect;

	cout << "컴퓨터 선택 중";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;
	
	while (1)
	{
		nIndex = rand() % 25;
		nSelect = comTable[nIndex];

		if (nSelect != 0)
		{
			for (int i = 0; i < 25; i++)
			{
				if (nSelect == userTable[i])
				{
					userTable[i] = 0;
					break;
				}
			}
			comTable[nIndex] = 0;
			break;
		}
	}
	cout << "컴퓨터 선택 : " << nSelect << endl;
	Sleep(500);
}

int CheckBingo(int* table)
{
	int nBingo = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i * 5 + j] == 0)
			{
				if (j == 4) nBingo++;
			}
			else 
				break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i + j * 5] == 0)
			{
				if (j == 4) nBingo++;
			}
			else break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (table[i * 5 + i] == 0)
		{
			if (i == 4) nBingo++;
		}
		else
			break;
	}
	for (int i = 0; i < 5; i++)
	{
		if (table[(i + 1) * 4] == 0)
		{
			if (i == 4) nBingo++;
		}
		else break;
	}

	return nBingo;
}