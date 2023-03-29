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
			cout << "��ǻ�� ����:" << nComBingo << endl << endl;
			ShowTable(nUserTable);
			cout << "���� ���� :" << nUserBingo << endl << endl;

			if (nUserBingo >= 3 && nComBingo >= 3)
			{
				cout << " ���� ���� �޼� _ ���� " << endl;
				break;
			}
			else if (nUserBingo >= 3)
			{
				cout << "���� ���� �޼� _ �̰��" << endl;
				break;
			}
			else if (nComBingo >= 3)
			{
				cout << "��ǻ�� ���� �޼� _ ����" << endl;
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
		cout << "0.�������� 1.�� ����";
		cin >> isPlaying;
	}
	return 0;
}
