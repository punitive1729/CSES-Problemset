#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
vector<vector<ll>> dp;


void solver(){
  ll n;cin>>n;
  ll t=(n*(n+1))>>1;
  if(t&1){
    cout<<"0\n";
    return;
  }
  
  t>>=1;
  dp.resize(2,vector<ll>(t+2,0));
  ll prev=0;

  for(ll i=1;i<=n;i++)
    dp[prev][0]=1;
  
  for(ll i=1;i<=t;i++){
    ll curr=1-prev;
    for(ll j=n;j>=1;j--){
      if(i>=j)
        dp[curr][i]=(dp[prev][i]+dp[prev][i-j])%mod;
    }
    prev=curr;
  }

  cout<<dp[prev][t]<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}