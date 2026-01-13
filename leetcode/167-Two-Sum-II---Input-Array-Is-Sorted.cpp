/*
 * Problem: Two Sum II - Input Array Is Sorted
 * Platform: LC
 * Problem ID: 167
 * URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * Date: 2026-01-13
 * Compilation: g++ -std=c++17 -O2 167-Two-Sum-II---Input-Array-Is-Sorted.cpp -o programa && ./programa < input.txt > output.txt
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



vector<int> solve(vector<int>& numbers, int target)
{
        int i=0,j=numbers.size()-1;
        vector<int> rslt={-1,-1};
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum==target) {
                return {i+1,j+1};
            }
            if(sum>target){
                j--;
            } else if (sum<target){
                i++;
            }
        } 
        return rslt;
}

int main()
{
    fastIO();
    int T; // cin >> T;
    vector<int> b = {1,23,2};
    while (T--)
    {
        vector<int> b = solve(b,9);
    }
    return 0;
}
