#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solver(){
  ll n;
  cin>>n;
  
  vector<vector<ll>> a;
  set<ll> st;
  
  for(ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    a.push_back({x,y});
    st.insert(x);
    st.insert(y);
  }
  
  ll rank=1,ans=0;
  unordered_map<ll,ll> mp;
  
  for(auto e:st)
    mp[e]=rank++;
  
  vector<ll> cnt(rank+2,0);
  vector<vector<ll>> occ(rank+2),leaving(rank+2);
  
  for(ll i=0;i<n;i++){
    a[i][0]=mp[a[i][0]];
    a[i][1]=mp[a[i][1]];
    
    cnt[a[i][0]]++;
    cnt[a[i][1]+1]--;
    
    occ[a[i][0]].push_back(i);
    leaving[a[i][1]+1].push_back(i);
  }
  
  for(ll i=1;i<cnt.size();i++){
    cnt[i]+=cnt[i-1];
    ans=max(ans,cnt[i]);
  }
  
  queue<ll> roomsAvailable;
  for(ll i=1;i<=ans;i++)
    roomsAvailable.push(i);
  
  vector<ll> occupied(a.size()+10,-1);
  vector<ll> f(a.size(),-1);
  
  for(ll i=1;i<=rank;i++){
    ll roomGiven;
    for(auto person:leaving[i]){
      roomGiven=occupied[person];
      roomsAvailable.push(roomGiven);
    }
    for(auto person:occ[i]){
      roomGiven=roomsAvailable.front();
      roomsAvailable.pop();
      f[person]=roomGiven;
      occupied[person]=roomGiven;
    }
  }
  
  cout<<ans<<"\n";
  for(auto e:f)
    cout<<e<<" ";
  cout<<"\n";
  
  
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}