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
	int n;
        cin >> n;
        vector<int> digits(n);
        
        for (int i = 0; i < n; i++) {
            cin >> digits[i];
        }
        
       int freq[10] = {0};
       int answer = 0;
        
       for (int i = 0; i < n; i++) {
            freq[digits[i]]++;
            if (freq[0] >= 3 && freq[1] >= 1 && freq[2] >= 2 && freq[3] >= 1 && freq[5] >= 1) {
                answer = i + 1;
                break;
            }
       }
        
        cout << answer << endl;
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
