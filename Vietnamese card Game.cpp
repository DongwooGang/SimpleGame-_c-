#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	rand();
	
	int nMoney = 200;
	int nBet;
	int nAddBet;
	int nCards[12];
	bool isPlaying =true;
	
	while (isPlaying)
	{
		for (int i= 1;i<=12;i++)
			nCards[i-1] =i;
		for (int i=0;i<100;i++)
		{
			int nSrc = rand()%12;
			int nDest = rand()%12;
			int nTemp = nCards[nSrc];
			nCards[nSrc] = nCards[nDest];
			nCards[nDest] = nTemp;
		}
		nBet = 200;
		nAddBet = 1;
		
		if (nCards[0]>nCards[1])
		{
			int nTemp = nCards[0];
			nCards[0]=  nCards[1];
			nCards[1] = nTemp;
		}
		
		while(true)
		{
			system("cls");
			cout <<"현재 보유 금액 : " << nMoney <<endl;
			cout << "=========================" << endl;
			cout <<"현재 베팅 금액 : " <<nBet *nAddBet << endl;
			cout <<" 오픈 카드 : "<<nCards[0] << "~" << nCards[1] << endl;
			cout << " 승부 카드 :?" << endl;
			cout <<" 추가 오픈 :\t" ;
			
			int nIndex =0;
			for (int i =2;i<=nAddBet;i*=2)
			{
				cout << nCards[3+(nIndex++)] << "\t";
			}
			for (int i=nAddBet;i<8;i*=2)
				cout << "?\t";
			cout <<endl;
			
			int nSelect;
			cout << "1.포기 2.승부 3.추가베팅";
			cin >> nSelect;
			
			if (nSelect ==1)
			{
				cout <<"게임 포기 "<< endl;
				cout <<"승부 카드 : " << nCards[2] << endl;
				nMoney -=nBet *nAddBet /2;
				break;
				
			}
			else if (nSelect ==2)
			{
				cout <<"승부--" << endl;
				cout <<"승부 카드 : "<< nCards[2] << endl;
				if (nCards[2]>nCards[0]&&nCards[2]<nCards[1])
				{
					cout <<"플레이어 승리" << endl;
					nMoney += nBet * nAddBet;
				}
				else 
				{
					cout <<"플레이어 패배!!" << endl;
					nMoney -= nBet*nAddBet;
					
				}
				break;
			}
			else if (nSelect==3)
			{
				if (nMoney <nBet *nAddBet*2)
					cout << "보유 금액이 부족합니다." << endl;
				else
					nAddBet *=2 ;
					
			}
			else
			{
				cout << "선택 범위 안에서 숫자를 고르세요."<< endl;
			}
			
		}
		if (nMoney <200)
		{
			cout <<" 더 이상 플레이를 할 금액이 없습니다."<<endl
			<< "게임을 종료합니다." << endl;
			isPlaying =false;
			
		}
		else 
		{
			char chYN;
			cout <<"다음 게임(y,n)";
			cin >> chYN;
			if (chYN =='n')
				isPlaying =false;
		}
	}
	system("pasuse");
	return 0;
}
