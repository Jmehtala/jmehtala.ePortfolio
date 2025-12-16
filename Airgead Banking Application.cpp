#include <iostream>
#include <vector>
#include <string>

#include "UserInput.h"
#include "InvestmentCalculations.h"

using namespace std;

void displayReports(const vector<double>& year_end_balances_no_deposit, const vector<double>& year_end_interest_no_deposit,
    const vector<double>& year_end_balances_with_deposit, const vector<double>& year_end_interest_with_deposit) {
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Year  Year End Balance  Year End Earned Interest" << endl;
    for (size_t i = 0; i < year_end_balances_no_deposit.size(); ++i) {
        cout << i + 1 << "     $" << year_end_balances_no_deposit[i] << "               $" << year_end_interest_no_deposit[i] << endl;
    }

    cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Year  Year End Balance  Year End Earned Interest" << endl;
    for (size_t i = 0; i < year_end_balances_with_deposit.size(); ++i) {
        cout << i + 1 << "     $" << year_end_balances_with_deposit[i] << "               $" << year_end_interest_with_deposit[i] << endl;
    }
}

int main() {
    //Get user input
    UserInput userInput;
    userInput.getUserInput();

    //Calculate interest and generate reports
    InvestmentCalculations investment(userInput.getInitialInvestment(), userInput.getMonthlyDeposit(),
        userInput.getAnnualInterestRate(), userInput.getNumberOfYears());
    vector<double> year_end_balances_no_deposit = investment.calculateYearEndBalancesWithoutDeposits();
    vector<double> year_end_interest_no_deposit = investment.calculateYearEndInterestWithoutDeposits();
    vector<double> year_end_balances_with_deposit = investment.calculateYearEndBalancesWithDeposits();
    vector<double> year_end_interest_with_deposit = investment.calculateYearEndInterestWithDeposits();

    //Display the reports
    displayReports(year_end_balances_no_deposit, year_end_interest_no_deposit,
        year_end_balances_with_deposit, year_end_interest_with_deposit);

    return 0;
}
