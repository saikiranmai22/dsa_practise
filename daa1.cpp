//dcc based to compute maximum integer in the array
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum element in an array using DCC approach
int FindMax(const vector<int>& A, int left, int right) {
    // Base case: If the subarray has only one element
    if (left == right) {
        return A[left];
    }

    // Step 1: Divide the array
    int mid = left + (right - left) / 2;

    // Step 2: Conquer by finding max in both subarrays
    int max_left = FindMax(A, left, mid);
    int max_right = FindMax(A, mid + 1, right);

    // Step 3: Combine the results by returning the maximum of both
    return max(max_left, max_right);
}

int main() {
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = A.size();

    int max_value = FindMax(A, 0, n - 1);
    cout << "The maximum value in the array is: " << max_value << endl;

    return 0;
}
