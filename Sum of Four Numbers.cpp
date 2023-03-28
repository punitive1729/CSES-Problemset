#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n,x;
  cin>>n>>x;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  if(n<4){
    cout<<"IMPOSSIBLE\n";
    return;
  }
  
  unordered_map<ll,queue<vector<ll>>> s;
  
  for(ll i=1;i<n;i++)
    for(ll j=i+1;j<n;j++)
      s[a[i]+a[j]].push({i+1,j+1});
  
  for(ll i=1;i<n;i++){
    for(ll j=i+1;j<n;j++){
      if(s[a[i]+a[j]].size()==1)
        s.erase(a[i]+a[j]);
      else
        s[a[i]+a[j]].pop();
    }
    for(ll j=i-1;j>=0;j--){
      ll p=a[i]+a[j];
      ll r=x-p;
      auto it=s.find(r);
      if(it!=s.end()){
        cout<<j+1<<" "<<i+1<<" "<<it->second.front()[0]<<" "<<it->second.front()[1]<<"\n";
        return;
      }
    }
  }
  cout<<"IMPOSSIBLE\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}