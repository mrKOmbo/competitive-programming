//283932 Packing Rectangle
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

bool opr(ll w,ll h, ll n,ll v){
    ll t=v/w;
    t*=(v/h);
    return t>=n;
}

void solve(){
    ll w,h,n; cin>>w>>h>>n;
    ll high=1,low=0,m,ant=-1;
    while(!opr(w,h,n,high)){
        high*=2;
    }
    while(low<=high){
        m=(low+high)/2;
        if(opr(w,h,n,m)){
            ant=m;
            high=m-1;
        } else {
            low=m+1;
        }
    }
    cout<<ant<<endl;
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
