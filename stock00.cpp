#include <iostream>
#include "stock00.h"

using std::cout;
using std::ios_base;
using std::endl;

using std::string;

AcctABC::AcctABC(const string &s,long an, double bal)
{
	fullName=s;
	acctNum=an;
	balance=bal;
}

void AcctABC::Deposit(double amt)
{
	if(amt<0)
	{
		cout<<"nie mozesz wplacic ujemnej kwoty\n";
	}
	else
	balance+=amt;
}

void AcctABC:: Withdraw(double amt)
{
	balance-=amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
	Formatting f;
	f.flag= 
	cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr=cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting &f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

void Brass::Withdraw(double amt)
{
	if(amt<0)
	{
		cout<<"nie mozna wplacic ujemnej kwoty\n";
	}
	else if(amt<=Balance())
	AcctABC::Withdraw(double amt);
	else
	cout<<"zadana wartosc  "<<amt
		<<" zl przekracza dostepne srodki"\n
}

void Brass::ViewAcct() const
{
	Formatting f= SetFormat();
	cout<<"wlasciciel "<<FullName()<<endl;
	cout<<" nr rachunku "<<AcctABC()<<endl;
	cout<<" stan konta "<<Balance()<<endl;
	Restore(f);
	
	
}

BrassPlus::BrassPlus(const string &s, long an, double bal,
					double mr, double r):AcctABC(s,an,bal)
{
	maxLoan=ml;
	owesBank=0;
	rate=r;
		
}


void BrassPlus::ViewAcct() const
{
	Formatting f= setFormat();
	cout<<"wlasciciel "<<FullName()<<endl;
	cout<<"nr rachunku "<<AcctABC()<<endl;
	cout<<"saldo "<<Balance()<<endl;
	cout<<"limit debetu "<<maxLoan<<" zl"<<endl;
	cout<<"kwota zadluzenia "<<owesBank<<endl;
	cout.precision(3);
	cout<<"stopa oprocentowania "<<100*rate<<"%\n";
	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f= SetFormat();
	
	double bal=Ballance();
	if (amt<=bal)
	AcctABC::Withdraw(amt);
	else if (amt<= bal +maxLoan-owesBank)
	{
		double advance =amt -bal;
		owesBank +=advance * (1.0+rate);
		cout<<"zadluzenie faktyczne "<<advance<<" zl\n";
		cout<<"odsetki "<<advance*rate<<" zl\n";
		Deposit(advance);
		AcctABC::Withdraw(amt);
		
	}
	else
	cout<<"przekroczony limit debetu";
	Restore(f);
}
