#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll comp(vector<ll>& a,vector<ll>& b){
  if(a[0]<b[0])
    return 1;
  if(a[0]==b[0])
    return a[1]>b[1];
  return 0;
}

void solver(){
  ll n;cin>>n;
  vector<vector<ll>> a;
  for(ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    a.push_back({min(x,y),max(x,y),i});
  }
  
  sort(a.begin(),a.end(),comp);
  set<ll> st;
  st.insert(a[0][1]);
  
  vector<vector<ll>> ans(2,vector<ll>(n,0));
  
  for(ll i=1;i<n;i++){
    auto it=st.lower_bound(a[i][1]);
    ans[1][a[i][2]]=(it!=st.end());
    st.insert(a[i][1]);
  }
  
  map<ll,vector<ll>> mp;
  mp[a[0][1]].push_back(a[0][2]);
  
  for(ll i=1;i<n;i++){
    while(st.size()){
      auto it=mp.lower_bound(a[i][1]);
      if(it==mp.end())
        break;
      for(auto ind:it->second)
        ans[0][ind]=1;
      mp.erase(it);
    }
    mp[a[i][1]].push_back(a[i][2]);
  }
  
  for(ll i=0;i<2;i++){
    for(ll j=0;j<n;j++)
      cout<<ans[i][j]<<" ";
    cout<<"\n";
  }
  
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}