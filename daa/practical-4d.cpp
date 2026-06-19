#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << "Enter target amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    for (int c : coins)
        for (int a = c; a <= amount; a++)
            dp[a] = min(dp[a], 1 + dp[a - c]);

    if (dp[amount] >= 1e9)
        cout << "Amount cannot be formed using given coins" << endl;
    else
        cout << "Minimum coins required = " << dp[amount] << endl;
    return 0;
}