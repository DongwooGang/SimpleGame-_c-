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
				cards[i * 13 + j].szShape = (char*)"��";	//	�� �� �� ��
				break;
			case E_DIA:
				cards[i * 13 + j].szShape = (char*)"��";	
				break;
			case E_HEART:
				cards[i * 13 + j].szShape = (char*)"��";		
				break;
			case E_CLOVER:
				cards[i * 13 + j].szShape = (char*)"��";	
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
		cout << "�ݾ��� �����Ͻÿ�(100~�����ݾ�) : ";
		cin >> nBet;

	}
	return nBet;
}


void Play(tagCard* cards, int* money, int* index, bool* playing)
{
	int nSelect;
	E_SELECT eSelect;
	int nBet;

	cout << "���� �ݾ� : " << *money << endl;
	cout << "1.���� 2.�ο� 3.���� (0.����) : ";
	cin >> nSelect;

	eSelect = (E_SELECT)nSelect;

	switch (eSelect)
	{
		case E_QUIT:
			cout << "������ ���� �մϴ�. " << endl;
			*playing = false;
			break;
		case E_HIGH:
			nBet = Betting(*money);
			if (cards[*index].nNumber > 7)
			{
				cout << "���� ����! : ";
				*money += nBet;
			}
			else
			{
				cout << "���� ����! : ";
				*money -= nBet;
			}
			cout << cards[*index].szShape << cards[*index].nNumber << endl;
			break;
		case E_LOW:
			nBet = Betting(*money);
			if (cards[*index].nNumber < 7)
			{
				cout << "���� ����! : ";
				*money += nBet;

			}
			else
			{
				cout << "���� ����! : ";
				*money -= nBet;
			}
			cout << cards[*index].szShape << cards[*index].nNumber << endl;
			break;
		case E_SEVEN:
			nBet = Betting(*money);
			if (cards[*index].nNumber == 7)
			{
				cout << "���� ����! : ";
				*money += nBet*2;

			}
			else
			{
				cout << "���� ����! : ";
				*money -= nBet;
			}
			cout << cards[*index].szShape << cards[*index].nNumber << endl;
			break;

	}
	*index += 6;
}
