#include<iostream>
#include<vector>
#define INF 1e9;
using namespace std;

int mini(vector<int> &arr, int i, int j){
    if(i+1==j){
        return 0;
    }
    int res=INF;
    for(int k=i+1;k<j;k++){
        int curr= mini(arr,i,k)+mini(arr,k,j)+arr[i]*arr[k]*arr[j];
        res=min(curr,res);
    }
    return res;
}

int mm(vector<int> &arr){
    int n=arr.size();
    return mini(arr,0,n-1);
}

int main(){
    vector<int> arr={40,20,30,10,30};
    cout<<mm(arr);
    return 0;
}