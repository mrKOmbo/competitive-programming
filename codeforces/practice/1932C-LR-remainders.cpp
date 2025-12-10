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
            if(ve[0]>li){
                ve[0]=li;
            } else {
                cout<<i<<endl;
                low=upper_bound(ve.begin(),ve.end(),li);
                if(!(ve[(low-ve.begin())-1]==li)){
                    ve[low - ve.begin()] = li;
                }
            }
        } else {
            cin>>ls;
            low=lower_bound(ve.begin(),ve.end(),li);
            //cout<<"El menor"<<(low-ve.begin())<<endl;
            up=lower_bound(ve.begin(),ve.end(),ls+1);
            //cout<<"El mayor"<<(up-ve.begin())<<endl;
            cout<<(up-ve.begin())-(low-ve.begin())<<endl;
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
 