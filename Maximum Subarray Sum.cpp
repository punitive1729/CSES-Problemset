#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

void solver(){
  ll n;cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  ll mx=a[0],cs=0,mn=0;
  for(auto e:a){
    cs+=e;
    mx=max({mx,e,cs-mn});
    mn=min(mn,cs);
  }
  cout<<mx<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}