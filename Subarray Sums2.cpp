#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,x;
  cin>>n>>x;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  ll cnt=0;
  unordered_map<ll,ll> mp;
  mp[0]=1;
  ll cs=0;
  for(ll i=0;i<n;i++){
    cs+=a[i];
    ll r=cs-x;
    cnt+=mp[r];
    mp[cs]++;
  }
  
  cout<<cnt<<"\n";
}