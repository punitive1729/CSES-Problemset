#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s,curr="";
vector<int> vis;
set<string> ans;

void solver(){
  if(curr.length()==s.length()){
    ans.insert(curr);
    return;
  }
  for(int i=0;i<s.length();++i){
    if(!vis[i]){
      vis[i]=1;
      curr+=s[i];
      solver();
      curr.pop_back();
      vis[i]=0;
    }
  }
}

int main(){
  ll t=1;
  //cin>>t;
  
  while(t--){
    cin>>s;
    vis.clear();
    vis.resize(10,0);
    solver();
    cout<<ans.size()<<"\n";
    for(auto e:ans)
      cout<<e<<"\n";
  }
}