#include "Bingo_Game.h"
using namespace std;

int main()
{
	srand(time(NULL));
	rand();

	int nUserTable[25];
	int nUserBingo = 0;
	int nComTable[25];
	int nComBingo = 0;

	bool isPlaying = true;
	bool isMyTurn = true;

	while (isPlaying)
	{
		InitTable(nUserTable);
		InitTable(nComTable);

		while (true)
		{
			system("cls");
			nUserBingo = CheckBingo(nUserTable);
			nComBingo = CheckBingo(nComTable);

			HideTable(nComTable);
			cout << "컴퓨터 빙고:" << nComBingo << endl << endl;
			ShowTable(nUserTable);
			cout << "유저 빙고 :" << nUserBingo << endl << endl;

			if (nUserBingo >= 3 && nComBingo >= 3)
			{
				cout << " 빙고 동시 달성 _ 비겼다 " << endl;
				break;
			}
			else if (nUserBingo >= 3)
			{
				cout << "유저 빙고 달성 _ 이겼다" << endl;
				break;
			}
			else if (nComBingo >= 3)
			{
				cout << "컴퓨터 빙고 달성 _ 졌다" << endl;
				break;
			}

			if (isMyTurn)
			{
				UserSelect(nUserTable, nComTable);
				isMyTurn = false;
			}
			else
			{
				ComSelect(nUserTable, nComTable);
				isMyTurn = true;
			}
		}
		cout << "0.게임종료 1.새 게임";
		cin >> isPlaying;
	}
	return 0;
}
