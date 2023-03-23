#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n,q;
  cin>>n>>q;
  
  vector<ll> a(n+1,0);
  for(ll i=1;i<=n;i++)
    cin>>a[i];
  
  for(ll i=1;i<=n;i++)
    a[i]^=a[i-1];
    
  while(q--){
    ll l,r;
    cin>>l>>r;
    cout<<(a[r]^a[l-1])<<"\n";
  }
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}