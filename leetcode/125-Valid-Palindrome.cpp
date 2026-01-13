/*
 * Problem: Valid Palindrome
 * Platform: LC
 * Problem ID: 125
 * URL: https://leetcode.com/problems/valid-palindrome/description/
 * Date: 2026-01-12
 * Compilation: g++ -std=c++17 -O2 125-Valid-Palindrome.cpp -o programa && ./programa < input.txt > output.txt
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



bool solve(string s)
{
    int n = s.length(), i=0,j=n-1;
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
           while(i<j && !isalnum(s[j])){
                j--;
            }
            if(i<j){
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
               }
                i++;
                j--;
            }
        }
        return true;
}

int main()
{
    fastIO();
    int T; // cin >> T;
    string s="fasjfk>fsd";
    while (T--)
    {
        solve(s);
    }
    return 0;
}
