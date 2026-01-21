/*
 * Problem: Implement Queue using Stacks
 * Platform: LC
 * Problem ID: 232
 * URL: https://leetcode.com/problems/implement-queue-using-stacks/description/
 * Date: 2026-01-21
 * Compilation: g++ -std=c++17 -O2 232-Implement-Queue-using-Stacks.cpp -o programa && ./programa < input.txt > output.txt
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

class MyQueue {
private:
    stack<int> mq;
    stack<int> temp;
    stack<int> temp2;
public:
    MyQueue() {
    }

    void recal(){
        while(!mq.empty()) {
            temp.push(mq.top()); 
            mq.pop();            
        }
    }
    
    void push(int x) {
        mq.push(x);
    }
    
    int pop() {
        if(temp.empty()){
            recal();
        }
        int v=temp.top();
        temp.pop();
        return v;
    }
    
    int peek() {
        if(temp.empty()){
            recal();
        }
        return temp.top();
    }
    
    bool empty() {
        return mq.empty() && temp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
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
