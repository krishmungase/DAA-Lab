#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(vector<int>& coins, int index, int amount, vector<vector<int>>& dp)
{
    if (amount == 0)
        return 0;

    if (index == 0) {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9;
    }

    if (dp[index][amount] != -1)
        return dp[index][amount];

    int notTake = findMinimumCoins(coins, index - 1, amount, dp);

    int take = 1e9;
    if (coins[index] <= amount)
        take = 1 + findMinimumCoins(coins, index, amount - coins[index], dp);

    dp[index][amount] = min(notTake, take);
    return dp[index][amount];
}

int coinChange(vector<int>& coins, int amount, vector<vector<int>>& dp)
{
    int n = coins.size();

    int result = findMinimumCoins(coins, n - 1, amount, dp);

    if (result >= 1e9)
        return -1;

    return result;
}

int main()
{
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cout << "Enter target amount: ";
    cin >> amount;

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int minimumCoins = coinChange(coins, amount, dp);

    if (minimumCoins == -1)
        cout << "\nAmount cannot be formed using given coins\n";
    else
        cout << "\nMinimum coins required = " << minimumCoins << endl;

    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    cout << "\nDP Table (rows = coin index, cols = amount)\n\n";

    cout << setw(5) << " ";
    for (int j = 0; j <= amount; j++)
        cout << setw(5) << j;

    cout << "\n------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << setw(3) << i << " |";
        for (int j = 0; j <= amount; j++) {

            if (dp[i][j] == -1)
                cout << setw(5) << ".";
            else if (dp[i][j] >= 1e9)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dp[i][j];
        }
        cout << endl;
    }

    return 0;
}