// # N-Queens Problem using Backtracking
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        int placedCol = board[i];
        if (placedCol == col) return false;
        if (abs(placedCol - col) == row - i) return false;
    }
    return true;
}

void printBoard(vector<int>& board, int n, int solutionNum) {
    cout << "Solution #" << solutionNum << ":\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cout << (board[r] == c ? "Q " : ". ");
        cout << "\n";
    }
    cout << "\n";
}

void solve(vector<int>& board, int n, int row, int& count) {
    if (row == n) {
        count++;
        printBoard(board, n, count);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solve(board, n, row + 1, count);
            board[row] = -1;
        }
    }
}

int main() {
    int n;
    cout << "Enter N (board size): ";
    cin >> n;

    vector<int> board(n, -1);
    int count = 0;

    cout << "\nAll solutions for " << n << "-Queens:\n\n";
    solve(board, n, 0, count);
    cout << "Total solutions: " << count << "\n";

    return 0;
}