#pragma once
#ifndef INVESTMENT_CALCULATIONS_H
#define INVESTMENT_CALCULATIONS_H

#include <vector>

struct MonthlyData {
    int year;
    int month;
    double openingBalance;
    double depositedAmount;
    double interestEarned;
    double closingBalance;
};

class InvestmentCalculations {
private:
    double initial_investment;
    double monthly_deposit;
    double annual_interest_rate;
    int number_of_years;

public:
    InvestmentCalculations(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numberOfYears);

    std::vector<double> calculateYearEndBalancesWithoutDeposits();
    std::vector<double> calculateYearEndInterestWithoutDeposits();
    std::vector<double> calculateYearEndBalancesWithDeposits();
    std::vector<double> calculateYearEndInterestWithDeposits();
    std::vector<MonthlyData> calculateMonthlyDetails();
};

#endif 