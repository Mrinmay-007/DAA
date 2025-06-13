#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

struct Item {
    float value, weight;
    float ratio;  // value/weight
};

// Sort items by decreasing value/weight ratio
void sortItems(Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take full item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of item
            totalValue += items[i].ratio * capacity;
            break; // knapsack is full
        }
    }

    return totalValue;
}

int main() {
    ifstream file("knapsack.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int n, capacity;
    file >> n >> capacity;

    Item items[MAX];
    for (int i = 0; i < n; i++) {
        file >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    file.close();

    float maxProfit = fractionalKnapsack(items, n, capacity);
    cout << "Maximum value in knapsack = " << maxProfit << endl;

    return 0;
}
