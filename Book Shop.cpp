#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x;
vector<ll> a,b;
vector<vector<ll>> dp;

ll solver(ll ind,ll p){
  if(ind>=n or p==0)
    return 0;
    
  if(dp[p][ind]>=0)
    return dp[p][ind];
  
  ll next=solver(ind+1,p);
  if(a[ind]<=p)
    next=max(next,b[ind]+solver(ind+1,p-a[ind]));
  
  return dp[p][ind]=next;
}

int main(){
  cin>>n>>x;
  
  a.resize(n);
  b.resize(n);
  
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  for(ll i=0;i<n;i++)
    cin>>b[i];
  
  dp.resize(x+2,vector<ll>(n+2,-1));
  cout<<solver(0,x);
}