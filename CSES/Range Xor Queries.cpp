//Range Xor Queries
#include <bits/stdc++.h>

using namespace std;

// Variables
typedef long long int ll;
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
    int n,q,li,ls; cin>>n>>q;
    vector<int> ve(n),sm(n+1);
    sm.push_back(0);
    input(ve);
    sm[0]=0;
    for(int i=1;i<=n;i++){
        sm[i]=sm[i-1]^ve[i-1];
    }
    for(int i=0;i<q;i++){
        cin>>li>>ls;
        cout<<(sm[ls]^sm[li-1])<<endl;
    }    
}

int main()
{
    fastIO();
    int t = 1; //cin>>t;
    fr(i, t)
    {
        solve();
    }

    return 0;
}
 