#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver(){
  ll n;
  cin>>n;
  
  vector<ll> a(n);
  for(ll i=0;i<n;i++)
    cin>>a[i];
  
  multiset<ll> st;
  
  for(auto e:a){
    auto it=st.lower_bound(e+1);
    if(it==st.end())
      st.insert(e);
    else{
      st.erase(it);
      st.insert(e);
    }
  }

  cout<<st.size()<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();//<<"\n";
}