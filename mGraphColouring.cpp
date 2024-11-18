#include<iostream>
#include <vector>
using namespace std;

bool isSafeToAssign(int i, int j, bool graph[101][101],int v, vector<int> &color){
    for(int k=0;k<v;k++){
        if(graph[i][k]==1 && color[k]==j)return false;
    }
    return true;
}

bool func( bool graph[101][101], int m, int v, int i, vector<int> &color){
    if(i==v) return true;
    for(int j=0;j<m;j++){

        if(isSafeToAssign(i,j,graph,v,color)){
            color[i]=j;
            if(func(graph,m,v,i+1, color)) return true;
            color[i]=-1;
        }       
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m , int v, vector<int> &color){
    vector <int> color(v,-1);
    return func(graph, m,v,0,color);
}