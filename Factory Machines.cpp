#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll check(vector<ll> &a, ll n, ll t, ll m)
{
    ll cnt = 0;
    for (auto e : a)
        cnt += m / e;
    return cnt >= t;
}

void solver()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = LONG_MAX, l = 0, r = a[0] * t;
    while (l <= r)
    {
        ll m = l + ((r - l) >> 1);
        if (check(a, n, t, m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << "\n";
}

int main()
{
    ll t = 1;
    // cin>>t;
    while (t--)
        solver();
}