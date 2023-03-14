#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n;
  cin>>n;
  
  vector<ll> mp(n+2,0);
  
  for(ll i=1;i<n;i++){
    ll x;
    cin>>x;
    mp[x]++;
  }
  
  for(ll i=1;i<=n;i++){
    if(mp[i]==0){
      cout<<i;
      return 0;
    }
  }
}