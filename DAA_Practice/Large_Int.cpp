#include <iostream>
#include <string>
using namespace std;

// Function for large integer multiplication
long long multiply(long long X, long long Y) {

    // Base Case
    if (X < 10 || Y < 10) {
        return X * Y;
    }

    // Find number of digits
    int n = max(to_string(X).length(), to_string(Y).length());

    int m = n / 2;

    long long power = 1;

    for (int i = 0; i < m; i++) {
        power *= 10;
    }

    // Split X into A and B
    long long A = X / power;
    long long B = X % power;

    // Split Y into C and D
    long long C = Y / power;
    long long D = Y % power;

    // Recursive calls
    long long P1 = multiply(A, C);
    long long P2 = multiply(B, D);
    long long P3 = multiply(A + B, C + D);

    // Combine results
    long long result =
        P1 * power * power +
        (P3 - P1 - P2) * power +
        P2;

    return result;
}

int main() {

    long long X, Y;

    cout << "Enter two numbers: ";
    cin >> X >> Y;

    cout << "Multiplication = " << multiply(X, Y);

    return 0;
}
