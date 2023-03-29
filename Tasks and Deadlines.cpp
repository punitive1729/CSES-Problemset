#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll comp(vector<ll> &a, vector<ll> &b)
{
    if (a[0] < b[0])
        return 1;
    if (a[0] == b[0])
        return a[1] <= b[1];
    return 0;
}

void solver()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), comp);
    ll ans = 0, ct = 0;
    for (auto v : a)
    {
        ct += v[0];
        ans += v[1] - ct;
    }
    cout << ans;
}

int main()
{
    ll t = 1;
    // cin>>t;
    while (t--)
        solver();
}