#include <bits/stdc++.h>
//#include <iostream>

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

void solve(){
	long long x, y, a;
        cin >> x >> y >> a;
        const long long sum = x + y;
        const long long n = a / sum;
        const long long rem = a - n * sum;
        cout << (rem >= x ? "YES\n" : "NO\n");
}

int main()
{
    fastIO();
    int T;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
