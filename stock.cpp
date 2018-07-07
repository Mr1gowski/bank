#include <iostream>
#include <string>
#include "stock00.h"

const int  CLIENTS=4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	AcctABC * p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for(int i=0;i<CLIENTS;i++)
	{
		cout<<"podaj imie i nazwisko klienta ";
		getline(cin,temp);
		cout<<"podaj numer rachunku klienta ";
		cin>>tempnum;
		cout<<"podaj poczatkowy stan konta ";
		cin>>tempbal;
		cout<<"wpisz 1 dla brass lub 2 dla brassplus ";
		while(cin>>kind&& (kind !='1' &&kind !='2'))
		cout<<"wpisz 1 lub 2";
		if (kind=='1')
		p_clients[i]= new Brass(temp,tempnum,tempbal);
		else
		{
			double tmax, trate;
			cout<<"podaj limit debetu ";
			cin>>tmax;
			cout<<"podaj stope oprocentowania ";
			cin>>trate;
			p_clients[i]= new BrassPlus(temp,tempnum, tempbal,tmax,trate);
			
		}
		
		while (cin.get() !='\n')
		continue;
	}
	cout<<endl;
	for(int i=0;i<CLIENTS;i++)
	{
		p_clients[i]->ViewAcct();
		cout<<endl;
		
	}
	for (int i=0;i<CLIENTS;i++)
	{
		delete p_clients[i];
	}
	
}
