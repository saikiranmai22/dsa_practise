#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using dynamic programming
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    // Create a 2D dp array, where dp[i][j] represents the maximum value
    // for a capacity j with the first i items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    // Build dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                // Either include the item or don't
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            } else {
                // Cannot include the item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // The maximum value is stored in dp[n][W]
    return dp[n][W];
}

int main() {
    int n, W;

    // Input the number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> wt(n), val(n);

    // Input the weights and values of the items
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    // Call the knapsack function and print the result
    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    
    return 0;
}
