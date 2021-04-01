/***************************************************************************
 * Name: Casey Cole
 * Email: coleca@email.sc.edu
 * Function: Account object header
 * 
 * Copyright (C) 2020 by Casey Cole                                        *
 *                                                                         *
 ***************************************************************************/
#include <iostream>
#include <string>
using namespace std;
/*
 * The following will define the member variables as well as the functions 
 * of the Account object. 
 * */
 
 
class Account {
	static int num_accounts;
	
	public:
		//Constructors
		//TODO: Default 
		Account(); //**Optional
		
		//TODO: Alternate Constructors
		Account(string, float);
		
		//TODO: Copy Constructors
		Account(const Account&);
		
		//TODO: Destructor
		//~Account(); 
		
		//Public Member Functions
		void print() const;
		string getName() const; 
		float getAmount() const;
		int getNumAccounts() const;
		
		//void operator-(int);
		
	private:	
		
		//Private Member Variables
		string name;
		float amount;
		//char *data; // = new char[10]

		//Private Member Functions
		void setName(string); 
		void setAmount(float);
};
