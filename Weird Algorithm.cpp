#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll n;
  cin >> n;

  while (1)
  {
    cout << n << " ";
    if (n == 1)
      break;
    if (n & 1)
      n = n * 3 + 1;
    else
      n >>= 1;
  }
}