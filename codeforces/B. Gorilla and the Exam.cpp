// B. Gorilla and the Exam
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
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
    int n, k;
    cin >> n >> k;

    map<int, int> freq_map; // Cambiado de unordered_map a map
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        freq_map[a]++;
    }

    multiset<int> freq_set; // Usamos multiset para ordenar automáticamente
    for (const auto &pair : freq_map)
    {
        freq_set.insert(pair.second);
    }

    int remaining = freq_set.size();
    for (int count : freq_set)
    {
        if (k >= count)
        {
            remaining--;
            k -= count;
        }
        else
        {
            break;
        }
    }

    cout << max(1, remaining) << endl;
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