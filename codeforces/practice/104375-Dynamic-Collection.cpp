//104375 Dynamic Collection
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
    ll n, q; cin>>n>>q;
    int qa, li,ls;
    vector<int> ve(n);
    vector<int>::iterator low,up;
    input(ve);
    sort(ve.begin(),ve.end());
    for(int i=0;i<q;i++){
        cin>>qa>>li;
        if(qa==1){
            int pos = lower_bound(ve.begin(),ve.end(), li)-ve.begin();
            if(ve[pos] == li) continue;
            if(ve[n-1] < li) {
                ve.push_back(li);
                n++;
            } else {
                ve[pos] = li;
            }
        } else {
            cin>>ls;
            int cant = upper_bound(ve.begin(),ve.end(), ls) - lower_bound(ve.begin(),ve.end(), li); 
            cout<<cant<<endl;
        }
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
 