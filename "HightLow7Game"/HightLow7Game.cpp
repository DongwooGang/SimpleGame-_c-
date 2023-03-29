#include"HightLow7Game.h"
using namespace std;

int main()
{
	srand(time(NULL));
	rand();

	tagCard stCards[52];
	bool isPlaying = true;
	int nMyMoney = 10000;
	int nCurrIndex = 5;

	InitCards(stCards);
	Suffle(stCards);

	system("pause");
	while (isPlaying)
	{
		system("cls");
		Print(stCards, nCurrIndex);
		if (nMyMoney < 100)
		{
			cout << "거지가 되었습니다. 게임장에서 나갑니다." << endl;
			isPlaying = false;
		}
		else if (nCurrIndex > 42)
		{
			Suffle(stCards);
			nCurrIndex = 5;
			cout << "새 카드로 게임을 계속 합니다." << endl;
			system("pause");
		}
		else
		{
			Play(stCards, &nMyMoney, &nCurrIndex, &isPlaying);
			Sleep(2000);
		}
	}
	system("pause");
	return 0;
}
