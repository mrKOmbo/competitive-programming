/*
 * Problem: Min Stack
 * Platform: LC
 * Problem ID: 155
 * URL: https://leetcode.com/problems/min-stack/description/
 * Date: 2026-01-20
 * Compilation: g++ -std=c++17 -O2 155-Min-Stack.cpp -o programa && ./programa < input.txt > output.txt
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
class MinStack {
private: 
    stack<int> mys;
    stack<int> mins;
public:
    int min=INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        mys.push(val);

        if(mins.empty() || val <= mins.top()) {
            mins.push(val);
        } else {
            mins.push(mins.top());  
        }
    }
    
    void pop() {
        mys.pop();
        mins.pop();
    }
    
    int top() {
        return mys.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


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
