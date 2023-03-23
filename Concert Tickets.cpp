#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n,m;
  cin>>n>>m;
  
  multiset<ll> s;
  for(ll i=0;i<n;i++){
    ll x;cin>>x;
    s.insert(-x);
  }
  
  for(ll i=0;i<m;i++){
    ll x;cin>>x;
    auto it=s.lower_bound(-x);
    if(it==s.end())
      cout<<"-1\n";
    else{
      cout<<(-*it)<<"\n";
      s.erase(it);
    }
  }
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}