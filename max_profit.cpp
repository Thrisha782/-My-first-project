#include<iostream>
using namespace std;

int main() {
    int number_of_days, stock_prices[100];

    // Asking the user for the number of days
    cout << "Enter the number of days: ";
    cin >> number_of_days;

    // Getting the stock prices for each day
    cout << "Enter the prices for each day: ";
    for (int day_index = 0; day_index < number_of_days; day_index++) {
        cin >> stock_prices[day_index];
    }

    int total_profit = 0;

    // Calculating profit by checking if today's price is higher than yesterday's
    // If yes, we "buy yesterday and sell today" to gain the difference
    for (int day_index = 1; day_index < number_of_days; day_index++) {
        if (stock_prices[day_index] > stock_prices[day_index - 1]) {
            total_profit += stock_prices[day_index] - stock_prices[day_index - 1];
        }
    }

    // Output the total profit
    cout << "Maximum profit: " << total_profit;
    return 0;
}
