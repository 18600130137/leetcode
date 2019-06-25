//
//  main.cpp
//  229. Majority Element II
//
//  Created by admin on 2019/6/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m=nums.size();
        int num1=0,num2=1,n1_count=0,n2_count=0;
        for(auto i:nums){
            if(i==num1){
                n1_count++;
            }else if(i==num2){
                n2_count++;
            }else if(n1_count==0){
                num1=i;
                n1_count++;
            }else if(n2_count==0){
                num2=i;
                n2_count++;
            }else{
                n1_count--;
                n2_count--;
            }
        }
        cout<<num1<<" "<<num2<<endl;
        n1_count=0,n2_count=0;
        for(auto i:nums){
            if(i==num1){
                n1_count++;
            }else if(i==num2){
                n2_count++;
            }
        }
        int thresh=m/3;
        vector<int> ret;
        if(n1_count>thresh){
            ret.push_back(num1);
        }
        if(n2_count>thresh){
            ret.push_back(num2);
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={1,1,1,3,3,2,2,2};
    Solution so=Solution();
    vector<int> ret=so.majorityElement(input);
    cout<<"The ret is:";
    for(auto  i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
