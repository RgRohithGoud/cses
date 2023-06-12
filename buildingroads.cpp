#include <bits/stdc++.h>
using namespace std;
void dfs(int node ,int n, vector<vector<int>> &gr, vector<int> &vis){
    vis[node] = 1;
    for(auto it: gr[node]){
        if(vis[it]!=1){
            dfs(it,n,gr,vis);
        }
    }
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
    vector<int> vis(n+1,0);
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        if(vis[i]!=1){
            if(i!=1){
                ans.push_back({1,i});
            }
            dfs(i,n,gr,vis);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it: ans) cout<<it.first<<" "<<it.second<<endl;
    return 0;

}