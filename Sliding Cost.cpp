#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
multiset<ll> lt,rt;
ll ls,rs;

void insert(ll val){
  auto itl=--lt.end();
  auto itr=rt.begin();
  if(val<=*itr){
    lt.insert(val);
    ls+=val;
  }
  else{
    rt.insert(val);
    rs+=val;
  }
}

void balance(){
  while(lt.size()<=rt.size()){
    auto itr=rt.begin();
    lt.insert(*itr);
    ls+=*itr;
    rs-=*itr;
    rt.erase(itr);
  }
  
  while((lt.size()-rt.size())>1){
    auto itl=--lt.end();
    rt.insert(*itl);
    rs+=*itl;
    ls-=*itl;
    lt.erase(itl);
  }
}

void erase(ll val){
  auto itl=lt.find(val);
  if(itl!=lt.end()){
    lt.erase(itl);
    ls-=val;
    return;
  }
  rs-=val;
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
      cout<<0<<" ";
    return;
  }
  
  if(k==2){
    for(ll i=1;i<n;i++)
      cout<<abs(a[i]-a[i-1])<<" ";
    return;
  }
  
  lt.insert(min(a[1],a[0]));
  ls=min(a[1],a[0]);
  
  rt.insert(max(a[1],a[0]));
  rs=max(a[1],a[0]);
  
  for(ll i=2;i<n;i++){
    insert(a[i]);
    balance();
    ll lss=lt.size(),rss=rt.size();
    if((lss+rss)==k){
      ll med=*(--lt.end());
      ll ans=med*lss-ls + rs-med*rss;
      cout<<ans<<" ";
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