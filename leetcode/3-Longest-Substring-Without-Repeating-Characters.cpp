/*
 * Problem: Longest Substring Without Repeating Characters
 * Platform: LC
 * Problem ID: 3
 * URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * Date: 2026-01-14
 * Compilation: g++ -std=c++17 -O2 3-Longest-Substring-Without-Repeating-Characters.cpp -o programa && ./programa < input.txt > output.txt
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



int lengthOfLongestSubstring(string s) {
        unordered_set<char> window; 
        int l=0, maxi=0;
        for(int r=0;r<s.length();r++){
            while(window.count(s[r])>0){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            maxi=max(maxi, r-l+1);
        }
        return maxi;
}

int main()
{
    fastIO();
    int T; // cin >> T;
    while (T--)
    {
        lengthOfLongestSubstring("fasd");
    }
    return 0;
}
