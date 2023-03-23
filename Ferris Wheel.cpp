#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n,x,cnt=0;
  cin>>n>>x;
  
  multiset<ll> st;
  for(ll i=0;i<n;i++){
    ll y;cin>>y;
    if(y<=x)
      st.insert(-y);
  }
  
  while(st.size()){
    auto itl=st.begin();
    ll val=-(*itl);
    st.erase(itl);
    auto itr=st.lower_bound(-(x-val));
    if(itr!=st.end())
      st.erase(itr);
    cnt++;
  }
  
  cout<<cnt<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}