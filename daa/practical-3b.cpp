#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of keys: ";
    cin >> n;
    vector<double> p(n + 1), q(n + 1);
    cout << "Enter p1 to pn:\n";
    for (int i = 1; i <= n; i++) cin >> p[i];
    cout << "Enter q0 to qn:\n";
    for (int i = 0; i <= n; i++) cin >> q[i];

    double e[20][20] = {}, w[20][20] = {};
    int root[20][20] = {};

    for (int i = 1; i <= n + 1; i++)
        e[i][i-1] = w[i][i-1] = q[i-1];

    for (int l = 1; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double cost = e[i][r-1] + e[r+1][j] + w[i][j];
                if (cost < e[i][j]) { e[i][j] = cost; root[i][j] = r; }
            }
        }

    cout << "\nMinimum Cost: " << e[1][n] << "\nRoot Table:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (i <= j ? root[i][j] : 0) << " ";
        cout << endl;
    }
    return 0;
}