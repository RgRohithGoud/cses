#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> gr(n+1);
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
    }
    vector<ll> dist(n+1,1e15);
    dist[1] =0;
    priority_queue <pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> > q; //{dist,node}
    q.push({0,1});
    while(!q.empty()){
        ll d = q.top().first;
        ll node = q.top().second;
        q.pop();
        if(d>dist[node]) continue;
        for(auto it: gr[node]){
            ll adjnode = it.first;
            ll edw = it.second;
            if(dist[adjnode]>d+edw){
                dist[adjnode] = d+edw;
                q.push({d+edw,adjnode});
            }
        }
    }
    for(ll i=1; i<n+1;i++){
        if(dist[i] == 1e15) dist[i] =-1;
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}