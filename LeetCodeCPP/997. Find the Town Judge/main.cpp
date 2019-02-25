//
//  main.cpp
//  997. Find the Town Judge
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0 && N==1){
            return 1;
        }
        
        unordered_map<int,int>  helper;
        for(auto item:trust){
            helper[item[1]]++;
            helper[item[0]]--;
        }
        
        for(auto item:helper){
            if(item.second==N-1){
                return item.first;
            }
        }
        
        return -1;
    }
};



int main(int argc, const char * argv[]) {
    int input1=4;
    vector<vector<int>> input2={{1,3},{1,4},{2,3},{2,4},{4,3}};
    Solution so=Solution();
    int ret=so.findJudge(input1, input2);
    cout<<"The  ret  is:"<<ret<<endl;
    return 0;
}
