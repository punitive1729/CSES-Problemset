#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int main(){
  ll n;
  cin>>n;
  
  vector<ll> dp(n+2,0);
  dp[0]=1;
  
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<7;j++){
      if(i>=j)
        dp[i]=(dp[i]+dp[i-j])%mod;
    }
  }
  
  cout<<dp[n]<<"\n";
}