#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,x;
  cin>>n>>x;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  ll cnt=0,p=0,l=0,r=0,cs=0;
  while(r<n){
    cs+=a[r];
    while(l<r and cs>x){
      cs-=a[l];
      l++;
    }
    cnt+=(cs==x);
    r++;
  }
  cout<<cnt<<"\n";
}