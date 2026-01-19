/*
 * Problem: Subarray Sum Equals K
 * Platform: LC
 * Problem ID: 560
 * URL: https://leetcode.com/problems/subarray-sum-equals-k/description/
 * Date: 2026-01-19
 * Compilation: g++ -std=c++17 -O2 560-Subarray-Sum-Equals-K.cpp -o programa && ./programa < input.txt > output.txt
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        
        int currentSum = 0;
        int count = 0;
        
        for(int num : nums) {
            currentSum += num;
            
            // Buscar si existe (currentSum - k) en el map
            if(prefixSumCount.count(currentSum - k)) {
                count += prefixSumCount[currentSum - k];
            }
            
            prefixSumCount[currentSum]++;
        }
        
        return count;
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
