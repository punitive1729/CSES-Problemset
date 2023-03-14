#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll solver(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  sort(a.begin(),a.end());
  if(a[0]!=1)
    return 1;

  ll prev=1,s=2;
  for(ll i=1;i<n;i++){
    if(a[i]>s)
      return s;
    prev+=a[i];
    s=prev+1;
  }
  return s;
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    cout<<solver();
  
}