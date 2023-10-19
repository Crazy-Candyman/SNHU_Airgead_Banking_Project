/*
* September 30, 2023
* Gabriel Nina
* 
* CS-210 Programming Languages Project II Airgead Banking
* 
* The purpose of this program is to provide the user with a year by year
* summary of yearly interest earned and opening balance totaled w/ the 
* interest. The program reads in an inital deposit, monthly deposit, annual
* interest, and the number of years of the bank term. Calculations are performed
* and two tables are displayed with a summary of a bank balances per year. One
* without monthly deposits and another with the monthly deposits.
* 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Banking.h"
#include <ctype.h>

using namespace std;

// Declared functions
template <typename T>			// Allows function to take in int or double
void getInput(string, T&);		// Reads & validates input

// Driver
int main() {
	Banking NewCustomer;		// Banking class object declared
	char userInput = 'a';		// User input to quit or continue program
	int numOfYears = 0;			
	double
		initialDeposit = 0.0,
		monthlyDeposit = 0.0,
		annualInterest = 0.0;
	
	do {
		// Prompts for user input
		cout << setfill('*') << setw(30) << "" << endl;
		cout << setw(20) << " Data Input " << setw(10) << "" << endl;
		getInput("Initial Deposit: $", initialDeposit);
		getInput("Monthly Deposit: $", monthlyDeposit);
		getInput("Annual Interest: %", annualInterest);
		getInput("Number of Years:  ", numOfYears);

		// Press enter to continue
		cin.ignore();
		cout << "Press the enter key to continue....";
		cin.ignore(1000, '\n');
		cout << endl << endl;

		// Banking class object initialized
		NewCustomer.setOpeningBalance(initialDeposit);
		NewCustomer.setMonthlyDeposit(monthlyDeposit);
		NewCustomer.setInterestRate(annualInterest);
		NewCustomer.setYearsOfTerm(numOfYears);

		// Display balance table w/o monthly deposit
		NewCustomer.displayBalance();
		cout << endl;

		// Display balance table w/ monthly deposit
		NewCustomer.displayBalance(monthlyDeposit);
		cout << endl;

		// Prompt to quit or restart program
		userInput = 'a';
		while (tolower(userInput) != 'n' && tolower(userInput) != 'y') {
			cout << "Would you like to run another calculation ( y / n ): ";
			cin >> userInput;

			if (cin.peek() != '\n') {
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
				userInput = 'a';
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} // End while loop

		cout << endl;
	} while (tolower(userInput) != 'n'); // End do-while loop

	return 0;
} // End main

// Defined Functions
template <typename T>
void getInput(string subject, T& input) {
	bool inputValidated = false;		// bool value to break while loop

	do {
		cout << subject;
		cin >> input;

		// If input is a positive number with no letters.

		if (!isblank(cin.peek())) {
			if (!cin.fail() && input >= 0) {
				if (cin.peek() == '\n') {
					inputValidated = true;
				}
				else {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else {
				cout << "Invalid Input. Please enter numbers only." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} // End if-else 
		}
		else {
			cout << "Invalid Input. Please do not add spaces." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	} while (!inputValidated == true);	// while inputValidated is not equal to true
}