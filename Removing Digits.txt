#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int main(){
  ll n;
  cin>>n;
  
  vector<ll> dp(n+2,INT_MAX);
  dp[0]=0;
  
  for(ll i=1;i<=n;i++){
    string s=to_string(i);
    for(auto c:s)
      dp[i]=min(1+dp[i-(c-'0')],dp[i]);
  }
  
  cout<<dp[n]<<"\n";
}