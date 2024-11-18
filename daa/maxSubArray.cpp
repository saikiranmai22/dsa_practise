#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to find the maximum sum subarray crossing the midpoint
int crossSum(const vector<int>& arr, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;

    // Find max sum in the left half
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;

    // Find max sum in the right half
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

// Function to find the maximum sum subarray using divide and conquer
int maxSubArraySum(const vector<int>& arr, int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    // Find the maximum subarray sum in the left, right, and crossing parts
    return max({maxSubArraySum(arr, low, mid), maxSubArraySum(arr, mid + 1, high), crossSum(arr, low, mid, high)});
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum using divide and conquer is: " << maxSubArraySum(arr, 0, arr.size() - 1) << endl;
    return 0;
}
