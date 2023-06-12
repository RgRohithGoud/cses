#include <bits/stdc++.h>
using  namespace std;

bool bfs(int start,vector<vector<int>> &gr,vector<int> &vis){
    vis[start] = 0;
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        int node = q.front().first;
        int val = q.front().second;
        q.pop();
        for(auto it: gr[node]){
            if(vis[it]!=-1){
                if(vis[it]==vis[node]) return 1;
            }
            else{
                vis[it]= 1-vis[node];
                q.push({it,vis[it]});
            }
        }
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    vector<int> vis(n+1,-1);
    bool x = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            x = bfs(i,gr,vis);
        }
        if(x==1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<vis[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}