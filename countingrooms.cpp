#include<bits/stdc++.h>
using namespace std;

void dfs(int r,int c,int n,int m,vector<vector<char>> &gr,vector<vector<int>> &vis){
    vis[r][c] = 1;
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int cr = r+dr[i];
        int cc = c+ dc[i];
        if(cr>=0 && cr<n &&cc>=0 && cc<m && vis[cr][cc]!=1 && gr[cr][cc]=='.'){
            dfs(cr,cc,n,m,gr,vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> gr(n,vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>gr[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gr[i][j]== '.' && vis[i][j]!=1){
                c++;
                dfs(i,j,n,m,gr,vis);
            }
        }
    }
    cout<<c<<endl;
    return 0;
}