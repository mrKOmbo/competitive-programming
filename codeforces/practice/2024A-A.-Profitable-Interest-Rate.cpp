/*
 * Problem: A. Profitable Interest Rate
 * Platform: CF
 * Problem ID: 2024A
 * URL: https://codeforces.com/contest/2024/problem/A
 * Date: 2025-12-10
 * Compilation: g++ -std=c++17 -O2 2024A-A.-Profitable-Interest-Rate.cpp -o programa && ./programa < input.txt > output.txt
 */

#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Macros
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

// Loops
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) ROF(i, 0, n)

// Input/Output
#define input(v) for (auto &x : v) cin >> x
#define output(v) for (auto &x : v) cout << x << " "; cout << endl
#define debug(x) cerr << #x << " = " << x << endl

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = acos(-1);

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Useful functions
template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
T power(T a, T b, T mod = MOD) {
    T res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a,b; cin>>a>>b;
    if (a>=b){
        cout<<a<<endl;
    } else {
        ll r = 2*a -b;
        if(r> 0){
            cout<<r<<endl;
        } else {
            cout<<0<<endl;
        }
    }

}

int main() {
    fastIO();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}