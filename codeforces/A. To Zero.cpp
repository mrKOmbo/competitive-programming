//A. To Zero
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
    int n,k;
    cin>>n>>k;
    int c=0;
    if(n%2==1)
    {
        n-=(k-(k%2==0));
        c++;
    }
    c+=(n+k-(k%2)-1)/(k-(k%2));
    cout<<c<<'\n';
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



