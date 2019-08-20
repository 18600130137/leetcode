//
//  main.cpp
//  341. Flatten Nested List Iterator
//
//  Created by admin on 2019/8/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
  class NestedInteger {
   public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single intege
     const vector<NestedInteger> &getList() const;
  };



class NestedIterator {
private:
    stack<NestedInteger>  helper;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1;i>=0;i--){
            helper.push(nestedList[i]);
        }
    }
    
    int next() {
        if(hasNext()){
            int top=helper.top().getInteger();
            helper.pop();
            return top;
        }
        return -1;
    }
    
    bool hasNext() {
        while(!helper.empty()){
            NestedInteger top=helper.top();
            if(top.isInteger()){
                return true;
            }
            helper.pop();
            vector<NestedInteger> nest=top.getList();
            for(int i=nest.size()-1;i>=0;i--){
                helper.push(nest[i]);
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
