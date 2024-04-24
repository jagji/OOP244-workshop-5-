/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
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





#pragma once


#ifndef SENECA_BANKACCOUNT_H_


#define SENECA_BANKACCOUNT_H_





namespace seneca


{
   const int	 ACCT_MAXLEN_USER = 16;					// Max Length of user name

  
   // Class Definition
  
   
   class bankAccount
   {

  
   
   private:
      
       
       // Data Members
     
       
       char	m_userName[ACCT_MAXLEN_USER];
     
       
       double	m_funds;
     
       
       bool	m_checking;
      
       
       int		m_monthlyTransactions;

      
  
   
   public:
     
       
       bankAccount(const char* name = nullptr, bool checking = false);
     
       
       
       bool isOpen() const;
      
       
       bool setup(const char* name, bool checking);

      
       
       // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
      
       
       // Type Conversion Operators
     
       
       operator bool() const;
      
       
       operator double() const;

      
       
       // Unary Operators
      
       
       bankAccount& operator++();
     
       
       bankAccount& operator--();

      // Binary Operators
     
       
       bool operator+= (double value);
      
       
       bool operator-= (double value);
      
       
       bool operator== (const bankAccount& other) const;
      
       
       bool operator> (double value) const;
     
       
       bool operator<= (double value) const;

      // Additional Methods
     
       
       bool operator<<(bankAccount& other);
      
       
       void display() const;
   };

   // ADD: Global helpers
   
   
   bool operator> (double lhs, const bankAccount& rhs);
  
   
   
   bool operator<= (double lhs, const bankAccount& rhs);
}


#endif

