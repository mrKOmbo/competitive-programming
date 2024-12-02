/*  Contest: Educational Codeforces Round 172 (Rated for Div. 2)
    Problem: Game with Colored Marbles
*/
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
    int n, x, y = 0;
    cin >> n;
    unordered_map<int, int> ht;
    while (n--)
    {
        cin >> x;
        ht[x] += 1;
    }
    x = 0;
    for (auto a : ht)
    {
        if (a.second == 1)
        {
            x += 1;
        }
        else
        {
            y += 1;
        }
    }
    cout << round(x / 2.0) * 2 + y << endl;
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