#include <vector>
#include <cmath> 
#include <algorithm> 
#include "InvestmentCalculations.h"

InvestmentCalculations::InvestmentCalculations(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numberOfYears)
    : initial_investment(initialInvestment), monthly_deposit(monthlyDeposit), annual_interest_rate(annualInterestRate), number_of_years(numberOfYears) {
}


std::vector<double> InvestmentCalculations::calculateYearEndBalancesWithoutDeposits() {
    std::vector<double> yearEndBalances;
    double interestRateMonthly = annual_interest_rate / 100.0 / 12.0;


    double currentBalance = initial_investment;

    for (int year = 1; year <= number_of_years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            currentBalance += currentBalance * interestRateMonthly;
        }
        yearEndBalances.push_back(currentBalance);
    }

    return yearEndBalances;
}

std::vector<double> InvestmentCalculations::calculateYearEndInterestWithoutDeposits() {
    std::vector<double> yearEndInterests;
    double interestRateMonthly = annual_interest_rate / 100.0 / 12.0;

    double currentBalance = initial_investment;

    for (int year = 1; year <= number_of_years; ++year) {
        double totalInterest = 0.0; 
        for (int month = 1; month <= 12; ++month) {
            double interest = currentBalance * interestRateMonthly;
            totalInterest += interest;
            currentBalance += interest; 
        }
        yearEndInterests.push_back(totalInterest);
    }

    return yearEndInterests;
}

std::vector<double> InvestmentCalculations::calculateYearEndBalancesWithDeposits() {
    std::vector<double> yearEndBalances;
    double interestRateMonthly = annual_interest_rate / 100.0 / 12.0;

    double currentBalance = initial_investment;

    for (int year = 1; year <= number_of_years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            double interest = currentBalance * interestRateMonthly;
            currentBalance += monthly_deposit + interest; 
        }
        yearEndBalances.push_back(currentBalance);
    }

    return yearEndBalances;
}


std::vector<double> InvestmentCalculations::calculateYearEndInterestWithDeposits() {
    std::vector<double> yearEndInterests;
    double interestRateMonthly = annual_interest_rate / 100.0 / 12.0;

    double currentBalance = initial_investment;

    for (int year = 1; year <= number_of_years; ++year) {
        double totalInterest = 0.0; 
        for (int month = 1; month <= 12; ++month) {
            double interest = currentBalance * interestRateMonthly;
            totalInterest += interest;
            currentBalance += monthly_deposit + interest; 
        }
        yearEndInterests.push_back(totalInterest);
    }

    return yearEndInterests;
}

std::vector<MonthlyData> InvestmentCalculations::calculateMonthlyDetails() {
    std::vector<MonthlyData> details;
    double interestRateMonthly = annual_interest_rate / 100.0 / 12.0;
    double currentBalance = initial_investment;

    for (int year = 1; year <= number_of_years; ++year) {
        for (int month = 1; month <= 12; ++month) {

            double opening = currentBalance;

            // 1. Calculate Interest on Opening Balance
            double interest = opening * interestRateMonthly;

            // 2. Add Monthly Deposit
            currentBalance += monthly_deposit;

            // 3. Add Interest
            currentBalance += interest;

            MonthlyData data;
            data.year = year;
            data.month = month;
            data.openingBalance = opening;
            data.depositedAmount = monthly_deposit;
            data.interestEarned = interest;
            data.closingBalance = currentBalance;

            details.push_back(data);
        }
    }

    return details;
}
