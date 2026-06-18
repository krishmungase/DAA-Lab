// # Fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<pair<int,int>> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second;

    sort(items.begin(), items.end(), [&](pair<int,int> a, pair<int,int> b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    
    double totalValue = 0.0;
    for (auto &item : items) {
        int value = item.first, weight = item.second;
        if (W >= weight) {
            W -= weight;
            totalValue += value;
        } else {
            totalValue += (double)value * W / weight;
            break;
        }
    }
    cout << "Maximum value in knapsack = " << totalValue << endl;
    return 0;
}