// Practical 1b: Finding Minimum and Maximum in an Array
#include <bits/stdc++.h>
using namespace std;

/* ---------- SIMPLE METHOD ---------- */
void simpleMinMax(vector<int>& arr, int &mini, int &maxi, int &cnt) {
    mini = maxi = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        cnt++;
        if (arr[i] > maxi) maxi = arr[i];
        cnt++;
        if (arr[i] < mini) mini = arr[i];
    }
}

/* ---------- DIVIDE & CONQUER METHOD ---------- */
void divideConquerMinMax(vector<int>& arr, int low, int high, int &mini, int &maxi, int &cnt) {
    if (low == high) {
        mini = maxi = arr[low];
        return;
    }
    if (high == low + 1) {
        cnt++;
        if (arr[low] < arr[high]) { mini = arr[low]; maxi = arr[high]; }
        else { mini = arr[high]; maxi = arr[low]; }
        return;
    }
    int mid = (low + high) / 2;
    int min1, max1, min2, max2;
    divideConquerMinMax(arr, low, mid, min1, max1, cnt);
    divideConquerMinMax(arr, mid + 1, high, min2, max2, cnt);
    cnt++;
    mini = min(min1, min2);
    cnt++;
    maxi = max(max1, max2);
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    int sMin, sMax, dMin, dMax, cnt1 = 0, cnt2 = 0;

    simpleMinMax(arr, sMin, sMax, cnt1);
    divideConquerMinMax(arr, 0, n - 1, dMin, dMax, cnt2);

    cout << "\nSimple Method:\n";
    cout << "Min = " << sMin << ", Max = " << sMax << "\n";
    cout << "Comparisons = " << cnt1 << "\n";

    cout << "\nDivide & Conquer Method:\n";
    cout << "Min = " << dMin << ", Max = " << dMax << "\n";
    cout << "Comparisons = " << cnt2 << "\n";

    return 0;
}