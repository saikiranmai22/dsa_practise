#include<iostream>
#include<vector>
using namespace std;
 bool subsetsum(const vector<int> &arr, int target, int n){
    //dp table
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    //
    for(int i=0;i<=n;i++){
        dp[i][0]= true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            //sum j without including the current element
            dp[i][j]= dp[i-1][j];
            //sum j including the current element
            if(arr[i-1]<=j){
                dp[i][j]= dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][target];
 }

 int main(){
    vector<int> arr={3,34,4,12,4,2};
    // int n, target;
    // cin>>n>>target;
    int n=6;
    int target= 9;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     arr.push_back(x);
    // }

    if(subsetsum(arr, target, n)){
        cout<<"exists";
    }
    else{
        cout<<"does not exist";
    }
    return 0;
 }