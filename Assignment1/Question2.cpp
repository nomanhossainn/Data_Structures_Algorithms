#include<iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxThieves(int prices[], int weights[], int n, int bagSize) {
    int dp[n + 1][bagSize + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= bagSize; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(1 + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][bagSize];
}

int main() {
    int n;
    cout << "Number of items: ";
    cin >> n;

    int prices[n], weights[n];
    cout << "Prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << "Weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int bagSize;
    cout << "Bag size: ";
    cin >> bagSize;

    int maxItems = maxThieves(prices, weights, n, bagSize);
    cout << "Number of thieves required: " << maxItems << endl;

    return 0;
}
