#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an item
struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator for sorting by value-to-weight (descending)
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve Fractional Knapsack Problem
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp); // Sort by value/weight ratio

    double maxValue = 0.0;
    for (auto &item : items) {
        if (W == 0) break;

        // Take whole item if possible
        if (item.weight <= W) {
            maxValue += item.value;
            W -= item.weight;
        }
        // Otherwise, take fraction
        else {
            maxValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }
    return maxValue;
}

int main() {
    int W = 50; // Knapsack capacity
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Fractional Knapsack = " << maxValue << endl;
    return 0;
}
