#pragma once

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>

using namespace std;

enum E_SHAPE{E_SPADE,E_DIA,E_HEART,E_CLOVER,E_MAX};
enum E_SELECT{E_QUIT,E_HIGH,E_LOW,E_SEVEN};

struct tagCard
{
	char* szShape;
	int nNumber;
};

void InitCards(tagCard* cards)
{
	for (E_SHAPE i = E_SPADE; i < E_MAX; i = (E_SHAPE)(i + 1))
	{
		for (int j = 0; j < 13; j++)
		{
			switch (i)
			{
			case E_SPADE:
				cards[i * 13 + j].szShape = (char*)"♠";	//	♥ ♠ ♣ ◆
				break;
			case E_DIA:
				cards[i * 13 + j].szShape = (char*)"◆";	
				break;
			case E_HEART:
				cards[i * 13 + j].szShape = (char*)"♥";		
				break;
			case E_CLOVER:
				cards[i * 13 + j].szShape = (char*)"♣";	
				break;

			}
			cards[i * 13 + j].nNumber = j + 1;
		}
	}
}
void Suffle(tagCard* cards)
{
	for (int i = 0; i < 1000; i++)
	{
		int nSrc = rand() % 52;
		int nDest = rand() % 52;
		tagCard stTemp = cards[nSrc];
		cards[nSrc] = cards[nDest];
		cards[nDest] = stTemp;
	}
}

void Print(tagCard* cards)
{
	for (int i = 0; i < 52; i++)
	{
		switch (cards[i].nNumber)
		{
		case 1:
			cout << cards[i].szShape << "A" << "\t";
			break;
		case 11:
			cout << cards[i].szShape << "J" << "\t";
			break;
		case 12:
			cout << cards[i].szShape << "Q" << "\t";
			break;
		case 13:
			cout << cards[i].szShape << "K" << "\t";
			break;
		default:
			cout << cards[i].szShape << cards[i].nNumber << "\t";
			break;

		}
		if (i % 13 == 12)
			cout << endl;
	}
}

void Print(tagCard* cards, int index)
{
	for (int i = index - 5; i < index; i++)
	{
		cout << cards[i].szShape << cards[i].nNumber << "\t";
	}
	cout << "\t( ? )" << endl;
}

int Betting(int money)
{
	int nBet = 0;
	while (nBet < 100 || nBet >money)
	{
		cout << "금액을 베팅하시오(100~보유금액) : ";
		cin >> nBet;

	}
	return nBet;
}


void Play(tagCard* cards, int* money, int* index, bool* playing)
{
	int nSelect;
	E_SELECT eSelect;
	int nBet;

	cout << "현재 금액 : " << *money << endl;
	cout << "1.하이 2.로우 3.세븐 (0.종료) : ";
	cin >> nSelect;

	eSelect = (E_SELECT)nSelect;

	switch (eSelect)
	{
		case E_QUIT:
			cout << "게임을 종료 합니다. " << endl;
			*playing = false;
			break;
		case E_HIGH:
			nBet = Betting(*money);
			if (cards[*index].nNumber > 7)
			{
				cout << "베팅 성공! : ";
				*money += nBet;
			}
			else
			{
				cout << "베팅 실패! : ";
				*money -= nBet;
			}
			cout << cards[*index].szShape << cards[*index].nNumber << endl;
			break;
		case E_LOW:
			nBet = Betting(*money);
			if (cards[*index].nNumber < 7)
			{
				cout << "베팅 성공! : ";
				*money += nBet;

			}
			else
			{
				cout << "베팅 실패! : ";
				*money -= nBet;
			}
			cout << cards[*index].szShape << cards[*index].nNumber << endl;
			break;
		case E_SEVEN:
			nBet = Betting(*money);
			if (cards[*index].nNumber == 7)
			{
				cout << "베팅 성공! : ";
				*money += nBet*2;

			}
			else
			{
				cout << "베팅 실패! : ";
				*money -= nBet;
			}
			cout << cards[*index].szShape << cards[*index].nNumber << endl;
			break;

	}
	*index += 6;
}
