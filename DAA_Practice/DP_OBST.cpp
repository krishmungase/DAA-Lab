#include<iostream>
#include<iomanip>
using namespace std;

int main() {

    int n;

    cout << "Enter number of keys : ";
    cin >> n;

    float p[20], q[20];
    float w[20][20], c[20][20];
    int r[20][20];

    cout << "Enter successful probabilities:\n";

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Enter unsuccessful probabilities:\n";

    for(int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    // Initialize diagonal
    for(int i = 0; i <= n; i++) {

        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    // Fill table diagonally
    for(int l = 1; l <= n; l++) {

        for(int i = 0; i <= n - l; i++) {

            int j = i + l;

            // Weight calculation
            w[i][j] = w[i][j-1] + p[j] + q[j];

            c[i][j] = 999999;

            // Try all roots
            for(int k = i + 1; k <= j; k++) {

                float cost = c[i][k-1] + c[k][j] + w[i][j];

                if(cost < c[i][j]) {

                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }

    // Weight Table
    cout << "\nWeight Table:\n";

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j <= n; j++) {

            if(j >= i)
                cout << fixed << setprecision(2)
                     << w[i][j] << "\t";
            else
                cout << "\t";
        }

        cout << endl;
    }

    // Cost Table
    cout << "\nCost Table:\n";

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j <= n; j++) {

            if(j >= i)
                cout << fixed << setprecision(2)
                     << c[i][j] << "\t";
            else
                cout << "\t";
        }

        cout << endl;
    }

    // Root Table
    cout << "\nRoot Table:\n";

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j <= n; j++) {

            if(j >= i)
                cout << r[i][j] << "\t";
            else
                cout << "\t";
        }

        cout << endl;
    }

    cout << "\nMinimum Cost : " << c[0][n] << endl;

    cout << "Root of Optimal BST : k" << r[0][n];

    return 0;
}
