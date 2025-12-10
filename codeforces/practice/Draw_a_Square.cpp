// Contest Codeforces Round 1009(Div.3_
//A. Draw a Square

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

#define all(v) (v).begin(), (v).end()
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (l == r && r == d && d == u) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main()
{
    fastIO();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
