/*
 * Problem: Top K Frequent Elements
 * Platform: LC
 * Problem ID: 347
 * URL: https://leetcode.com/problems/top-k-frequent-elements/description/
 * Date: 2026-01-19
 * Compilation: g++ -std=c++17 -O2 347-Top-K-Frequent-Elements.cpp -o programa && ./programa < input.txt > output.txt
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(const auto num : nums){
            freqMap[num]++;
        }
        vector<pair<int, int>> freqVec;
        for(const auto& [num, freq] : freqMap) {
            freqVec.push_back({num, freq});
        }
        sort(freqVec.begin(), freqVec.end(), 
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second > b.second;  // Descendente
             });
        vector<int> temp;
        for(int i=0;i<k;i++){
            temp.push_back(freqVec[i].first);
        }
        return temp;

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
