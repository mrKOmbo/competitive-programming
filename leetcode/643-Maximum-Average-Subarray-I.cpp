/*
 * Problem: Maximum Average Subarray I
 * Platform: LC
 * Problem ID: 643
 * URL: https://leetcode.com/problems/maximum-average-subarray-i/description/
 * Date: 2026-01-14
 * Compilation: g++ -std=c++17 -O2 643-Maximum-Average-Subarray-I.cpp -o programa && ./programa < input.txt > output.txt
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



double findMaxAverage(vector<int>& nums, int k) {
        double s=0;
        for(int i=0;i<k;i++){
            s+=nums[i];
        }
        double maxSuma = s;

        for(int i = k; i < nums.size(); i++) {
            s = s - nums[i - k] + nums[i];
            maxSuma = max(maxSuma, s);
        }
        return maxSuma / k;
}

int main()
{
    fastIO();
    int T; // cin >> T;
    vector<int> a;
    while (T--)
    {
        findMaxAverage(a,1);
    }
    return 0;
}
