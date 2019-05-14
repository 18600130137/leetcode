//
//  main.cpp
//  155. Min Stack
//
//  Created by admin on 2019/5/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    int min_=INT_MAX;
    stack<int> s1;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(x<=min_){
            s1.push(min_);
            min_=x;
        }
        s1.push(x);
    }
    
    void pop() {
        if(getMin()==top())  {
            s1.pop();
            min_=s1.top();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return  min_;
    }
};


int main(int argc, const char * argv[]) {
    MinStack s=MinStack();
    s.push(-2);
    s.push(0);
    s.push(-1);
    cout<<"getMIN:"<<s.getMin()<<endl;
    cout<<"Top:"<<s.top()<<endl;
    s.pop();
    cout<<"getMin:"<<s.getMin()<<endl;
    return 0;
}
