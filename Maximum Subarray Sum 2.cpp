#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,ans=LONG_MIN,l,r;
  cin>>n>>l>>r;
  
  if(l>r)
    swap(l,r);
  
  vector<ll> a(n+1),cs(n+1,0);
  for(ll i=1;i<=n;i++)
    cin>>a[i];
  
  for(ll i=1;i<=n;i++)
    cs[i]=cs[i-1]+a[i];
    
  deque<ll> q;
  q.push_back(0);
  map<ll,ll> mp;
  mp[0]++;
  
  for(ll i=l;i<=n;i++){
    while(q.size() and (i-q.front())>r){
      ll l=q.front();
      q.pop_front();
      if(mp[cs[l]]==1)
        mp.erase(cs[l]);
      else
        mp[cs[l]]--;
    }
    
    while(1){
      ll next=q.back()+1;
      if((i-next)<l)
        break;
      q.push_back(next);
      mp[cs[next]]++;
    }
    
    auto it=mp.begin();
    ans=max(ans,cs[i]-it->first);
  }
  
  cout<<ans<<"\n";
}