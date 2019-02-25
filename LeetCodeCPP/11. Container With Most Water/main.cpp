//
//  main.cpp
//  11. Container With Most Water
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int water=0;
        while(i<j){
            int h=min(height[i],height[j]);
            water=max(water,h*(j-i));
            while(height[i]<=h && i<j){
                i++;
            }
            while(height[j]<=h && i<j){
                j--;
            }
            
        }
        return water;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={1,8,6,2,5,4,8,3,7};
    Solution so=Solution();
    int area=so.maxArea(input);
    cout<<"The area is :"<<area<<endl;
    return 0;
}
