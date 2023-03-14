#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n;
  cin>>n;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  ll cnt=0;
  unordered_map<ll,ll> mp;
  mp[0]=1;
  
  ll cs=0;
  for(ll i=0;i<n;i++){
    cs=(n+(cs+a[i])%n)%n;
    cnt+=mp[cs];
    mp[cs]++;
  }
  
  cout<<cnt<<"\n";
}