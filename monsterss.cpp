#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> gr; //timer
vector <pair<int,int>> monsters;
pair<int,int> si;
pair <int,int> se;
map <pair<int,int>,pair<int,int>> prt_playr; 
vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
bool isvalid(int r,int c,int timer){
    if(r<0|| r>=n ||c<0 || c>=m) return false;
    if(timer<gr[r][c]){
        gr[r][c] = timer;
        return true;
    }
    return false;
}
bool foundway(int r,int c,int timer){
    if(isvalid(r,c,timer)){
        if(r==0 || c==0 || r == n-1 || c == m-1) return true;
        else return false;
    }
    return false;
}
bool isescape(){
    prt_playr[si] = {-1,-1};
    queue<pair<pair<int,int>,int>> q; //{node,timer}
    q.push({si,0});
    while (!q.empty())
    {
        int p1 = q.front().first.first;
        int p2 = q.front().first.second;
        int timer  = q.front().second;
        q.pop();
        timer++;
        for(auto it: moves){
            int cr = p1 + it.first;
            int cc = p2 + it.second;
            if(foundway(cr,cc,timer)){
                prt_playr[{cr,cc}] = {p1,p2};
                se = {cr,cc};
                return true; 
            }
            if(isvalid(cr,cc,timer)){
                prt_playr[{cr,cc}] = {p1,p2};
                q.push({{cr,cc},timer});
            }
        }
    }
    return false;
    
}
void preprocess_monsters(){
    queue<pair<pair<int,int>,int>> q;
    for(auto it: monsters){
        q.push({it,0});
    }
    while(!q.empty()){
        pair<int,int> block = q.front().first;
        int timer = q.front().second;
        q.pop();
        timer++;
        for(auto it: moves){
            int cr = block.first + it.first;
            int cc = block.second + it.second;
            if(isvalid(cr,cc,timer)){
                q.push({{cr,cc},timer});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    gr.resize(n);
    for(int i=0;i<n;i++) gr[i].resize(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            gr[i][j] = INT_MAX;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='M'){
                monsters.push_back({i,j});
                gr[i][j] =0;
            }
            if(c=='A'){
                si = {i,j};
                gr[i][j] = 0;
            }
            if(c=='#'){
                gr[i][j] = 0;
            }
        }
    }
    if(si.first == 0 or si.second == 0 or si.first == n-1 or si.second == m-1) 
    {
        cout << "YES" << endl;
        cout << 0;
        return 0;
    }
    preprocess_monsters();
    if(isescape()){
        cout<<"YES"<<endl;
        string s ="";
        pair<int,int> p = se;
        pair<int,int> p1 = prt_playr[se];
        while(p1.first!=-1 && p1.second!=-1 ){
            if(p1.first-p.first ==1 && p1.second- p.second==0){
                s.push_back('U');
            }
            if(p1.first-p.first == -1 && p1.second- p.second==0){
                s.push_back('D');
            }
            if(p1.first-p.first ==0 && p1.second- p.second== 1){
                s.push_back('L');
            }
            if(p1.first-p.first == 0 && p1.second- p.second== -1){
                s.push_back('R');
            }
            p = p1;
            p1 = prt_playr[p];
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}