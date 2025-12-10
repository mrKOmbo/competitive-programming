// A. Coin Transformation
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;

#define sz(x) (int)x.size()
#define fr(i, n) for (int i = 0; i < n; i++)
#define input(v)       \
    for (auto &it : v) \
        cin >> it;
#define output(v)      \
    for (auto &it : v) \
        cout << it << " ";

void fastIO()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    ll a;
    cin >> a;
    int count = 1;
    while (a > 3)
    {
        count *= 2;
        a /= 4;
    }
    cout << count << endl;
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}