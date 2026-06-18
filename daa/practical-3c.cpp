// # 0/1 Knapsack Problem using Memoization (Top-Down DP)
#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int>& value, vector<int>& weight, vector<vector<int>>& dp) {
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];

    int notTake = knapsack(n - 1, W, value, weight, dp);  // skip item n    
    int take = 0;
    if (weight[n - 1] <= W)
        take = value[n - 1] + knapsack(n - 1, W - weight[n - 1], value, weight, dp);

    return dp[n][W] = max(take, notTake);
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> value(n), weight(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i] >> weight[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << "\nMaximum value in knapsack = " << knapsack(n, W, value, weight, dp) << endl;

    return 0;
}