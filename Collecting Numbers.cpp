#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

void solver(){
  ll n;
  cin>>n;

  unordered_map<int,int> mp;
  for(ll i=0;i<n;i++){
    ll x;
    cin>>x;
    mp[x]=i;
  }
  
  ll ans=0,curr=1;
  while(mp.size()){
    ll p=mp[curr];

    while(mp.size()){
      mp.erase(curr);
      if(curr==n){
        ans++;
        cout<<ans<<"\n";
        return;
      }
      curr++;
      ll next=mp[curr];
      
      if(next>p)
        p=next;
      else
        break;
      
    }
    
    ans++;
  }
  
  cout<<ans<<"\n";
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}