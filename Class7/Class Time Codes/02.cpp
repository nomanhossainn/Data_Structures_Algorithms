#include<iostream>
using namespace std;

// int P[] = {200, 150, 100, 50, 300}; // Array of profits
// int W[] = {3, 2, 1, 2, 5}; 
int P[] = {12,10,20,15};
int W[] = {2,1,3,2};          // Array of weights

// Recursive function to solve the 0/1 knapsack problem
int knapsack01(int C, int i) {
    // Base case: if capacity or item index becomes 0, return 0
    if (C == 0 || i == 0) {
        return 0;
    }
    
    // Adjust index to access arrays correctly
    i--;

    // Calculate the value if the current item is not included
    int value1 = 0 + knapsack01(C, i);
    
    // Calculate the value if the current item is included
    int value2 = 0;
    if (C >= W[i]) {
        value2 = P[i] + knapsack01(C - W[i], i);
    }
    
    // Choose the maximum value between including and excluding the current item
    return max(value1, value2);
}

int main() {
    // Calculate the total profit for the given capacity and number of items
    int totalProfit = knapsack01(5, 4);
    
    // Output the total profit
    cout << "Total profit: " << totalProfit << endl;
    
    return 0;
}
