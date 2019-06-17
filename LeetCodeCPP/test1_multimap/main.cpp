//
//  main.cpp
//  test1_multimap
//
//  Created by admin on 2019/6/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include<cstdio>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    multimap<int,int>  mm;
    mm.insert({5,1});
    mm.insert({1,3});
    mm.insert({10,4});
    mm.insert({2,1});
    for(auto  item:mm){
        cout<<item.first<<" ";
    }
    cout<<endl;
    return 0;
}
