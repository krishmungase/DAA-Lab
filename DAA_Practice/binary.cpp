#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void generateRandomData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(int arr[], int n, int key, int &comparisons) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        comparisons++;

        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int key, int &comparisons) {
    if (low > high)
        return -1;

    comparisons++;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return recursiveBinarySearch(arr, mid + 1, high, key, comparisons);
    else
        return recursiveBinarySearch(arr, low, mid - 1, key, comparisons);
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    
    generateRandomData(arr, n);
    
    cout << "\nRandomly Generated Array (Unsorted):\n";
    printArray(arr, n);
    
    int sortedArr[n];
    
    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }

    bubbleSort(sortedArr, n);

    cout << "\nSorted Array:\n";
    printArray(sortedArr, n);

    int key = arr[rand() % n];

    cout << "\nSearching for key: " << key << endl;

    int comparisons;
    int result;
    
    comparisons = 0;
    auto start = high_resolution_clock::now();
    result = binarySearch(sortedArr, n, key, comparisons);
    auto end = high_resolution_clock::now();

    cout << "\n\nBinary Search (Iterative)";
    cout << "\nIndex: " << result;
    cout << "\nComparisons: " << comparisons;
    cout << "\nTime (ns): "
         << duration_cast<nanoseconds>(end - start).count();
         
         
	comparisons = 0;
    start = high_resolution_clock::now();
    result = recursiveBinarySearch(sortedArr, 0, n - 1, key, comparisons);
    end = high_resolution_clock::now();

    cout << "\n\nBinary Search (Recursive)";
    cout << "\nIndex: " << result;
    cout << "\nComparisons: " << comparisons;
    cout << "\nTime (ns): "
         << duration_cast<nanoseconds>(end - start).count();
         
	return 0;
	
}
    
    












