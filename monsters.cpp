#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<pair<int,int>> monster; //for storing locations of monsters
vector<vector<int>> g; 
// for storing time values at each block like least time taken by monster 
// to reach that block and also least time taken by player to reach 
// so that he does go there again after analysing that block 
map<pair<int,int>, pair<int,int>> par_mp;
//for storing parent location of block from  where player came from.
pair<int,int> si, se; //to store starting and ending points of player
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,1},{0,-1}}; 

//this is to check if any monster can reach the spot before the player reaches the spot
// or else the player has reached the spot in a better time than it.
bool isValid(int x, int y, int timer)
{
  if(x<0 or y<0 or x>=n or y>=m)
  {
    return false;
  }
  if(g[x][y] <= timer)
  {
    return false;
  }
  return true;
}
// to check whether the player got a spot to escape
bool isExcape(int x, int y, int timer)
{
  if(!isValid(x,y,timer)) return false;
  if(x == 0 or y == 0 or 
    x == n-1 or y == m-1) return true;
  return false;
}
 
bool bfs_escape()
{
  queue<pair<pair<int,int>,int>> q; //{{position of player},time taken to reach that position}
  q.push(make_pair(si,0));
  par_mp[si] = {-1,-1}; //parent of starting point
  while(!q.empty())
  {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int timer = q.front().second; 
    timer++; q.pop();
    for(auto mv: moves)
    {
      int tx = cx+mv.first;
      int ty = cy+mv.second;
      //if it directly got a point to escape return true
      if(isExcape(tx,ty,timer))
      {
       par_mp[{tx,ty}] = {cx,cy};
       se = {tx,ty}; return true; 
      }
      //at imtermediate steps if its a valid spot push it into queue
      if(isValid(tx,ty,timer))
      {
        par_mp[{tx,ty}] = {cx,cy};
        g[tx][ty] = timer;
        q.push({{tx,ty},timer});
      }
    }
  }
  return false;
}
// this is to process all the monsters where they can reach at a particular instance
void preprocess_lava_flow()
{
  queue<pair<pair<int,int>,int>> q; //to store {{monster's location},time taken}
  //take all monsters into queue.
  for(auto m: monster)
  {
    q.push(make_pair(m,0));
  }
  while(!q.empty())
  {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int timer = q.front().second; 
    timer++; q.pop();

    for(auto mv: moves)
    {
      int tx = cx+mv.first;
      int ty = cy+mv.second;
      if(isValid(tx,ty,timer))
      {
        g[tx][ty] = timer; //record the value of least time taken by monster to reach the spot
        q.push({{tx,ty},timer});
      }
    }
  }

  
  
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  g.resize(n);
  for(int i = 0; i < n; ++i)
  {
    g[i].resize(m);
  }
 
  for(int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      g[i][j] = INT_MAX;
    }
  }  
 
  for(int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      char c; cin >> c;
      if(c == '#')
      {
        g[i][j] = 0; //wall
      }
      else if(c == 'M')
      {
        g[i][j] = 0; //monster '0' time to reach
        
          monster.push_back({i,j});
      }
      else if(c == 'A')
      {
        g[i][j] = 0; //player
        si = {i,j};
      }
      else
      {
        g[i][j] = INT_MAX; 
        //other blocks just mark them as infinite as they are safe..
      }
    }
  }
  if(si.first == 0 or si.second == 0 or si.first == n-1 or si.second == m-1) 
  {
    cout << "YES" << endl;
    cout << 0;
    return 0;
  }
  preprocess_lava_flow(); //get values of time taken to reach a spot by monster
  
  if(!bfs_escape())
  {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  //traverse in backwards by travelling to the parent
  pair<int,int> tmp = se;
  pair<int,int> tmp1 = par_mp[se];
  pair<int,int> ed = {-1,-1}; 
  vector<char> ans;
  while(tmp1 != ed)
  {
    
    if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('R');
    }
    if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('L');
    }
    if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
    {
      ans.push_back('D');
    }
    if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
    {
      ans.push_back('U');
    }
    tmp = par_mp[tmp];
    tmp1 = par_mp[tmp];
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto c: ans)
  {
    cout << c;
  }
}