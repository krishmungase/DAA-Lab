#include <iostream>
#include <climits>
using namespace std;

int main() {

    int n, V;

    cout << "Enter number of coins: ";
    cin >> n;

    int coin[n + 1];

    for(int i = 1; i <= n; i++) {

        cout << "Coin " << i << ": ";
        cin >> coin[i];
    } 

    cout << "Enter amount: ";
    cin >> V;

    int dp[n + 1][V + 1];

    // Initialization

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for(int j = 1; j <= V; j++) {
        dp[0][j] = INT_MAX - 1;
    }

    // Fill DP Table

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= V; j++) {

            if(coin[i] <= j) {

                int include = dp[i][j - coin[i]] + 1;

                int exclude = dp[i - 1][j];

                dp[i][j] = min(include, exclude);
            }

            else {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print DP Table

    cout << "\nDP Table:\n\n";

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j <= V; j++) {

            if(dp[i][j] == INT_MAX - 1)
                cout << "0 ";
            else
                cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    // Final Answer

    if(dp[n][V] == INT_MAX - 1) {

        cout << "\nNo solution possible.\n";
        return 0;
    }

    cout << "\nMinimum Coins Required: "
         << dp[n][V] << endl;

    // Print Coins Used

    cout << "\nCoins Used:\n";

    int i = n;
    int j = V;

    while(j > 0 && i > 0) {

        if(dp[i][j] == dp[i - 1][j]) {

            i--;

        } else {

            cout << coin[i] << " ";

            j = j - coin[i];
        }
    }

    return 0;
}
