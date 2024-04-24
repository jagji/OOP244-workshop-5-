/*/////////////////////////////////////////////////////////////////////////
Workshop - 5 (P2)
Full Name  : jagjit kaur
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       : 22 nd  February 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


#include<iostream>

#include <cstring>

#include "Power.h"

using namespace std;


namespace seneca {

	// Default constructor for Power class
	Power::Power() {
		setEmpty();
	}

	// Parameterized constructor for Power class
	Power::Power(const char* name, int rarity) {
		createPower(name, rarity);
	}

	// Set Power object to an empty state
	void Power::setEmpty() 
	{
		m_name[0] = '\0';

		m_rarity = 0;
	}

	// Create a Power object with given name and rarity
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0)
		{
			strncpy(m_name, name, MAX_NAME_LENGTH);

			m_rarity = rarity;
		}
		else {
			setEmpty();

		}
	}

	// Get the name of the power
	const char* Power::checkName() const 
	{
		return m_name;
	}

	// Get the rarity of the power
	int Power::checkRarity() const 
	{
		return m_rarity;
	}

	// Check if the Power object is in an empty state
	bool Power::isEmpty() const
	{
		return (m_name[0] == '\0' || m_rarity == 0);

	}

	// Display details of powers in an array
	void displayDetails(Power* powers, int size) 
	{
		cout << "List of available powers: " << endl;

		for (int i = 0; i < size; i++)
		{
			if (!powers[i].isEmpty()) 
			{
				cout << "  Name: " << powers[i].checkName() << ", "

					<< "Rarity: " << powers[i].checkRarity() << endl;

			}
			else if (powers[i].isEmpty())
			{
				cout << "  Empty Power Slot" << endl;
			}
		}
	}
