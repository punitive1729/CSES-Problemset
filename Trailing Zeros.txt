#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n;
  cin>>n;
  
  ll p5=0,curr=5;
  
  while(curr<=n){
    p5+=n/curr;
    curr*=5;
  }
  
  cout<<p5<<"\n";
  
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}