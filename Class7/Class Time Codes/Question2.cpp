#include <stdio.h>

// Structure to represent items
struct Item {
    int price;
    int weight;
};

// Function to calculate the maximum value that can be obtained
// with a bag of capacity W
int maximumThieves(int n, struct Item items[], int bagSize) {
    // Sort items based on their value per unit weight
    float pricePerWeight[n];
    for (int i = 0; i < n; i++) {
        pricePerWeight[i] = (float)items[i].price / items[i].weight;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (pricePerWeight[j] < pricePerWeight[j+1]) {
                float temp = pricePerWeight[j];
                pricePerWeight[j] = pricePerWeight[j+1];
                pricePerWeight[j+1] = temp;

                struct Item tempItem = items[j];
                items[j] = items[j+1];
                items[j+1] = tempItem;
            }
        }
    }

    int thieves = 0;
    int currentWeight = 0;

    // Fill the bag with items until it's full
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= bagSize) {
            currentWeight += items[i].weight;
            thieves++;
        } else {
            // If adding the whole item would exceed the bag's capacity,
            // add fraction of the item
            float fraction = (float)(bagSize - currentWeight) / items[i].weight;
            currentWeight += (int)(fraction * items[i].weight);
            thieves += (int)(fraction * 1); // 1 means one thief can carry the whole item
            break;
        }
    }

    return thieves;
}

int main() {
    int n;
    printf("Number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].price);
    }
    printf("Weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
    }

    int bagSize;
    printf("Bag size: ");
    scanf("%d", &bagSize);

    int thieves = maximumThieves(n, items, bagSize);
    printf("Number of thieves required to empty the house: %d\n", thieves);

    return 0;
}
