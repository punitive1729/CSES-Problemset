#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

void solver(){
  ll n;
  cin>>n;
  
  vector<vector<ll>> a;
  for(ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    if(x>y)
      swap(x,y);
    a.push_back({x,y});
  }
  
  sort(a.begin(),a.end());
  
  vector<ll> dp(n+1,0);
  dp[n-1]=1;
  ll f=1;
  for(ll i=n-2;i>=0;i--){
    ll ans=n,l=i+1,r=n-1;
    while(l<=r){
      ll m=l+((r-l)>>1);
      if(a[m][0]>=a[i][1]){
        r=m-1;
        ans=m;
      }
      else
        l=m+1;
    }
    dp[i]=max(dp[i+1],1+dp[ans]);
    f=max(f,dp[i]);
  }

  cout<<f<<"\n";  
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}