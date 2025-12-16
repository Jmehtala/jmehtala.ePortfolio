#include <iostream>
#include <limits> // Used for numeric_limits
#include <string> // Used for string prompts
#include "UserInput.h"

using namespace std;

// --- Private Helper Templates ---

// Template function to handle input validation for double type
void getValidDoubleInput(double& value, const string& prompt, const string& error_msg, bool mustBePositive) {
    bool valid_input = false;
    while (!valid_input) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Error: Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (mustBePositive && value <= 0.0) {
            cout << error_msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            valid_input = true;
        }
    }
}

// Template function to handle input validation for integer type
void getValidIntInput(int& value, const string& prompt, const string& error_msg, bool mustBePositive) {
    bool valid_input = false;
    while (!valid_input) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Error: Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (mustBePositive && value <= 0) {
            cout << error_msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            valid_input = true;
        }
    }
}


// --- Class Implementation ---

UserInput::UserInput() {
    // You can initialize members in the initializer list for better style
    // initial_investment(0.0), monthly_deposit(0.0), ... {}
    initial_investment = 0.0;
    monthly_deposit = 0.0;
    annual_interest_rate = 0.0;
    number_of_years = 0;
}

double UserInput::getInitialInvestment() const {
    return initial_investment;
}

double UserInput::getMonthlyDeposit() const {
    return monthly_deposit;
}

double UserInput::getAnnualInterestRate() const {
    return annual_interest_rate;
}

int UserInput::getNumberOfYears() const {
    return number_of_years;
}

void UserInput::getUserInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n------------------------------------" << endl;
    cout << "          Investment Data" << endl;
    cout << "------------------------------------" << endl;

    getValidDoubleInput(initial_investment,
        "Enter Initial Investment Amount: $",
        "Error: Initial investment must be a positive number.",
        true); // Must be positive

    getValidDoubleInput(monthly_deposit,
        "Enter Monthly Deposit: $",
        "Error: Monthly deposit must be non-negative.",
        false); // Can be zero (no monthly deposit)

    getValidDoubleInput(annual_interest_rate,
        "Enter Annual Interest Rate (%): ",
        "Error: Annual interest rate must be non-negative.",
        false); // Can be zero

    getValidIntInput(number_of_years,
        "Enter Number of Years: ",
        "Error: Number of years must be a positive integer.",
        true); // Must be positive
}

void UserInput::pauseProgram() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n\nPress Enter to continue...";
    cin.get();

// Clear Console Screen 
#ifdef _WIN32
    system("cls");
#else
    // For Unix-like systems (Linux, macOS)
    system("clear");
#endif
}