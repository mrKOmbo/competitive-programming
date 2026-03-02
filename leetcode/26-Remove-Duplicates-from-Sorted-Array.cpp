/*
 * Problem: Remove Duplicates from Sorted Array
 * Platform: LC
 * Problem ID: 26
 * URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * Date: 2026-03-02
 * Compilation: g++ -std=c++17 -O2 26-Remove-Duplicates-from-Sorted-Array.cpp -o programa && ./programa < input.txt > output.txt
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                nums[k]=nums[i];
                k++;
            }
        }
    
        return k;
    }
};

