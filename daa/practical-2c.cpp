// ## Activity Selection Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<pair<int, int>> activities(n);  // {finish, start}
    cout << "Enter start and finish times of each activity:\n";
    for (int i = 0; i < n; i++) {
        int start, finish;
        cout << "Activity " << i + 1 << " - Start: ";
        cin >> start;
        cout << "Activity " << i + 1 << " - Finish: ";
        cin >> finish;
        activities[i] = {finish, start};
    }

    // Sort by finish time
    sort(activities.begin(), activities.end());

    cout << "\nAfter sorting:\n";
    cout << "Start Time\tFinish Time\n";
    for (int i = 0; i < n; i++)
        cout << activities[i].second << "\t\t" << activities[i].first << endl;

    cout << "\nSelected activities are:\n";
    cout << "Activity: (" << activities[0].second << ", " << activities[0].first << ")\n";
    int last = activities[0].first;
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= last) {
            cout << "Activity: (" << activities[i].second << ", " << activities[i].first << ")\n";
            last = activities[i].first;
        }
    }

    return 0;
}

/*
Sample Input/Output:
6
1 2
3 4
0 6
5 7
8 9
5 9
*/