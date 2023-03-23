#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
void solver()
{
    ll n;
    cin >> n;
    ll p = 1;
    for (ll i = 1; i <= n; i++)
        p = (p << 1) % mod;
    cout << p << "\n";
}
 
int main()
{
    ll t = 1;
    // cin>>t;
 
    while (t--)
        solver();
}