//1598A Computer Game
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
   int n; cin>>n;
   string s,x; cin>>s>>x;
   for(int i=0;i<n;i++){
        if(s[i]=='1'&&x[i]=='1'){
            cout<<"NO"<<endl;
            return ;
        }
   }
   cout<<"YES"<<endl;
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
