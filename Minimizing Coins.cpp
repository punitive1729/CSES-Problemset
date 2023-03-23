#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n;
vector<ll> a,dp;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll n,t;
  cin>>n>>t;
  
  a.resize(n);
  dp.resize(t+2,INT_MAX);
  
  for(ll i=0;i<n;i++){
    cin>>a[i];
    if(a[i]<=t)
      dp[a[i]]=1;
  }
  
  dp[0]=0;
  sort(a.begin(),a.end());
  
  for(ll i=1;i<=t;i++){
    for(ll j=0;j<n;j++){
      if(a[j]>i)
        break;
      dp[i]=min(dp[i],1+dp[i-a[j]]);
    }
  }
  
  if(dp[t]>=INT_MAX)
    dp[t]=-1;
  
  cout<<dp[t]<<"\n";
}