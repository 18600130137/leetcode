//
//  main.cpp
//  42. Trapping Rain Water
//
//  Created by admin on 2019/3/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int m=height.size();
        if(m==0){
            return 0;
        }
        int i=0,j=m-1;
        int ret=0;
        int left_max=max(0,height[i]),right_max=max(0,height[j]);
        while(i<j){
            if(height[i]<=height[j]){
                ret+=left_max-height[i];
                i++;
                left_max=max(left_max,height[i]);
            }else{
                ret+=right_max-height[j];
                j--;
                right_max=max(right_max,height[j]);
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution so=Solution();
    int ret=so.trap(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
