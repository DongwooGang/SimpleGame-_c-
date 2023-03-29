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
			cout <<"���� ���� �ݾ� : " << nMoney <<endl;
			cout << "=========================" << endl;
			cout <<"���� ���� �ݾ� : " <<nBet *nAddBet << endl;
			cout <<" ���� ī�� : "<<nCards[0] << "~" << nCards[1] << endl;
			cout << " �º� ī�� :?" << endl;
			cout <<" �߰� ���� :\t" ;
			
			int nIndex =0;
			for (int i =2;i<=nAddBet;i*=2)
			{
				cout << nCards[3+(nIndex++)] << "\t";
			}
			for (int i=nAddBet;i<8;i*=2)
				cout << "?\t";
			cout <<endl;
			
			int nSelect;
			cout << "1.���� 2.�º� 3.�߰�����";
			cin >> nSelect;
			
			if (nSelect ==1)
			{
				cout <<"���� ���� "<< endl;
				cout <<"�º� ī�� : " << nCards[2] << endl;
				nMoney -=nBet *nAddBet /2;
				break;
				
			}
			else if (nSelect ==2)
			{
				cout <<"�º�--" << endl;
				cout <<"�º� ī�� : "<< nCards[2] << endl;
				if (nCards[2]>nCards[0]&&nCards[2]<nCards[1])
				{
					cout <<"�÷��̾� �¸�" << endl;
					nMoney += nBet * nAddBet;
				}
				else 
				{
					cout <<"�÷��̾� �й�!!" << endl;
					nMoney -= nBet*nAddBet;
					
				}
				break;
			}
			else if (nSelect==3)
			{
				if (nMoney <nBet *nAddBet*2)
					cout << "���� �ݾ��� �����մϴ�." << endl;
				else
					nAddBet *=2 ;
					
			}
			else
			{
				cout << "���� ���� �ȿ��� ���ڸ� ������."<< endl;
			}
			
		}
		if (nMoney <200)
		{
			cout <<" �� �̻� �÷��̸� �� �ݾ��� �����ϴ�."<<endl
			<< "������ �����մϴ�." << endl;
			isPlaying =false;
			
		}
		else 
		{
			char chYN;
			cout <<"���� ����(y,n)";
			cin >> chYN;
			if (chYN =='n')
				isPlaying =false;
		}
	}
	system("pasuse");
	return 0;
}
