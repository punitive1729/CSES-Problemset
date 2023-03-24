#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
multiset<ll> lt,rt;

void insert(ll val){
  auto itl=--lt.end();
  auto itr=rt.begin();
  if(val<=*itr)
    lt.insert(val);
  else
    rt.insert(val);
}

void balance(){
  while(lt.size()<=rt.size()){
    auto itr=rt.begin();
    lt.insert(*itr);
    rt.erase(itr);
  }
  
  while((lt.size()-rt.size())>1){
    auto itl=--lt.end();
    rt.insert(*itl);
    lt.erase(itl);
  }
}

void erase(ll val){
  auto itl=lt.find(val);
  if(itl!=lt.end()){
    lt.erase(itl);
    return;
  }
  rt.erase(rt.find(val));
}

void solver(){
  ll n,k;
  cin>>n>>k;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  if(k==1){
    for(auto e:a)
      cout<<e<<" ";
    return;
  }
  
  if(k==2){
    for(ll i=1;i<n;i++)
      cout<<min(a[i],a[i-1])<<" ";
    return;
  }
  
  lt.insert(min(a[1],a[0]));
  rt.insert(max(a[1],a[0]));
  
  for(ll i=2;i<n;i++){
    insert(a[i]);
    balance();
    ll ls=lt.size(),rs=rt.size();
    if((ls+rs)==k){
      auto itl=--lt.end();
      cout<<*itl<<" ";
      erase(a[i-k+1]);
      balance();
    }
  }
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}