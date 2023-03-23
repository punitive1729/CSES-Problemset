#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
const ll mod=1e9+7;
 
void getInput(vector<ll>& a,ll n){
  for(ll i=0;i<n;i++)
    cin>>a[i];
}
 
void solver(){
  ll n,t;
  cin>>n>>t;
  
  vector<ll> a(n);
  
  getInput(a,n);
  
  dp.resize(t+2,0);
  dp[0]=1;
  
  sort(a.begin(),a.end());
  
  for(ll i=1;i<=t;i++){
    for(ll j=0;j<n;j++){
      if(i<a[j])
        break;
      dp[i]=(dp[i]+dp[i-a[j]])%mod;
    }
  }
  
  cout<<dp[t]<<"\n";
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}