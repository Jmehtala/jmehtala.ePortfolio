
#include "InvestmentCharts.h"
#include <iostream>

void InvestmentDisplay::displayChart(const std::vector<int>& years, const std::vector<double>& balances, const std::vector<double>& interests) {
    std::cout << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Year\tYear End Balance\tYear End Earned Interest" << std::endl;
    for (size_t i = 0; i < years.size(); ++i) {
        std::cout << years[i] << "\t$" << balances[i] << "\t\t$" << interests[i] << std::endl;
    }
}
