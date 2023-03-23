#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
vector<ll> dp;
 
 
void solver(){
  ll n,x;
  cin>>n>>x;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
    
  sort(a.begin(),a.end());
  dp.resize(x+2,0);
  
  dp[0]=1;
  
  for(ll i=0;i<n;i++){
    for(ll j=a[0];j<=x;j++){
      if(j>=a[i])
        dp[j]=(dp[j]+dp[j-a[i]])%mod;
    }
  }
  cout<<dp[x]<<"\n";
}
 
int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}