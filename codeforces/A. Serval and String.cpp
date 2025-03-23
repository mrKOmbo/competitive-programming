#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
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
	string s;
	cin>>n>>k>>s;
	string t=s;
	reverse(t.begin(),t.end());
	if(count(s.begin(),s.end(),s[0])==n)cout<<"NO"<<endl;
	else
	{
		if(k>0)cout<<"YES"<<endl;
		else 
		{
			if(s<t) cout<<"YES"<<endl;
			else cout<<"NO"<endl;
		}
	}
	return;
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
