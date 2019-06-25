//
//  main.cpp
//  232. Implement Queue using Stacks
//
//  Created by admin on 2019/6/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int>  st;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(st.empty()){
            st.push(x);
            return;
        }
        int top=st.top();
        st.pop();
        push(x);
        st.push(top);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!empty()){
            int top=st.top();
            st.pop();
            return top;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() {
        if(!empty()){
            return st.top();
        }
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

int main(int argc, const char * argv[]) {
     MyQueue obj = MyQueue();
     obj.push(5);
     int param_2 = obj.pop();
     int param_3 = obj.peek();
     bool param_4 = obj.empty();
     cout<<param_2<<" "<<param_3<<" "<<param_4<<endl;
     return 0;
}
