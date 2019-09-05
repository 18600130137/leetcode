//
//  main.cpp
//  _1172. Dinner Plate Stacks
//
//  Created by admin on 2019/8/30.
//  Copyright © 2019年 liu. All rights reserved.
//
			
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class DinnerPlates {
private:
    vector<stack<int>> base;
    set<int>  unfull;
    int my_capacity;
    
    
public:
    DinnerPlates(int capacity) {
        my_capacity=capacity;
    }
    
    void push(int val) {
        if(unfull.empty()){
            base.push_back(stack<int>());
            unfull.insert(base.size()-1);
        }
        int h=*unfull.begin();
        base[h].push(val);
        if(base[h].size()==my_capacity){
            unfull.erase(unfull.begin());
        }
    }
    
    int pop() {
        if(base.empty()){
            return -1;
        }
        auto top=base.back().top();
        base.back().pop();
        while(!base.empty() && base.back().empty()){
            unfull.erase(base.size()-1);
            base.pop_back();
        }
        if(!base.empty() && base.back().size()<my_capacity){
            unfull.insert(base.size()-1);
        }
        return top;
    }
    
    int popAtStack(int index) {
        if(base.size()<=index || base[index].empty()){
            return -1;
        }
        if(index==base.size()-1){
            return pop();
        }
        int top=base[index].top();
        base[index].pop();
        unfull.insert(index);
        return top;
    }
};

int main(int argc, const char * argv[]) {
    DinnerPlates* obj = new DinnerPlates(2);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    cout<<obj->popAtStack(0)<<endl;
    obj->push(20);
    obj->push(21);
    cout<<obj->popAtStack(0)<<endl;
    cout<<obj->popAtStack(2)<<endl;
    return 0;
}
