/***************************************************************************
 * Name: Casey Cole
 * Email: coleca@email.sc.edu
 * Function: Account object
 * 
 * Copyright (C) 2020 by Casey Cole                                        *
 *                                                                         *
 ***************************************************************************/


#include "Account.h"

int Account::num_accounts = 0;

//Default constructor
Account::Account() 
{
	//~ name = "Null"; 
	//~ amount = 1000;
	setName("Null"); 
	setAmount(1000);
	num_accounts++;
}

Account::Account(string _name, float _amount)
{
	//~ name = _name;
	//~ amount = _amount;
	setName(_name); 
	setAmount(_amount);
	num_accounts++;
}

Account::Account(const Account& _acct)
{
	setName(_acct.getName());
	setAmount(_acct.getAmount());
	
}

int Account::getNumAccounts() const
{
	return num_accounts;
}

string Account::getName() const
{
	return name;
} 

float Account::getAmount() const
{
	return amount;
}

void Account::setName(string _name)
{
	name = _name;
} 

void Account::setAmount(float _amount)
{
	if(_amount < 0) 
	{
		amount = 0;
	}
	else
	{
		amount = _amount;
	}
}
void Account::print() const
{
	cout << "Account holder name: " << name << endl; 
	cout << "Account balance: " << amount << endl;
}

//~ Account::~Account()
//~ {
	//~ delete [] data;
//~ } 




