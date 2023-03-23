#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll r,c,ans;
  cin>>r>>c;
  if(r==c and c==1){
    cout<<"1\n";
    return;
  }
  if(r>=c){
    if(r&1){
      ll s=(r-1)*(r-1)+1;
      ans=s+c-1;
    }
    else{
      ll s=r*r;
      ans=s-(c-1);
    }
  }
  else{
    if(c&1){
      ll s=c*c;
      ans=s-(r-1);
    }
    else{
      ll s=(c-1)*(c-1)+1;
      ans=s+r-1;
    }
  }
  cout<<ans<<"\n";
}

int main(){
  ll t=1;
  cin>>t;
  
  while(t--)
    solver();
}