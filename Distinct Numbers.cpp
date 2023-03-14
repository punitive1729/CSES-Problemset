#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n;
  cin>>n;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  sort(a.begin(),a.end());
  ll cnt=0;
  
  for(ll i=0;i<n;){
    ll p=a[i];
    while(i<n and p==a[i])
      i++;
    cnt++;
  }
  
  cout<<cnt<<"\n";
  
}