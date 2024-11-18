#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string lcs(string str1, string str2){
    int n = str1.size();
    int m= str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (str1[i-1]==str2[j-1]){
                dp[i][j]= dp[i-1][j-1]+1;
            }else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs="";
    int i=n, j=m;
    while(i>0 &&j>0){
        if(str1[i-1]==str2[j-1]){
            lcs +=str1[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}
int main(){
    string str1 = "ABCBDAB";
    string str2 = "BDCABC";
    string answer=lcs(str1,str2);
    cout<<answer;
    return 0;
}