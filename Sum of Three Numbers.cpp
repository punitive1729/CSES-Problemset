#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n,x;cin>>n>>x;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) 
    cin>>a[i];
  map<ll,queue<ll>> p,s;
  p[a[0]].push(1);
  
  for(ll i=1;i<n;i++)
    s[a[i]].push(i+1);
    
  ll m=n>>1;
  for(ll i=1;i<n;i++){
    if(s[a[i]].size()==1)
      s.erase(a[i]);
    else
      s[a[i]].pop();
    if(i<m){
      for(auto e:p){
        ll cs=a[i]+e.first;
        auto it=s.find(x-cs);
        if(it!=s.end()){
          cout<<e.second.front()<<" "<<(i+1)<<" "<<it->second.front()<<"\n";
          return;
        }
      }
    }
    else{
      for(auto e:s){
        ll cs=a[i]+e.first;
        auto it=p.find(x-cs);
        if(it!=p.end()){
          cout<<it->second.front()<<" "<<(i+1)<<" "<<e.second.front()<<"\n";
          return;
        }
      }
    }
    p[a[i]].push(i+1);
  }
  cout<<"IMPOSSIBLE\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}