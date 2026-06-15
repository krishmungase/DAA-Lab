// # KMP String Matching Algorithm
#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size(), m = pattern.size();
    if (m == 0 || m > n) return result;

    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return result;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> lps = buildLPS(pattern);
    cout << "\nLPS array: [ ";
    for (int v : lps) cout << v << " ";
    cout << "]\n";

    vector<int> matches = KMPSearch(text, pattern);
    if (matches.empty()) {
        cout << "\nPattern not found in text.\n";
    } else {
        cout << "\nPattern found at index(es): ";
        for (int idx : matches) cout << idx << " ";
        cout << "\n";
    }
    return 0;
}