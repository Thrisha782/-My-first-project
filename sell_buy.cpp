#include<iostream>
#include<climits>
using namespace std;

int main() {
        //initializing variables 
    int number_of_days;
    int stock_prices[100];
//getting inputs 
    cout << "Enter the number of days: ";
    cin >> number_of_days;

    cout << "Enter the stock prices for each day: ";
    for (int day_index = 0; day_index < number_of_days; day_index++) {
        cin >> stock_prices[day_index];
    }

    int minimum_price_so_far = INT_MAX; // assigning to the maximum value 
    int maximum_profit = 0;

    for (int day_index = 0; day_index < number_of_days; day_index++) { //traversing the prices array
        minimum_price_so_far = min(minimum_price_so_far, stock_prices[day_index]); 

        int current_profit = stock_prices[day_index] - minimum_price_so_far;
        maximum_profit = max(maximum_profit, current_profit);
    }

    cout<< "The maximum profit is: " << maximum_profit;

    return 0;
}
