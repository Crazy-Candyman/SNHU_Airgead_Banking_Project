#pragma once
#include <iostream>

class Banking {

private:
	int m_yearsOfTerm;
	double
		m_initialDeposit,
		m_monthlyDeposit,
		m_interestRate,
		m_interest,
		m_openingBalance,
		m_closingBalance;

	// Overloaded functions
	void calcTotal();				// Calculates balances
	void calcTotal(double);			// Calculates balances

public:
	// Constructor
	Banking();

	// Setters
	void setOpeningBalance(double);
	void setYearsOfTerm(int);
	void setMonthlyDeposit(double);
	void setInterestRate(double);

	// Getters
	int getYearsOfTerm();
	double getMonthlyDeposit();
	double getInterestRate();
	double getOpeningBalance();
	double getClosingBalance();

	// Overloaded functions
	void displayBalance();			// Display balance w/o monthly deposit
	void displayBalance(double);	// Display balance w/ monthly deposit
};

