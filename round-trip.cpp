#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int> &parent,vector<vector<int>> &gr,vector<int> &vis){
    vis[node]=1;
    for(auto it: gr[node]){
        if(vis[it]!=1){
            parent[it]=node;
            if(dfs(it,parent,gr,vis)==1) return 1;;
        }
        else{
            if(it!=parent[node]){
                string s ="";
                s += to_string(it);
                s.push_back(' ');
                int c=1;
                while(node!=it){
                    s += to_string(node);
                    s.push_back(' ');
                    node = parent[node];
                    c++;
                }
                s += to_string(node);
                c++;
                cout<<c<<endl;
                cout<<s<<endl;
                return 1;
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
    vector<int> vis(n+1,0);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++) parent[i] = i;
    bool x = 0;
    for(int i=1;i<=n;i++){
       if(vis[i]!=1) x =  dfs(i,parent,gr,vis);
       if(x==1){
        return 0;
       }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}