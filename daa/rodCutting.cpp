#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function for top-down approach (Recursive with Memoization)
int rodCuttingTopDown(int n, vector<int>& price, vector<int>& dp) {
    // If the value is already calculated, return it
    if (dp[n] != -1) {
        return dp[n];
    }

    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        max_val = max(max_val, price[i] + rodCuttingTopDown(n - i, price, dp));
    }

    dp[n] = max_val; // Memoize the result
    return dp[n];
}

// Function for bottom-up approach (Dynamic Programming)
int rodCuttingBottomUp(int n, vector<int>& price) {
    vector<int> dp(n + 1, 0);  // DP table

    // Build the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        int max_val = 0;
        for (int j = 1; j <= i; j++) {
            max_val = max(max_val, price[j] + dp[i - j]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    // Example: Prices for each length of the rod
    vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20}; // 0th index is unused
    int n = 8; // Length of the rod

    // Top-Down Approach
    vector<int> dpTopDown(n + 1, -1); // Initialize dp array for memoization
    int resultTopDown = rodCuttingTopDown(n, price, dpTopDown);
    cout << "Maximum profit (Top-Down): " << resultTopDown << endl;

    // Bottom-Up Approach
    int resultBottomUp = rodCuttingBottomUp(n, price);
    cout << "Maximum profit (Bottom-Up): " << resultBottomUp << endl;

    return 0;
}
