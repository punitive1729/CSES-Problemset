#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,k;
  cin>>n>>k;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  ll l=0,cnt=0;
  unordered_map<ll,ll> mp;
  
  for(ll i=0;i<n;i++){
    mp[a[i]]++;
    while(mp.size()>k){
      if(mp[a[l]]==1)
        mp.erase(a[l]);
      else
        mp[a[l]]--;
      ++l;
    }
    cnt+=(i-l+1);
  }
  cout<<cnt<<"\n";
}