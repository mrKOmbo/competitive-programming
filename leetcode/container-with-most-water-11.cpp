/*
 * Problem: 11
 * Platform: LC
 * Problem ID: container-with-most-water
 * URL: https://leetcode.com/problems/container-with-most-water/description/
 * Date: 2026-01-12
 * Compilation: g++ -std=c++17 -O2 container-with-most-water-11.cpp -o programa && ./programa < input.txt > output.txt
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



void solve(vector<int>& height){
    int i=0,j=height.size()-1, mx=0;
    while(i<j){
            if(height[i]>height[j]){
                mx=max(mx,(j-i)*height[j]);
                j--;
            } else {
                mx=max(mx,(j-i)*height[i]);
                i++;
            }
    }
    return mx;
}

int main()
{
    fastIO();
    int T; // cin >> T;
    vector<int> a= {1,8,6,2,5,4,8,3,7};
    while (T--)
    {
        solve(a);
    }
    return 0;
}
