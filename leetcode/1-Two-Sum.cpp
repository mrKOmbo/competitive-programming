/*
 * Problem: Two Sum
 * Platform: LC
 * Problem ID: 1
 * URL: https://leetcode.com/problems/two-sum/description/
 * Date: 2026-01-16
 * Compilation: g++ -std=c++17 -O2 1-Two-Sum.cpp -o programa && ./programa < input.txt > output.txt
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mm;
        for(int i=0;i<nums.size();i++){
            int res=target-nums[i];
            if(mm.find(res)!=mm.end()){
                return {mm[mm.find(res)->first],i};
            }
            mm[nums[i]]=i;
        }
        return{0,0};
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
