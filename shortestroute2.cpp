#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,1e15));
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(c,dist[a][b]);
        dist[b][a] = min(c,dist[b][a]);
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            if(i==j) dist[i][j] =0;
        }
    }
    for(ll x = 1;x<=n;x++){
        for(ll i =1; i<=n;i++){
            for(ll j = 1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][x]+dist[x][j]);
            }
        }
    }
    for(ll i = 0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        if(dist[a][b]== 1e15 ) cout<<"-1"<<endl;
        else cout<<dist[a][b]<<endl;
    }

    return 0;
}