#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solver(){
  ll n;cin>>n;
  vector<vector<ll>> a;
  set<ll> st;
  while(n--){
    ll x,y;
    cin>>x>>y;
    st.insert(x);
    st.insert(y);
    a.push_back({min(x,y),max(x,y)});
  }
  ll rank=0;
  unordered_map<ll,ll> mp;
  for(auto e:st){
    ++rank;
    mp[e]=rank;
  }
  vector<ll> ans(rank+10,0);
  for(auto v:a){
    ans[mp[v[0]]]++;
    ans[mp[v[1]]+1]--;
  }
  ll cnt=0;
  for(ll i=1;i<ans.size();i++){
    ans[i]+=ans[i-1];
    cnt=max(cnt,ans[i]);
  }
  cout<<cnt<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
  
}