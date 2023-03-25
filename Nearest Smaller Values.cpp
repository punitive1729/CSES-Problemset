#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

void solver()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  stack<ll> st;
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  cout << "0 ";
  st.push(0);
  for (ll i = 1; i < n; i++)
  {
    while (st.size() and a[st.top()] >= a[i])
      st.pop();
    if (st.size())
      cout << st.top() + 1 << " ";
    else
      cout << "0 ";
    st.push(i);
  }
}

int main()
{
  ll t = 1;
  // cin>>t;

  while (t--)
    solver();
}