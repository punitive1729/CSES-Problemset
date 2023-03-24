#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll check(vector<ll> &a, ll s, ll k)
{
    ll cs = 0, cnt = 0;
    for (ll i = 0; i < a.size(); i++)
    {
        if ((cs + a[i]) > s)
        {
            cs = 0;
            cnt++;
        }
        cs += a[i];
    }
    cnt++;

    return cnt <= k;
}

void solver()
{
    ll l = INT_MIN, r = 0, n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    ll ans = r;
    while (l <= r)
    {
        ll m = l + ((r - l) >> 1);
        if (check(a, m, k))
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