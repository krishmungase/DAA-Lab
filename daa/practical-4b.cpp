// TSP using Branch and Bound
#include <iostream>
using namespace std;

int N;
int cost[10][10];
bool visited[10];
int minCost = 100000;
int bestPath[20], currPath[20];

void tsp(int city, int count, int currCost) {
    if (count == N && cost[city][0]) {
        int total = currCost + cost[city][0];
        if (total < minCost) {
            minCost = total;
            for (int i = 0; i < N; i++)
                bestPath[i] = currPath[i];
            bestPath[N] = 0;
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[city][i]) {
            int temp = currCost + cost[city][i];
            if (temp < minCost) {              // bound: prune
                visited[i] = true;
                currPath[count] = i;
                tsp(i, count + 1, temp);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> N;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    visited[0] = true;
    currPath[0] = 0;
    tsp(0, 1, 0);

    cout << "\nOptimal Path: ";
    for (int i = 0; i <= N; i++)
        cout << bestPath[i] << " ";

    cout << "\nTotal Cost = " << minCost << endl;
    return 0;
}