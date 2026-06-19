#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print DP Table
void printTable(vector<vector<int>>& dp, int n, int W) {

    cout << "\nCurrent DP Table:\n\n";

    // Column headings
    cout << "    ";

    for (int w = 0; w <= W; w++)
        cout << w << " ";

    cout << endl;

    // DP Table
    for (int i = 0; i <= n; i++) {

        cout << i << " : ";

        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

// Function for 0/1 Knapsack using DP
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {

    // DP Table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP Table
    for (int i = 1; i <= n; i++) {

        for (int w = 0; w <= W; w++) {

            // If current item can fit
            if (wt[i - 1] <= w) {

                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );

            }
            else {

                dp[i][w] = dp[i - 1][w];
            }
        }

        cout << "\nAfter considering Item " << i
             << " (Value=" << val[i - 1]
             << ", Weight=" << wt[i - 1] << ")";

        printTable(dp, n, W);
    }

    // Backtracking to find selected items
    int w = W;

    cout << "\nSelected Items:\n";

    for (int i = n; i > 0 && w > 0; i--) {

        if (dp[i][w] != dp[i - 1][w]) {

            cout << "Item " << i
                 << " (Value=" << val[i - 1]
                 << ", Weight=" << wt[i - 1] << ")\n";

            w = w - wt[i - 1];
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values of items:\n";

    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter weights of items:\n";

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxProfit = knapsack(W, wt, val, n);

    cout << "\nMaximum Profit = " << maxProfit << endl;

    return 0;
}
