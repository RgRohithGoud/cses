#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> dist;
vector<ll> vis;
vector<ll> path;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> gr(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
    }
    dist.resize(n+1);
    vis.resize(n+1);
    path.resize(n+1);
    for(int i=1;i<=n;i++){
        vis[i] =0;
        dist[i] = LLONG_MAX;
        path[i] = 0;
    }
    dist[1]=0;
    path[1] = 1;
    dfs(1,gr);
    return 0;
}