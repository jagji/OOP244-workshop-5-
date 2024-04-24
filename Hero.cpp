/*/////////////////////////////////////////////////////////////////////////
						  Workshop - 5 (P2)
Full Name  : jagjit kaur 
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       : 22nd  February 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>

#include <iomanip>

#include "Hero.h"


#include "Power.h"

using namespace std;


namespace seneca{


 

        Hero::Hero() : powers(nullptr), numPowers(0), powerLevel(0) {
            m_heroName[0] = '\0';
        }

        Hero::Hero(const char* heroName, const Power* powers, int numPowers) {
            strcpy(m_heroName, heroName);

            this->powers = new Power[numPowers];

            for (int i = 0; i < numPowers; i++) {
                this->powers[i] = powers[i];
            }

            this->numPowers = numPowers;
            powerLevel = calculatePowerLevel();
        }

        Hero::~Hero() {
            delete[] powers;
            powers = nullptr;
        }

        int Hero::calculatePowerLevel() {
            int totalRarity = 0;

            for (int i = 0; i < numPowers; i++) {
                totalRarity += powers[i].checkRarity();
            }

            return totalRarity * numPowers;
        }

        std::ostream& Hero::display() const {
            std::cout << "Hero Name: " << m_heroName << std::endl;

            // Assuming displayPowerDetails is a separate function or method

            // displayPowerDetails(powers, numPowers);

            std::cout << "Power Level: " << powerLevel << std::endl;

            return std::cout;
        }

        int Hero::getPowerLevel() const {
            return powerLevel;
        }

        Hero& Hero::operator+=(const Power& newPower) {
            Power* updatedPowers = new Power[numPowers + 1];

            for (int i = 0; i < numPowers; i++) {
                updatedPowers[i] = powers[i];
            }

            updatedPowers[numPowers++] = newPower;

            delete[] powers;
            powers = updatedPowers;

            powerLevel = calculatePowerLevel();

            return *this;
        }

        Hero& Hero::operator-=(int decreaseAmount) {
            powerLevel -= decreaseAmount;

            return *this;
        }

        bool Hero::operator<(const Hero& otherHero) {
            return powerLevel < otherHero.getPowerLevel();
        }

        bool Hero::operator>(const Hero& otherHero) {
            return powerLevel > otherHero.getPowerLevel();
        }

    }
