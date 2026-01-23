/*
 * Problem: Path Sum
 * Platform: LC
 * Problem ID: 112
 * URL: https://leetcode.com/problems/path-sum/description/
 * Date: 2026-01-23
 * Compilation: g++ -std=c++17 -O2 112-Path-Sum.cpp -o programa && ./programa < input.txt > output.txt
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        if(!root->left && !root->right) {
            return root->val == targetSum;
        }

        int newTarget=targetSum-root->val;
        return hasPathSum(root->left, newTarget) || 
               hasPathSum(root->right, newTarget);
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
