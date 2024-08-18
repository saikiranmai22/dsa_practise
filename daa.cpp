//recursive activity selector
#include <iostream>
#include <vector>

using namespace std;

void recursiveActivitySelector(vector<int> &s, vector<int> &f, int k, int n, vector<int> &selectedActivities) {
    int m = k + 1;

    // Find the first activity in S_k to finish
    while (m <= n && s[m] < f[k]) {
        m++;
    }

    // If a valid activity is found
    if (m <= n) {
        selectedActivities.push_back(m);  // Select this activity
        recursiveActivitySelector(s, f, m, n, selectedActivities);  // Recursively select the next activities
    }
}

int main() {
    vector<int> s = {0, 1, 3, 0, 5, 8, 5}; 
    vector<int> f = {0, 2, 4, 6, 7, 9, 9}; 
    int n = s.size() - 1;  
    vector<int> selectedActivities;
    
    selectedActivities.push_back(1);
    
    recursiveActivitySelector(s, f, 1, n, selectedActivities);

    cout << "Selected activities: ";
    for (int i : selectedActivities) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}