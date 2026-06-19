#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter number of jobs: ";
	cin>>n;
	
	int id[n], profit[n], deadline[n];
	
	cout<<"Enter the id, profit and deadline of jobs: "<<endl;
	for(int i=0; i<n; i++){
		cin>>id[i]>>profit[i]>>deadline[i];
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(profit[i] < profit[j]){
				swap(profit[i], profit[j]);
				swap(deadline[i], deadline[j]);
				swap(id[i], id[j]);
			}
		}
	}
	int maxDeadline = 0;
	for(int i=0; i<n; i++){
		maxDeadline = max(maxDeadline, deadline[i]);
	}
	
	int slot[maxDeadline];
	for(int i=0; i<maxDeadline; i++){
		slot[i] = -1;
	}
	int totalProfit = 0;
	
	for(int i=0; i<n; i++){
		for(int j = deadline[i]; j>0; j--){
			if(slot[j] == -1){
				slot[j] = id[i];
				totalProfit += profit[i];
			}
		}
	}
	
	for(int i=0; i<maxDeadline; i++){
		cout<<slot[i]<<" ";
	}
	
	return 0;
	
}
