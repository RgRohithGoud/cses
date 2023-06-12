#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(int node,vector<vector<ll>> &gr,vector<int> &vis){
    vis[node]=1;
    for(auto it: gr[node]){
        if(vis[it]!=1){
            dfs(it,gr,vis);
        }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> gr;
    vector <vector<ll>> normalgraph(n+1);
    vector<int> vis(n+1,0);
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        vector<ll> v = {a,b,c};
        gr.push_back(v);
        normalgraph[a].push_back(b);
    }
    vector<ll> dist(n+1,LLONG_MIN);
    dist[1] = 0;
    for(ll x=0;x<n-1;x++){
        for(ll i=0;i<m;i++){
            vector<ll> v = gr[i];
            if(dist[v[0]]!=LLONG_MIN){
                if(dist[v[0]]+v[2]>dist[v[1]]){
                    dist[v[1]] = dist[v[0]]+v[2];
                }
            }
        }
    }
    for(ll i=0;i<m;i++){
        vector<ll> v = gr[i];
        if(dist[v[0]]!=LLONG_MIN){
            if(dist[v[0]]+v[2]>dist[v[1]]){
                dfs(v[0],normalgraph,vis); // check whether the increasing loop is can pass through the 'n'th node 
            }
        }
    }
    if(dist[n]==LLONG_MIN) dist[n] =-1;
    if(vis[n]!=1) cout<<dist[n]<<endl;
    else cout<<"-1"<<endl;
    return 0;
}