#include "SlidePuzzle.h"
using namespace std;

int main()
{
	system("mode con:lines=25 cols =48");
	srand(time(NULL));
	rand();

	HANDLE hOP;
	hOP = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = false;
	curInfo.dwSize = 1;
	SetConsoleCursorInfo(hOP, &curInfo);

	bool isPlaying = true;
	int nPuzzle[5][5];
	int nX = 4;
	int nY = 4;

	InitPuzzle(nPuzzle);
	Print(hOP, nPuzzle, nX, nY);

	while (isPlaying)
	{
		if (_kbhit())
		{
			system("cls");
			Keyboard(&isPlaying, nPuzzle, &nX, &nY);
			Print(hOP, nPuzzle, nX, nY);
			isPlaying = !Check(nPuzzle);

			if (isPlaying == false)
			{
				cout << " 게임 클리어 _게임을 종료합니다." << endl;
				system("pause");
			}
			while (_kbhit()) _getch();
		}
	}
	return 0;
}


