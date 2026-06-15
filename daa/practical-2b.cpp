// # Coin Change Problem Greedy Approach
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    sort(coins.rbegin(), coins.rend());

    cout << "Coin usage:\n";
    for (int i : coins) {
        if (amount >= i) {
            int count = amount / i;
            amount = amount % i;
            cout << i << " -> " << count << " coins\n";
        }
    }

    if (amount > 0)
        cout << "Remaining amount cannot be formed: " << amount << "\n";

    return 0;
}