// Task 1: Code and analyze solutions to following problem with given strategies:
// i.  Knap Sack using greedy approach
// ii. Knap Sack using dynamic approach

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item{
    int profit;
    int weight;
    float pwRatio;

    Item(int profit, int weight): profit(profit), weight(weight) {
        this->pwRatio = (float)profit/weight;
    }
};

// Comparison function to sort items by value-to-weight ratio
bool cmp(struct Item a, struct Item b) {
    return a.pwRatio > b.pwRatio;
}

float knapSackGreedy(vector<Item> obj, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    sort(obj.begin(), obj.end(), cmp);

    float totalProfit = 0.0;
    int currentWeight = 0;

    for (auto item : obj) {
        if (currentWeight + item.weight <= capacity) {
            // If the item can fit entirely, take it
            currentWeight += item.weight;
            totalProfit += item.profit;
        } else {
            // Take the fraction of the remaining weight
            int remainingWeight = capacity - currentWeight;
            totalProfit += item.profit * ((double)remainingWeight / item.weight);
            break; // Knapsack is full
        }
    }
    return totalProfit;
}

int main(){
    int capacity = 20;
    vector<Item> obj = {
        {25, 18},
        {24, 15},
        {20, 10}
    };

    float maxProfit = knapSackGreedy(obj, capacity);
    cout<<"max profit in knap sack is : "<<maxProfit<<endl;

    return 0;
}