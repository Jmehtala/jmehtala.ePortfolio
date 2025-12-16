#pragma once
#ifndef USERINPUT_H
#define USERINPUT_H

class UserInput {
private:
    double initial_investment;
    double monthly_deposit;
    double annual_interest_rate;
    int number_of_years;

public:
    UserInput();

    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterestRate() const;
    int getNumberOfYears() const;

    void getUserInput();


    void pauseProgram();

    void displayMenu();
};

#endif 