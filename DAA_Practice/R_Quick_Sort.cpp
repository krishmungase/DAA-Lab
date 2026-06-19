#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(int arr[], int low, int high){
	int pivotIdx = low + rand() % (high - low + 1);
	swap(arr[pivotIdx], arr[high]);
	
	int pivot = arr[high];
	int i = low - 1;
	
	for(int j=low; j<high; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	
	swap(arr[i+1], arr[high]);
	return i+1;
}

void RandomQuickSort(int arr[], int low, int high){
	if(low >= high){
		return;
	}
	int pivot = partition(arr, low, high);
	RandomQuickSort(arr, low, pivot-1);
	RandomQuickSort(arr, pivot + 1, high);
}

int main(){
	srand(time(0));
	
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	
	int arr[n];
	cout<<"Enter array elements: "<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	cout<<endl;
	
	cout<<"Unsorted array: "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	
	RandomQuickSort(arr, 0, n-1);
	
	cout<<"Sorted array: "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
