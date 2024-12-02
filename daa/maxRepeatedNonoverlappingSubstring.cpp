#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_map>
using namespace std;

vector<string> FindMaxRepeatedStrings(const string& S){
    int n=S.length();
    vector<string> max_substring; //return vector of strings

    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            string substring = S.substr(i,j-i); //generating all the substrings
            int count=0; //non overlapping count
            int index=0; // next occurence of the substring 

            while(index<=n- substring.length()){
                size_t found = S.find(substring, index); // give sout the index where the substring is found , the index here is from where the search will start
                if (found != string::npos) { //if substring found, not equal to empty string
                    count++;
                    index = found + substring.length(); // Move past the last occurrence to ensure non-overlap
                } else {
                    break;
                }
            }
            //adds if apprears more than once
            if (count > 1) {
                if (find(max_substring.begin(), max_substring.end(), substring) == max_substring.end()) {
                    max_substring.push_back(substring);
                }
            }                
        }
    }

    int maxLenght=0;
    vector<string> result;
    //finds the longest max repeated substring
    for(const string& s: max_substring){
        if (s.length() > maxLenght) {
            maxLenght = s.length();
            result.clear(); // Clear the list as we found a longer substring
            result.push_back(s);
       } else if (s.length() == maxLenght) { // multiple with the same length
            result.push_back(s);
            } 
        }
    return result;
}

int main(){
    string S="ababhbcbc";
    vector<string> result= FindMaxRepeatedStrings(S);

    if(!result.empty()){
        for(const string& substring: result){
            cout<<substring<<endl;
        }
    }else{
        cout<<"not found"<<endl;
    }
}