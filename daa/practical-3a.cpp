// # Coin Change Problem Dynamic Programming Approach
#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int coin : coins)
            if (coin <= i)
                dp[i] = min(dp[i], 1 + dp[i - coin]);

    return dp[amount] >= 1e9 ? -1 : dp[amount];
}

int main() {
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

    int minimumCoins = coinChange(coins, amount);
    if (minimumCoins == -1)
        cout << "Amount cannot be formed using given coins" << endl;
    else
        cout << "Minimum coins required = " << minimumCoins << endl;

    return 0;
}