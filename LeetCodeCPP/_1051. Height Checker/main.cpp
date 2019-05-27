//
//  main.cpp
//  _1051. Height Checker
//
//  Created by admin on 2019/5/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count=0;
        vector<int> ch(heights);
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(ch[i]!=heights[i]){
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,1,4,2,1,3};
    Solution so=Solution();
    int wrongCount=so.heightChecker(input);
    cout<<"The place wrong count is:"<<wrongCount<<endl;
    return 0;
}
