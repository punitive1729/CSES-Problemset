#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
 
ll solver(ll l,ll r,vector<ll>& a,vector<ll>& p){
  if(l>r)
    return LONG_MIN;
  
  if(l==r)
    return a[l];
  
  if(dp[l][r]>LONG_MIN)
    return dp[l][r];
  
  ll left=a[l]+p[r]-p[l]-solver(l+1,r,a,p);
  ll right=a[r]+p[r-1]-p[l-1]-solver(l,r-1,a,p);
  
  return dp[l][r]=max(left,right);
}
 
void solver(){
  ll n;
  cin>>n;
  vector<ll> a(n+2,0),p(n+2,0);
  dp.resize(n+2,vector<ll>(n+2,LONG_MIN));
  
  for(ll i=1;i<=n;i++){
    cin>>a[i];
    p[i]=p[i-1]+a[i];
  }
  
  cout<<solver(1,n,a,p);
}
 
int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}