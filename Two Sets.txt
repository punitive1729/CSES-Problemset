#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n;
  cin>>n;
  
  ll s=(n*(n+1))>>1;
  if(s&1){
    cout<<"NO\n";
    return;
  }
  
  ll s1=0,s2=0;
  vector<ll> f1,f2;
  for(ll i=n;i>0;i--){
    if(s1>=s2){
      s2+=i;
      f2.push_back(i);
    }
    else{
      s1+=i;
      f1.push_back(i);
    }
  }
  
  if(s1==s2){
    cout<<"YES\n"<<f1.size()<<"\n";
    for(auto e:f1)
      cout<<e<<" ";
    cout<<"\n"<<f2.size()<<"\n";
    for(auto e:f2)
      cout<<e<<" ";
    return;
  }
  cout<<"NO\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();//<<"\n";
}