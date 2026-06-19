#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of items: "<<endl;
	cin>>n;
	
	int weight[n], profit[n];
	float ratio[n];
	int W;+
	
	cout<<"Enter weight of items: "<<endl;
	for(int i=0; i<n; i++){
		cin>>weight[i];
	}
	
	cout<<"Enter profit of items: "<<endl;
	for(int i=0; i<n; i++){
		cin>>profit[i];
	}
	
	cout<<"Enter the capacity of knapsack: "<<endl;
	cin>>W;
	
	for(int i=0; i<n; i++){
		ratio[i] = round(((float)profit[i] / weight[i]) * 100.0) / 100.0;
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(ratio[i] < ratio[j]){
				swap(ratio[i], ratio[j]);
				swap(weight[i], weight[j]);
				swap(profit[i], profit[j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<weight[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i=0; i<n; i++){
		cout<<profit[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i=0; i<n; i++){
		cout<<ratio[i]<<" ";
	}
	
	cout<<endl;
	int U = W;
	float x[n] = {0};
	float p = 0.0;
	
	for(int i=0; i<n; i++){
		if(weight[i]<=U){
			x[i] = 1;
			U = U - weight[i];
			p = p + profit[i];
		}
		else{
			x[i] = round(((float)U/weight[i])*100)/100;
			p = round((p + profit[i] * x[i])*100)/100;
			U = 0;
			break;
		}
	}
	
	cout<<endl;
	
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	
	cout<<endl;
	
	cout<<"Total profit: "<<p<<endl;
	
	return 0;
}
