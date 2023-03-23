#include <bits/stdc++.h>
using namespace std;
 
void solver(){
  string s;
  cin>>s;
  vector<int> cnt(30,0);
  for(auto c:s)
    cnt[c-'A']++;
  int cntOdd=0;
  for(int i=0;i<26;i++)
    cntOdd+=(cnt[i]&1);
  if(cntOdd>1){
    cout<<"NO SOLUTION";
    return;
  }
  string t;
  char middle='.';
  for(int i=0;i<26;i++){
    if(cnt[i]&1){
      middle='A'+i;
      cnt[i]--;
    }
    while(cnt[i]){
      cnt[i]-=2;
      t.push_back('A'+i);
    }
  }
  cout<<t;
  if(middle!='.')
    cout<<middle;
  reverse(t.begin(),t.end());
  cout<<t<<"\n";
}
 
int main(){
  int t=1;
  while(t--)
    solver();
}