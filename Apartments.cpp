#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> f;
void solver(){
  ll n,m,k;
  cin>>n>>m>>k;
  
  vector<ll> a(n),b(m);
  
  for(ll i=0;i<n;i++) 
    cin>>a[i];
    
  sort(a.begin(),a.end());
  
  for(ll i=0;i<m;i++) 
    cin>>b[i];
    
  sort(b.begin(),b.end());
  
  ll i=0,j=0,cnt=0;
  while(i<n and j<m){
    while(j<m and b[j]<a[i] and abs(b[j]-a[i])>k)
      j++;
    
    while(i<n and b[j]>a[i] and abs(b[j]-a[i])>k)
      i++;
    
    if(i<n and j<m and abs(a[i]-b[j])<=k){
      cnt++;
      i++;
      j++;
    }
    
  }
  
  cout<<cnt<<"\n";
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--)
    solver();
}