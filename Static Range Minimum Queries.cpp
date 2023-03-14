#include <bits/stdc++.h>
using namespace std;
#define ll long long

void constructTree(vector<ll>& st,vector<ll>& a,ll tind,ll tl,ll tr){
  if(tl>tr)
    return;
  if(tl==tr){
    st[tind]=a[tl];
    return;
  }
  ll left=tind<<1,tm=tl+((tr-tl)>>1);
  constructTree(st,a,left,tl,tm);
  constructTree(st,a,left|1,tm+1,tr);
  st[tind]=min(st[left],st[left|1]);
}

ll query(vector<ll>& st,ll tind,ll tl,ll tr,ll ql,ll qr){
  if(tl>tr or ql>qr or qr<tl or ql>tr)
    return INT_MAX;
  
  if(ql<=tl and tr<=qr)
    return st[tind];
    
  ll left=tind<<1,tm=tl+((tr-tl)>>1);
  return min(query(st,left,tl,tm,ql,qr),query(st,left|1,tm+1,tr,ql,qr));
}

void solver(){
  ll n,q;
  cin>>n>>q;
  
  vector<ll> a(n+1,0);
  for(ll i=1;i<=n;i++)
    cin>>a[i];
  
  vector<ll> st(5*n+10,INT_MAX);
  constructTree(st,a,1,1,n);
  
  while(q--){
    ll l,r;
    cin>>l>>r;
    
    cout<<query(st,1,1,n,l,r)<<"\n";
  }
  
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}