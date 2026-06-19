#include<iostream>
using namespace std;

int main(){
	int n; 
	cout<<"Enter number coin denominations: ";
	cin>>n;
	
	int denominations[n];
	int amount;
	
	cout<<"Enter coin denominations: "<<endl;
	for(int i=0; i<n; i++){
		cin>>denominations[i];
	}
	
	cout<<"Enter the amount: ";
	cin>>amount;
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(denominations[i] < denominations[j]){
				swap(denominations[i], denominations[j]);
			}
		}
	}
	
	int A = amount;
	int coins = 0;
	
	for(int i=0; i<n; i++){
		if(A >= denominations[i]){
			int count = A / denominations[i];
			coins += count;
			cout<<"denominations of "<<i<<" "<<count;
			A = A % denominations[i];
		}
	}
	
	cout<<coins<<endl;
	
	return 0;
}
