#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<unordered_map<ll,ll>> dp;
 
ll solve(int ind,vector<int>& a,ll d){
  if(ind>=(ll)a.size())
    return d;
  
  if(dp[ind].find(d)!=dp[ind].end())
    return dp[ind][d];
  
  return dp[ind][d]=min(solve(ind+1,a,d+a[ind]),solve(ind+1,a,abs(d-a[ind])));
}
 
void solver(){
  int n;cin>>n;
  vector<int> a(n);
  dp.resize(n+2);
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<solve(0,a,0);
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}