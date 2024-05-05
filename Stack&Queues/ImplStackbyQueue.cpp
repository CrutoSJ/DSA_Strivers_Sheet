// #Question:-

// #Link-> https://leetcode.com/problems/implement-stack-using-queues/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    
    queue<int>q;
    
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};