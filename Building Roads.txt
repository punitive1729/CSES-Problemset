#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> g;
vector<ll> par;

void dfs(int u,int r){
  par[u]=r;
  for(auto e:g[u])
    if(par[e]<0)
      dfs(e,r);
}

void solver(){
  ll n,m;
  cin>>n>>m;
  
  g.resize(n+2);
  par.resize(n+2,-1);
  
  while(m--){
    ll u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  ll cnt=0;
  vector<ll> rep;
  for(ll i=1;i<=n;i++){
    if(par[i]<0){
      dfs(i,i);
      cnt++;
      rep.push_back(i);
    }
  }
  
  cout<<rep.size()-1<<"\n";
  for(ll i=1;i<rep.size();i++)
    cout<<rep[i-1]<<" "<<rep[i]<<"\n";
  
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();//<<"\n";
}