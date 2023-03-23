#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n,k;
  cin>>n>>k;

  vector<vector<ll>> a;
  for(ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    a.push_back({x,y});
  }
  
  set<vector<ll>> st;
  sort(a.begin(),a.end());
  ll cnt=n;
  
  for(ll i=0;i<n;i++){
    while(st.size()){
      vector<ll> v=*st.begin();
      if(v[0]>a[i][0])
        break;
      st.erase(st.begin());
    }
    st.insert({a[i][1],i});
    
    while(st.size()>k){
      auto it=--st.end();
      vector<ll> v=*it;
      st.erase(it);
      cnt--;
    }
  }
  
  cout<<cnt<<"\n";
  
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}