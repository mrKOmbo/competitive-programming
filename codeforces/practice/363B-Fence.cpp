// 363B - Fence 
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
    int n,k,v; cin>>n>>k;
    vector<int> sm(n+1);
    vector<pair<int,int>> ve;
    sm[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v;
        sm[i]=sm[i-1]+v;
    }

    for(int i=0;i<n-k+1;i++){
        ve.push_back(make_pair(sm[k+i]-sm[i],i));
    }
    cout<<min_element(ve.begin(),ve.end())->second+1<<endl;
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
 