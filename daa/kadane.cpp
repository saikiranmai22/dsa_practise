#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadane(const vector<int>& arr) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum is: " << kadane(arr) << endl;
    return 0;
}
