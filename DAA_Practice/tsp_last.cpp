#include <iostream>
#include <climits>

using namespace std;

int graph[10][10];
int visited[10];

int path[10];
int bestPath[10];

int n;

int minCost = INT_MAX;

void tsp(int city, int count, int cost)
{
    if(count == n && graph[city][0] > 0)
    {
        int totalCost = cost + graph[city][0];

        if(totalCost < minCost)
        {
            minCost = totalCost;

            for(int i = 0; i < n; i++)
            {
                bestPath[i] = path[i];
            }
        }

        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && graph[city][i] > 0)
        {
            visited[i] = 1;

            path[count] = i;

            tsp(i, count + 1, cost + graph[city][i]);

            visited[i] = 0;
        }
    }
}

void solve()
{
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;

    path[0] = 0;

    tsp(0, 1, 0);

    cout << "\nMinimum Travelling Cost = "
         << minCost;

    cout << "\nMinimum Path = ";

    for(int i = 0; i < n; i++)
    {
        cout << bestPath[i] << " -> ";
    }

    cout << "0";
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "\nEnter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    solve();

    return 0;
}
