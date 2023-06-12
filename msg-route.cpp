#include <bits/stdc++.h>
using namespace std;
void bfs(int start,int n, vector<vector<int>> &gr){
    vector<int> parent(n+1);
    vector<int> vis(n+1,0);
    for(int i=0;i<n+1;i++) parent[i] =i;
    queue<int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : gr[node]){
            if(vis[it]!=1){
                vis[it]=1;
                q.push(it);
                parent[it] = node;
                if(it==n){
                    vector<int> ans;
                    while(parent[it]!=it){
                        ans.push_back(it);
                        it = parent[it];
                    }
                    ans.push_back(it);
                    reverse(ans.begin(),ans.end());
                    cout<<ans.size()<<endl;
                    for(auto x: ans) cout<<x<<" ";
                    cout<<endl;
                    return ;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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
    bfs(1,n,gr);
    return 0;
}