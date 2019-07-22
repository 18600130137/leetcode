//
//  main.cpp
//  _1130. Minimum Cost Tree From Leaf Values
//
//  Created by admin on 2019/7/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int m=arr.size();
        vector<int> stack={INT_MAX};
        int res=0;
        for(int i=0;i<m;i++){
            while(stack.back()<=arr[i]){
                int mid=stack.back();
                stack.pop_back();
                res+=mid*min(stack.back(),arr[i]);
            }
            stack.push_back(arr[i]);
        }
        for(int i=2;i<stack.size();i++){
            res+=stack[i-1]*stack[i];
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={6,2,4};
    Solution so=Solution();
    int ret=so.mctFromLeafValues(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
