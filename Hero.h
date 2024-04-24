/*/////////////////////////////////////////////////////////////////////////
Workshop - 5 (P2)
Full Name  : jagjit kaur
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       : 22nd February 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"
#include <iostream>
#include <ostream>

namespace seneca {

	// Class representing a Hero
	class Hero {
	private:
		char m_heroName[MAX_NAME_LENGTH + 1]{}; // Name of the hero
		Power* powers; // Array of powers possessed by the hero
		int numPower = 0; // Number of powers
		int powerLevel = 0; // Power level of the hero

	public:
		// Default constructor
		Hero();

		// Parameterized constructor
		Hero(const char* heroName, const Power* powers, int numPower);

		// Destructor
		~Hero();

		// Calculate the power level of the hero
		int calculatedPowerLevel();

		// Read the power level of the hero
		int readPL() const;

		// Display information about the hero
		std::ostream& display() const;

		// Overloaded addition assignment operator to add a new power to the hero
		Hero& operator+= (const Power& inputPower);

		// Overloaded subtraction assignment operator to decrease the power level
		Hero& operator-= (int decreaseAmount);

		// Overloaded less than comparison operator to compare power levels with another hero
		bool operator< (const Hero& second);

		// Overloaded greater than comparison operator to compare power levels with another hero
		bool operator> (const Hero& second);

		// Overloaded left shift operator to add a Power to a Hero and return the updated object 
		Hero& operator<< (const Power& right);
	};

	// Overloaded right shift operator to add a Power to a Hero and return the added power 
	const Power& operator>> (const Power& left, Hero& right);
}

#endif 
