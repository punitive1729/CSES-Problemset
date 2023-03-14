#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> a;
vector<vector<ll>> vis;
ll R,C;

void dfs(ll r,ll c){
  if(r<0 or c<0 or r>=R or c>=C)
    return;
    
  if(vis[r][c] or a[r][c]=='#')
    return;
  
  vis[r][c]=1;
  dfs(r-1,c);
  dfs(r,c-1);
  dfs(r+1,c);
  dfs(r,c+1);
}

void solver(){
  cin>>R>>C;
  a.clear();
  
  for(ll i=0;i<R;i++){
    string s;
    cin>>s;
    a.push_back(s);
  }
  
  ll ans=0;
  
  vis.resize(R+1,vector<ll>(C+1,0));
  for(ll i=0;i<R;i++){
    for(ll j=0;j<C;j++){
      if(a[i][j]=='.' and !vis[i][j]){
        dfs(i,j);
        ans++;
      }
    }
  }
  
  cout<<ans<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();//<<"\n";
}