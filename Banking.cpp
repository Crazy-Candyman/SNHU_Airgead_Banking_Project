#include "Banking.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Defined constructor
Banking::Banking() {
	m_yearsOfTerm = 0;
	m_initialDeposit = 0.0;
	m_monthlyDeposit = 0.0;
	m_interestRate = 0.0;
	m_interest = 0.0;
	m_openingBalance = 0.0;
	m_closingBalance = 0.0;
}

// Setters
void Banking::setOpeningBalance(double openingBalance) {
	this->m_openingBalance = openingBalance;
}

void Banking::setYearsOfTerm(int yearsOfTerm) {
	this->m_yearsOfTerm = yearsOfTerm;
}

void Banking::setMonthlyDeposit(double monthlyDeposit) {
	this->m_monthlyDeposit = monthlyDeposit;
}

void Banking::setInterestRate(double interestRate) {
	this->m_interestRate = interestRate;
}

// Getters
int Banking::getYearsOfTerm() {
	return m_yearsOfTerm;
}

double Banking::getOpeningBalance() {
	return m_openingBalance;
}

double Banking::getClosingBalance() {
	return m_closingBalance;
}

double Banking::getMonthlyDeposit() {
	return m_monthlyDeposit;
}

double Banking::getInterestRate() {
	return m_interestRate;
}

// Functions
void Banking::calcTotal() {
	// Loops 12 months
	for (int i = 0; i < 12; i++) {
		double total;
		double currentInterest;

		// Calculates interest earned, opening & closing balance
		total = m_openingBalance;
		currentInterest = total * ((m_interestRate / 100) / 12);
		m_closingBalance = currentInterest + total;
		m_openingBalance = m_closingBalance;
		m_interest += currentInterest;
	} // End loop
} // End function

void Banking::calcTotal(double t_monthlyDeposit) {
	// Loops 12 months
	for (int i = 0; i < 12; i++) {
		double total;
		double currentInterest;

		// Calculates interest earned, opening & closing balance
		total = m_openingBalance + t_monthlyDeposit;
		currentInterest = total * ((m_interestRate / 100) / 12);
		m_closingBalance = currentInterest + total;
		m_openingBalance = m_closingBalance;
		m_interest += currentInterest;
	} // End loop
} // End function

void Banking::displayBalance() {
	stringstream ss;				// String stream used to convert int to string
	string interestToString;		// Data holds interest as a string type
	string openingBalToString;		// Data holds opening balance as a string type

	// Display Header and title
	cout << setfill(' ');
	cout << setw(60) << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	cout << right << setfill(' ');
	cout << setw(6) << "Year";
	cout << setw(23) << "Year End Balance";
	cout << setw(31) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(64) << "" << endl;

	// Loops years of term
	for (int i = 1; i <= m_yearsOfTerm; i++) {

		m_interest = 0.0;	// Clears interest earned every loop
		ss.clear();			// Clears string stream buffer every loop
		
		calcTotal();		// Calculates balances for 1 year

		// String stream takes in "doubles" and outputs "strings"
		ss << fixed << setprecision(2) << m_openingBalance << " " << m_interest;
		ss >> openingBalToString >> interestToString;

		cout << setfill(' ');
		cout << setw(6) << i;								// Number of year in current loop
		cout << setw(23) << "$" + openingBalToString;		// Opening balance
		cout << setw(31) << "$" + interestToString << endl;	// Interest earned
	} // End loop
} // End function

void Banking::displayBalance(double m_monthlyDeposit) {
	stringstream ss;				// String stream used to convert int to string
	string interestToString;		// Data holds interest as a string type
	string openingBalToString;		// Data holds opening balance as a string type

	// Display Header and title
	cout << setfill(' ');
	cout << setw(58) << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	cout << right << setfill(' ');
	cout << setw(6) << "Year";
	cout << setw(23) << "Year End Balance";
	cout << setw(31) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(64) << "" << endl;

	// Loops years of term
	for (int i = 1; i <= m_yearsOfTerm; i++) {

		m_interest = 0.0;				// clears interest earned every loop
		ss.clear();						// Clears string stream buffer every loop

		calcTotal(m_monthlyDeposit);	// Calculates balances for 1 year

		// String stream takes in "doubles" and outputs "strings"
		ss << fixed << setprecision(2) << m_openingBalance << " " << m_interest;
		ss >> openingBalToString >> interestToString;

		// Output balance
		cout << setfill(' ');
		cout << setw(6) << i;								// Number of year in current loop
		cout << setw(23) << "$" + openingBalToString;		// Opening balance
		cout << setw(31) << "$" + interestToString << endl;	// Interest earned
	} // End loop
} // End function
