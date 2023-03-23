#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solver(){
  ll n;cin>>n;
  if(n==1){
    cout<<"1\n";
    return;
  }
  if(n<4){
    cout<<"NO SOLUTION\n";
    return;
  }
  
  for(ll i=2;i<=n;i+=2)
    cout<<i<<" ";
  for(ll i=1;i<=n;i+=2)
    cout<<i<<" ";
  cout<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
  
}