#include<iostream>
using namespace std;

void print(int n, int A[][]){
	for(int i=1; i<=n; i++){

        for(int j=1; j<=n; j++){

            if(A[i][j] == 99999){
                cout<<"INF ";
            }
            else{
                cout<<A[i][j]<<" ";
            }
        }

        cout<<endl;
    }
}

int main(){
	int n;
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	int A[n+1][n+1];
	
	cout<<"Enter cost matrix:"<<endl;
    cout<<"Enter -1 for infinity"<<endl;

    for(int i=1; i<=n; i++){

        for(int j=1; j<=n; j++){

            cin>>A[i][j];

            if(A[i][j] == -1){
                A[i][j] = 99999;
            }
        }
    }
    
	cout<<"\nCost Matrix:\n";

    for(int i=1; i<=n; i++){

        for(int j=1; j<=n; j++){

            if(A[i][j] == 99999){
                cout<<"INF ";
            }
            else{
                cout<<A[i][j]<<" ";
            }
        }

        cout<<endl;
    }
    
    for(int k=1; k<=n; k++){
    	for(int i=1; i<=n; i++){
    		for(int j=1; j<=n; j++){
    			if(A[i][k] != 99999 && A[k][j] != 99999){
    				if(A[i][k] + A[k][j] < A[i][j]){
    					A[i][j] = A[i][k] + A[k][j];
 				    }
				}
			}
		}
		
		cout<<"\nMatrix after k= "<<k<<endl;
		
		print(n, A);
	}

	
	return 0;
	
}
