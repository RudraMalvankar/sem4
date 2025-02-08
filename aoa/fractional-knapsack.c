#include <stdio.h>

// Structure to store weight, value, and value-to-weight ratio
typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

// Function to sort items in decreasing order of value/weight ratio
void sortItems(Item items[], int n) {
    int i, j;
    Item temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Function to calculate the maximum profit using the Fractional Knapsack approach
float fractionalKnapsack(Item items[], int n, int capacity) {
    float totalValue = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity;
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity, i;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    Item items[n];

    printf("Enter weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;  // Calculate value-to-weight ratio
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items by decreasing value-to-weight ratio
    sortItems(items, n);

    // Compute maximum profit
    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum Profit: %.2f\n", maxProfit);

    return 0;
}

/* ANSWER
Enter number of items: 3
Enter weight and value of each item:
10 60
20 100
30 120
Enter capacity of knapsack: 50
Maximum Profit: 240.00

*/