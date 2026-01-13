/*
 * Problem: 3Sum
 * Platform: LC
 * Problem ID: 15
 * URL: https://leetcode.com/problems/3sum/description/
 * Date: 2026-01-13
 * Compilation: g++ -std=c++17 -O2 15-3Sum.cpp -o programa && ./programa < input.txt > output.txt
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



vector<vector<int>> solve(vector<int>& nums)
{
        sort(nums.begin(),nums.end());
        vector<vector<int>> rst;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1, r=nums.size()-1;
            if (i>0 && nums[i]==nums[i-1]) continue;
            while(l<r){
                int s = nums[i]+nums[l]+nums[r];
                if(s==0){
                    rst.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                } else if(s<0){
                    l++;
                } else{
                    r--;
                }
            }
        }
        return rst;
}

int main()
{
    fastIO();
    int T; // cin >> T;
    vector<int> b={1,12,3};
    while (T--)
    {
        vector<vector<int>> b= solve(b);
    }
    return 0;
}
