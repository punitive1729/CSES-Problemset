#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

void solver(){
  ll n,x;
  cin>>n>>x;
  map<ll,ll> st;
  
  for(ll i=0;i<n;i++){
    ll y;cin>>y;
    if(st.find(x-y)!=st.end()){
      cout<<st[x-y]<<" "<<i+1;
      return;
    }
    st[y]=i+1;
  }
  cout<<"IMPOSSIBLE\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}