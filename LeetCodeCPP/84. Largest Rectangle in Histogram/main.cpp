//
//  main.cpp
//  84. Largest Rectangle in Histogram
//
//  Created by admin on 2019/4/2.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> helper;
        int m=heights.size();
        int max_area=0;
        for(int i=0;i<=m;){
            int height=(i==m?0:heights[i]);
            if(helper.empty() || height>=heights[helper.top()]){
                helper.push(i);
                i++;
            }else{
                int lastTop=helper.top();
                helper.pop();
                max_area=max(max_area,heights[lastTop]*(helper.empty()?i:i-helper.top()-1));
                //cout<<max_area<<endl;
                
            }
        }
        
        
        return max_area;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,1,5,6,2,3};
    Solution so=Solution();
    int area=so.largestRectangleArea(input);
    cout<<"The area is:"<<area<<endl;
    return 0;
}
