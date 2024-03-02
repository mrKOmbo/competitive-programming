//1932C LR-remainders 
#include <bits/stdc++.h>
using namespace std;

// Variables
typedef long long ll;
typedef unsigned long long  ull;
typedef long double ld;

// Funciones
#define sz(x) (int)x.size()
#define fr(i, n) for (int i = 0; i < n; i++)
#define input(v) for (auto &it : v) \
                      cin >> it;
#define output(v) for (auto &it : v) \
                      cout << it <<" ";

void fastIO()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int n,m,l=0,r; cin>>n>>m;
    vector<int> ve(n);
    vector<ll> rest(n); 
    string s;
    input(ve);
    cin>>s;
    r=n-1;
    for(int i=0;i<n-1;i++){
        if(s[i]=='L'){
            l++;
        } else {
            r--;
        }
    }
    rest[n-1]=ve[l]%m;
    for(int i=n-2;i>=0;i--){
        if(s[i]=='L'){
			l--;
			rest[i] = (rest[i+1]*ve[l])%m;
		}else{
			r++;
			rest[i] = rest[i+1]*ve[r]%m;
		}
    }
    output(rest);
	cout<<endl;
}

int main()
{
    fastIO();
    int t = 1; cin>>t;
    fr(i, t)
    {
        solve();
    }

    return 0;
}
