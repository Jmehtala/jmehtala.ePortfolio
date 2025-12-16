
#ifndef INVESTMENT_DISPLAY_H
#define INVESTMENT_DISPLAY_H

#include <vector>

class InvestmentDisplay {
public:
    static void displayChart(const std::vector<int>& years, const std::vector<double>& balances, const std::vector<double>& interests);
};

#endif //INVESTMENT_DISPLAY_H 
