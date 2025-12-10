// A. MEX Table
// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <cmath>
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
    int n, m, mx;
    cin >> n >> m;
    mx = max(n, m);
    mx++;
    cout << mx << endl;
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