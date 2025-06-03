#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min_thieves(int bag_size, int weights[], int n) {
    int i, w;
    int K[bag_size + 1];

    K[0] = 0;

    for (w = 1; w <= bag_size; w++)
        K[w] = bag_size + 1;

    for (i = 0; i < n; i++) {
        for (w = weights[i]; w <= bag_size; w++) {
            K[w] = min(K[w], 1 + K[w - weights[i]]);
        }
    }

    return K[bag_size];
}

int main() {
    int n, bag_size;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int prices[n], weights[n];

    printf("Enter the prices of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &prices[i]);

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter the bag size: ");
    scanf("%d", &bag_size);

    printf("Number of thieves required: %d\n", min_thieves(bag_size, weights, n));

    return 0;
}
