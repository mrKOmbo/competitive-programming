/*
 * Problem: Valid Parentheses
 * Platform: LC
 * Problem ID: 20
 * URL: https://leetcode.com/problems/valid-parentheses/description/
 * Date: 2026-01-20
 * Compilation: g++ -std=c++17 -O2 20-Valid-Parentheses.cpp -o programa && ./programa < input.txt > output.txt
 */

//#include <bits/stdc++.h>
#include <iostream>

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

class Solution {
public:
    bool isValid(string s) {
        stack<char> in;

        for(const auto& a: s){
            if(a=='('||a=='['||a=='{'){
                in.push(a);
            } else {
                if(in.empty()){
                    return false;
                }

                char s = in.top();
                in.pop();

                if(a==')'&&s!='(') return false;
                if(a=='}'&&s!='{') return false;
                if(a==']'&&s!='[') return false;
            }
        }
        return in.empty();
    }
};

void solve()
{
    
}

int main()
{
    fastIO();
    int T; // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
