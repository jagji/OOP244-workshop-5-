/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/*/////////////////////////////////////////////////////////////////////////
						  Workshop - 3 (P2)
Full Name  : jagjit kaur
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       : 18 February 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"

#include <iostream>

#include <cstring>

#include <cstdio>

#include <cmath>



using namespace std;



namespace seneca


{
	// Default Constructor with default arguments


	bankAccount::bankAccount(const char *name, bool checking)



		// Initialize m_userName to an empty string 

	{
		m_userName[0] = '\0'; // Empty string implies that  account is not open
		


		// Call setup function to initialize bank account 


		
		setup(name, checking);


	}



	// Open bank account: setup can only be done once!


	bool bankAccount::setup(const char *name, bool checking)


	{
		if (isOpen())


			return false;


		if 
			
			(name == nullptr)


			return false;



		strcpy(m_userName, name);


		m_monthlyTransactions = 0;


		m_checking = checking;


		m_funds = 0;


		return true;


	}

	// Account is open if user name string is not empty


	bool bankAccount::isOpen() const

	{

		return (m_userName[0] != '\0');

	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

	const double CHECKING_FEE = 1.25;


	const double SAVINGS_FEE = 3.50;


	const double CHECKING_INTEREST = 0.005;


	const double SAVINGS_INTEREST = 0.025;

	// Cast Operators


	bankAccount::operator bool() const


	{

		return isOpen();

	}

	bankAccount::operator double() const

	{
		return m_funds;
	}

	// Unary Operators

	bankAccount &bankAccount::operator++()

	{
		if 
			(isOpen() && m_funds > 0)
		{


			double interest = m_checking ? m_funds * CHECKING_INTEREST : m_funds * SAVINGS_INTEREST;

			m_funds += interest;

		}

		return *this;

	}


	bankAccount &bankAccount::operator--()


	{
		if 
			(isOpen())
		{
			double fee = m_checking ? m_monthlyTransactions * CHECKING_FEE : m_monthlyTransactions * SAVINGS_FEE;

			m_funds -= fee;

		}

		return *this;

	}

	// Binary Operators

	bool bankAccount::operator+=(double value)

	{
		if 
			(isOpen())
		{
			m_funds += value;

			m_monthlyTransactions++;

			char valueStr[20];

			sprintf(valueStr, "%.2f", value);


			string output = "Deposit $" + std::string(valueStr) + " for " + m_userName;

			
			cout << output << std::endl;
			
			return true;
		}
		
		return false;
	}

	bool bankAccount::operator-=(double value)

	{
		
		m_funds -= value;
		
		m_monthlyTransactions++;
		
		char valueStr[20];
		
		sprintf(valueStr, "%.2f", value);

		
		string output = "Withdraw $" + std::string(valueStr) + " for " + m_userName;

		
		cout << output << std::endl;
		
		
		return true;


		// return *this += -value;


	}



	//Account is open if user name string is not empty 



	bool bankAccount::operator==(const bankAccount &other) const


	{
		
		
		return isOpen() && other.isOpen() && strcmp(m_userName, other.m_userName) == 0 && fabs(m_funds - other.m_funds) < 0.001 && m_checking == other.m_checking;
	}


	bool bankAccount::operator>(double value) const
	{
		
		
		return isOpen() && m_funds > value;
	}

	bool bankAccount::operator<=(double value) const
	{
	
		
		return !(*this > value);
	}

	// Additional Methods


	bool bankAccount::operator<<(bankAccount &other)


	{
		if 
			
			
			(isOpen() && other.isOpen() && other.m_funds > 0)


		{
			
			
			double transferAmount = other.m_funds;
			
			
			char transferAmountStr[20];
			
			
			sprintf(transferAmountStr, "%.2f", transferAmount);

			string output = "Transfer $" + std::string(transferAmountStr) + " from " + other.m_userName + " to " + m_userName;

			
			
			cout << output << std::endl;

			
			
			*this += other.m_funds;
			
			
			other -= other.m_funds;
			
			
			return true;
		}
		
		
		return false;
	}

	void bankAccount::display() const


	{
		if
			(isOpen())
		{
			int maxNameLength = 15;	
			
			// Adjust this value to the maximum user name length


			
			
			int numHyphens = maxNameLength - std::strlen(m_userName) + 1; // Add 1 for an extra hyphen
			
			
			std::string hyphens(numHyphens, '-');

			
			
			char balance[20];
			
			
			
			std::sprintf(balance, "%8.2f", m_funds);

			
			
			char transactions[4];
			
			
			std::sprintf(transactions, "%03d", m_monthlyTransactions);

			std::string output = "Display Account -> User:" + hyphens + m_userName + " | " + (m_checking ? "Checking" : " Savings") + " | Balance: $" + std::string(balance) + " | Transactions:" + std::string(transactions);



			
			
			std::cout << output << std::endl;
		}


		else

		{


			
			
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}
	}


	// ADD: Global Helper Function


	
	bool operator>(double lhs, const bankAccount &rhs)
	{
		
		return rhs.isOpen() && lhs > (double)rhs;
	}

	
	bool operator<=(double lhs, const bankAccount &rhs)
	{
		
		return !operator>(lhs, rhs);
	}
}
