// # 0/1 Knapsack Problem using Memoization (Top-Down DP)
#include <bits/stdc++.h>
using namespace std;

int knapsack(int i, int W, vector<int>& value, vector<int>& weight, vector<vector<int>>& dp) {
    if (i == 0 || W == 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    int notTake = knapsack(i - 1, W, value, weight, dp);  // skip item i
    int take = 0;
    if (weight[i - 1] <= W)
        take = value[i - 1] + knapsack(i - 1, W - weight[i - 1], value, weight, dp);

    return dp[i][W] = max(take, notTake);
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