#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio_b = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio_b > ratio_a) ? 1 : -1;
}
void knapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(items[0]), compare);

    int current_weight = 0;
    double final_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            final_value += items[i].value;
        }
        else {
            int remaining_weight = capacity - current_weight;
            final_value += items[i].value * ((double)remaining_weight / items[i].weight);
            break;
        }
    }
    printf("Maximum value in the knapsack: %.2lf\n", final_value);
}

int main() {
    int capacity, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    knapsack(capacity, items, n);

    return 0;
}
