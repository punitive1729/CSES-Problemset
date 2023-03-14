#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print(ll n,ll d){
  string s;
  while(n || d){
    s+=((n&1) + '0');
    n>>=1;
    d--;
  }
  for(ll i=s.length()-1;i>=0;i--)
    cout<<s[i];
  cout<<"\n";
}

void solver(){
  ll n;cin>>n;
  ll t=n;
  n=1<<n;
  
  for(ll i=0;i<n;i++)
    print(i^(i>>1),t);
  
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}