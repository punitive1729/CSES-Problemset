#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solver()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll r = 0;
    for (ll i = n - 2; i >= 0; i--)
        r += a[i];
    if (r <= a[n - 1])
        cout << a[n - 1] * 2;
    else
        cout << r + a[n - 1];
    cout << "\n";
}

int main()
{
    ll t = 1;
    // cin>>t;
    while (t--)
        solver();
}