#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

void solver(){
  ll k;
  cin>>k;
  
  ll l=1,r=LONG_MAX>>1,ans=0,sum=0;
  
  while(l<=r){
    ll m=l+((r-l)>>1);
    ll cd=0,t=m;
    while(t){
      cd++;
      t/=10;
    }
    
    ll cs=0,p10=1;
    for(ll i=1;i<cd;i++){
      cs+=9*p10*i;
      p10*=10;
    }
    
    cs+=(m-p10+1)*cd;
    
    if(cs>=k)
      r=m-1;
    else{
      ans=m;
      sum=cs;
      l=m+1;
    }
  }
  
  ll rem=k-sum-1;
  string ss=to_string(ans+1);
  
  cout<<ss[rem]<<"\n";
}

int main(){
  ll t=1;
  cin>>t;
  
  while(t--)
    solver();
}