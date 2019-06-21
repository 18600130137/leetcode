//
//  main.cpp
//  225. Implement Stack using Queues
//
//  Created by admin on 2019/6/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int>  q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    int  size(){
        return  q.size();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(empty()){
            q.push(x);
        }else{
            q.push(x);
            for(int i=0;i<size()-1;i++){
                int tmp=q.front();
                q.pop();
                q.push(tmp);
            }
            
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top=q.front();
        q.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return  q.empty();
    }
};
int main(int argc, const char * argv[]) {
    MyStack obj =MyStack();
    obj.push(1);
    obj.push(2);
    int param_2 = obj.pop();
    int param_3 = obj.top();
    bool param_4 = obj.empty();
    cout<<param_2<<" "<<param_3<<" "<<param_4<<endl;
    return 0;
}
