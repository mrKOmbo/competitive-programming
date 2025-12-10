/*  Contest: Educational Codeforces Round 172 (Rated for Div. 2)
    Problem: A. Greedy Monocarp
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k, x;
    cin >> n >> k;
    vector<int> ms;

    while (n--)
    {
        cin >> x;
        ms.push_back(x);
    }

    sort(ms.begin(), ms.end(), greater<int>());

    x = 0;
    for (auto g : ms)
    {
        x += g;

        if (x > k)
        {
            x = x - g;
            cout << k - x << endl;
            return;
        }

        if (x == k)
        {
            cout << 0 << endl;
            return;
        }
    }
    cout << k - x << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
