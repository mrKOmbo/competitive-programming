/*
 * Problem: Minimum Size Subarray Sum
 * Platform: LC
 * Problem ID: 209
 * URL: https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * Date: 2026-01-15
 * Compilation: g++ -std=c++17 -O2 209-Minimum-Size-Subarray-Sum.cpp -o programa && ./programa < input.txt > output.txt
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,sum=0;
        int minLen = INT_MAX;
        for(int j=0;j<nums.size();j++){

            sum+=nums[j];
            while(sum>=target){
                minLen=min(minLen, j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
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
