#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll ans = 0, n, cnt = 0;
  string s;
  cin >> s;

  n = s.length();
  for (ll i = 0; i < n;)
  {
    ll curr = 0;
    char p = s[i];
    while (i < n and p == s[i])
    {
      curr++;
      i++;
    }
    ans = max(ans, curr);
  }
  cout << ans << "\n";
}