// # Searching Algorithms: Linear Search, Binary Search, Recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target) return i;
    return -1;
}

int binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int recursiveBinarySearch(vector<int>& arr, int target, int l, int r) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return recursiveBinarySearch(arr, target, l, mid - 1);
    else return recursiveBinarySearch(arr, target, mid + 1, r);
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "\nLinear Search Index: " << linearSearch(arr, target) << "\n";

    sort(arr.begin(), arr.end());

    cout << "Binary Search Index: " << binarySearch(arr, target) << "\n";
    cout << "Recursive Binary Search Index: " << recursiveBinarySearch(arr, target, 0, n - 1) << "\n";

    return 0;
}