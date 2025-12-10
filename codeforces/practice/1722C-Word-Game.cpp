//1722C Word Game
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

void fastIO()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int n,p=0; cin>>n;
    string s[3][n];
    map<string,int> mp;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
            mp[s[i][j]]++;
        }
    }
    for(int i=0;i<3;i++){
        p=0;
        for(int j=0;j<n;j++){
            if(mp[s[i][j]]==1){
                p+=3;
            } else if(mp[s[i][j]]==2) {
                p++;
            }
        }
        cout<<p<<" ";
    }
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
