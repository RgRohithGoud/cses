    #include<bits/stdc++.h>
    using namespace std;
    void bfs(int r,int c,int n,int m,vector<vector<char>> &gr){
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> dir(n,vector<char>(m,'x'));
        vis[r][c] = 1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while (!q.empty())
        {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row = cr+dr[i];
                int col = cc + dc[i];
                if(row>=0 && row<n && col >=0 && col <m && vis[row][col]!=1 && (gr[row][col]=='.'|gr[row][col]=='B')){
                    vis[row][col] = 1;
                    q.push({row,col});
                    switch (i)
                    {
                    case 0:
                        dir[row][col] = 'R';
                        break;
                    case 1:
                        dir[row][col] = 'L';
                        break;
                    case 2:
                        dir[row][col] = 'D';
                        break;
                    case 3:
                        dir[row][col] = 'U';
                        break;

                    default:
                        break;
                    }
                    if(gr[row][col]=='B'){
                        cout<<"YES"<<endl;
                        string s ="";
                        while(row!=r || col!=c ){
                            s += dir[row][col];
                            switch (dir[row][col])
                            {
                            case 'R':
                                col--;
                            break;
                            case 'L':
                                col++;
                            break;
                            case 'D':
                                row--;
                            break;
                            case 'U':
                                row++;
                            break;
                            default:
                            break;
                            }
                        }
                        cout<<s.length()<<endl;
                        reverse(s.begin(),s.end());
                        cout<<s<<endl;
                        return;
                    }
                }
            }
        }
        cout<<"NO"<<endl;
        
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
        int si = 0,sj = 0,ei =0,ej = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gr[i][j]== 'A'){
                    si = i;
                    sj = j;
                }
                if(gr[i][j]=='B'){
                    ei = i;
                    ej = j;
                }
            }
        }
        bfs(si,sj,n ,m, gr);

        return 0;
    }