#include <iostream>
#include <climits>
using namespace std;

int main(){
	int n;
	cout<<"Enter the no of matrix: ";
	cin>>n;
	
	int d[n+1];
	cout<<"Enter dimensions: "<<endl;
	for(int i=0; i<=n; i++){
		cin>>d[i];
	}
	
	int m[n+1][n+1], s[n+1][n+1];
	
	for(int i=1; i<=n; i++){
		m[i][i] = 0;
		s[i][i] = 0;
	}
	
	for(int l=2; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for(int k=i; k<=j-1; k++){
				int cost = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j];
				
				if(cost < m[i][j]){
					m[i][j] = cost;
					s[i][j] = k;
				}
			}
		}
	}
	cout<<"\nCost table:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i>j){
				cout<<"-\t";
			}
			else{
				cout<<m[i][j]<<"\t";
			}
		}
		cout<<endl;
	}
	
	cout << "\nSplit Table (s):\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i>=j){
				cout<<"-\t";
			}
			else{
				cout<<s[i][j]<<"\t";
			}
		}
		cout<<endl;
	}
	cout << "\nMinimum number of multiplications = "<< m[1][n] << endl;
	
	return 0;
}
