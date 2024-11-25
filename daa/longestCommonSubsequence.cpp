#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//bottom up appraoch, table will fill from top to down
//memoisation - top down approach
string lcs(string str1, string str2){
    int n = str1.size();
    int m= str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0)); // stores the lenght of the lcs
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (str1[i-1]==str2[j-1]){ // match
                dp[i][j]= dp[i-1][j-1]+1; // add 1 to the lcs length of previous substrings
            }else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]); // exclude either character
            }
        }
    }
    string lcs=""; // to store the lcs
    int i=n, j=m;
    while(i>0 &&j>0){ // transverse entire string
        if(str1[i-1]==str2[j-1]){ // match
            lcs +=str1[i-1]; //add the char
            i--; // move diagonally up-left in the dp table 
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--; //move up
        }else{
            j--; // move left
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