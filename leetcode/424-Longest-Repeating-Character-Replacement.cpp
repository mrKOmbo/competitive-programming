/*
 * Problem: Longest Repeating Character Replacement
 * Platform: LC
 * Problem ID: 424
 * URL: https://leetcode.com/problems/longest-repeating-character-replacement/description/
 * Date: 2026-01-15
 * Compilation: g++ -std=c++17 -O2 424-Longest-Repeating-Character-Replacement.cpp -o programa && ./programa < input.txt > output.txt
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
    int characterReplacement(string s, int k) {
        int maxFreq=0, left=0, maxLen=0;
        int freq[26]={0};

        for(int right=0;right<s.length();right++){
            freq[s[right] - 'A']++;
            maxFreq=max(maxFreq, freq[s[right]-'A']);
            int changes= (right-left+1)-maxFreq;

            while(changes> k){
                freq[s[left]-'A']--;
                left++;
                changes=(right-left+1)-maxFreq;
            }
            maxLen=max(maxLen, right-left+1);
        }
        return maxLen;
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
