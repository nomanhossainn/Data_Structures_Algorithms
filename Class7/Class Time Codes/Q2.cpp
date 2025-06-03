#include <stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum number of thieves required to empty the house
int maximumThieves(int n, int prices[], int weights[], int bagSize) {
    int dp[n + 1][bagSize + 1];

    // Build dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= bagSize; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(prices[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][bagSize];
}

int main() {
    int n;
    printf("Number of items: ");
    scanf("%d", &n);

    int prices[n], weights[n];
    printf("Prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    printf("Weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int bagSize;
    printf("Bag size: ");
    scanf("%d", &bagSize);

    int thieves = maximumThieves(n, prices, weights, bagSize);
    printf("Number of thieves required to empty the house: %d\n", thieves);

    return 0;
}
