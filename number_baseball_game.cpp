#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	rand();
	
	int nRand1,nRand2,nRand3;
	int nUser1,nUser2,nUser3;
	int nStrike,nBall,nOut;
	
	int nCount = 0;
	bool bGame = true;
	
	while (bGame)
	{
		nRand1 = rand()% 9 +1;
		
		while (true)
		{
			nRand2 = rand()%9+1;
			if (nRand2!=nRand1)
				break;
		}
		while (true)
		{
			nRand3 =rand()%9 +1;
			if (nRand3!= nRand1&&nRand3!=nRand2)
				break;
		}
		nStrike =0;
	
		while (nStrike<3)
		{
			system("cls");
			nCount++;
			
			cout <<"ù��° ���ڸ� ���ÿ�(1~9) : ";
			cin >> nUser1;
			cout <<"�ι�° ���ڸ� ���ÿ�(1~9) : ";
			cin >> nUser2;
			cout <<"����° ���ڸ� ���ÿ�(1~9) : ";
			cin >> nUser3;	
			
			nStrike = nBall = nOut = 0;
			
			if (nUser1==nRand1)
				nStrike++;
			else if (nUser1 == nRand2 ||nUser1 == nRand3)
				nBall++;
			else
				nOut++;
			
			if (nUser2 == nRand2)
				nStrike++;
			else if (nUser2 == nRand1||nUser2 ==nRand3)
				nBall++;
			else
				nOut++;
			
			if (nUser3 ==nRand3)
				nStrike++;
			else if(nUser3 == nRand1||nUser3 == nRand2)
				nBall++;
			else
				nOut++;
			
			cout <<"��Ʈ����ũ:" << nStrike << endl;
			cout << " �� :" << nBall << endl;
			cout << " �ƿ� : " << nOut << endl;
			
			system("pause");
			
		}
		cout << "�� ���� Ƚ�� : " << nCount << endl;
		
		char chYN;
		cout << " �� ����(y,n)";
		cin >> chYN;
		
		if (chYN == 'n')
			bGame = false;
	}
	system("pause");
	return 0;
		
}
