//
//  main.cpp
//  295. Find Median from Data Stream
//
//  Created by admin on 2019/7/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<long long> small,large;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size()<large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size()>large.size()?small.top():(small.top()-large.top())/2.0;
    }
};




int main(int argc, const char * argv[]) {
    MedianFinder *obj=new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double num1=obj->findMedian();
    cout<<"num1=="<<num1<<endl;
    obj->addNum(3);
    double num2=obj->findMedian();
    cout<<"num2=="<<num2<<endl;
    return 0;
}
