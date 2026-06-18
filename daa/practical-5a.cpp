// # Naive String Matching Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    vector<int> matches;
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
            matches.push_back(i);
    }

    if (matches.empty()) {
        cout << "\nPattern not found." << endl;
    } else {
        cout << "\nPattern found at index(es): ";
        for (int idx : matches)
            cout << idx << " ";
        cout << endl;
    }
    return 0;
}