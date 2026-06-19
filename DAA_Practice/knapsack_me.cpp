#include<iostream>
#include<algorithm>
using namespace std;

void print(int n, int W, int dp[][100]){
	cout << "\nCurrent DP Table:\n\n";
	for(int i=0; i<=n; i++){
		for(int j=0; j<=W; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
}

int knapsack(int n, int W, int weight[], int profit[]){
	int dp[100][100];
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=W; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=W; j++){
			if(weight[i-1] <= j){
				dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
		cout << "\nAfter considering Item " << i << ":\n";
		print(n, W, dp);
	}
	
	int w = W;
	int x[n];
	for(int i=0; i<n; i++){
		x[i] = 0;
	}
	
	for(int i=n; i>0; i--){
		if(dp[i][w] != dp[i-1][w]){
			x[i-1] = 1;
			w = w - weight[i-1];
		}
	}
	
	cout << "\nSelected Items:\n\n";

    cout << "Item\tWeight\tProfit\n";

    for(int i=0; i<n; i++){

        if(x[i] == 1){

            cout << i+1 << "\t"
                 << weight[i] << "\t"
                 << profit[i] << endl;
        }
    }

    cout << "\nSolution Vector x[]:\n";

    for(int i=0; i<n; i++){

        cout << x[i] << " ";
    }

    cout << endl;

	
	return dp[n][W];
}

int main(){
	int n, W;
	
	cout<<"Enter no of items: ";
	cin>>n;
	int weight[n];
	int profit[n];
	cout<<"Enter the weights of the items: "<<endl;
	for(int i=0; i<n; i++){
		cin>>weight[i];
	}
	cout<<"Enter the profit of the items: "<<endl;
	for(int i=0; i<n; i++){
		cin>>profit[i];
	}
	
	cout<<"Enter the capacity of knapsack: ";
	cin>>W;
	
	int maxProfit = knapsack(n, W, weight, profit);
	
	cout << "\nMaximum Profit = " << maxProfit << endl;
	
	return 0;
	
	
}
