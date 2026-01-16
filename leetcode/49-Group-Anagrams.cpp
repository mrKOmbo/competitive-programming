/*
 * Problem: Group Anagrams
 * Platform: LC
 * Problem ID: 49
 * URL: https://leetcode.com/problems/group-anagrams/description/
 * Date: 2026-01-16
 * Compilation: g++ -std=c++17 -O2 49-Group-Anagrams.cpp -o programa && ./programa < input.txt > output.txt
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mm;
        for(const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            
            mm[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& pair : mm) {
            result.push_back(pair.second);
        }
        return result;
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
