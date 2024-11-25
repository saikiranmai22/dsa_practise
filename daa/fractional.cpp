#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fractionalKnapsack(double W, vector<pair<double, double>> &items) {
    sort(items.begin(), items.end(), [](pair<double, double> a, pair<double, double> b) {
        return (a.first / a.second) > (b.first / b.second);
    });

    double totalValue = 0.0; 

    for (auto &item : items) {
        double value = item.first;
        double weight = item.second;

        if (W >= weight) {
            cout<<value<<" "<<weight<<endl;
            totalValue += value;
            W -= weight;
        } else {
            cout<<value<<" "<<(W/weight)<<endl;
            totalValue += value * (W / weight);
            break; 
        }
    }
    // return totalValue;
    cout<<totalValue;
}

int main() {
    int n=3;
    double W=50;

    // cout << "Enter the number of items: ";
    // cin >> n;
    // cout << "Enter the capacity of the knapsack: ";
    // cin >> W;
    
    vector<pair<double, double>> items(n); // Each pair is (value, weight)
    // cout << "Enter the value and weight of each item:\n";
    // for (int i = 0; i < n; i++) {
    //     cin >> items[i].first >> items[i].second; // Value, Weight
    // }
    items[0].first= 60;
    items[0].second= 10;
    items[1].first= 120;
    items[1].second= 30;
    items[2].first= 100;
    items[2].second= 20;
    // double maxProfit = fractionalKnapsack(W, items);
    // cout << "Maximum profit: " << maxProfit << endl;

    fractionalKnapsack(W, items);

    return 0;
}