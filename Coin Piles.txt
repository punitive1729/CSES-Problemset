#include <bits/stdc++.h>
using namespace std;
#define ll long long


string solver(){
  ll a,b;
  cin>>a>>b;
  
  // 2x + y = a
  // x + 2y = b
  
  if(min(a,b)*2 < max(a,b))
      return "NO";
  
  if(a==b and a==0)
    return "YES";

  ll d=(a<<1)-b;
  if(d%3)
    return "NO";
  
  ll x=d/3;
  
  d=b-x;
  if(d&1)
    return "NO";
  
  ll y=d/2;
  
  if(x>=0 and y>=0)
    return "YES";
  
  return "NO";
}

int main(){
  ll t=1;
  cin>>t;
  
  while(t--)
    cout<<solver()<<"\n";
}