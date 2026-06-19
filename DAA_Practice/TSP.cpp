#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int n;
int cost[10][10];

int dp[10][1 << 10];

int tsp(int mask, int pos){

    // Base Case:
    // If all cities are visited
    if(mask == (1 << n) - 1){
        return cost[pos][0];
    }

    // If already calculated
    if(dp[pos][mask] != -1){
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    // Try going to every unvisited city
    for(int city = 0; city < n; city++){

        // If city is not visited
        if((mask & (1 << city)) == 0){

            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city);

            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}

int main(){

    cout<<"Enter number of cities: ";
    cin>>n;

    cout<<"Enter cost matrix:"<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>cost[i][j];
        }
    }

    dp[n+1][n+1];

    // Start from city 0
    int minimumCost = tsp(cost, dp);

    cout<<"\nMinimum Cost = "<<minimumCost;

    return 0;
}
