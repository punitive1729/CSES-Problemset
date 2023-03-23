#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

ll getCost(vector<ll>& a,ll k){
  ll ans=0;
  for(auto e:a)
    ans+=abs(e-k);
  return ans;
}

void solver(){
  ll n;
  cin>>n;
  
  ll mn=INT_MAX, mx=INT_MIN;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
    mx=max(mx,a[i]);
    mn=min(mn,a[i]);
  }
  
  ll l=mn,r=mx,ans=LONG_MAX;
  
  while(l<=r){
    ll m1=l+((r-l)/3);
    ll m2=r-((r-l)/3);
    
    ll c1=getCost(a,m1);
    ll c2=getCost(a,m2);
    
    ans=min({ans,c1,c2});
    
    if(c1<c2)
      r=m2-1;
    if(c2<c1)
      l=m1+1;
    if(c1==c2){
      l=m1+1;
      r=m2-1;
    }
  }
  
  cout<<ans<<"\n";
  
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}