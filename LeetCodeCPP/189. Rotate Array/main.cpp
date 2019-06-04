//
//  main.cpp
//  189. Rotate Array
//
//  Created by admin on 2019/6/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;





class Solution {
private:
    void func(vector<int> &nums, int k){
        std::rotate(nums.begin(), nums.begin() + (nums.size() - (k % (nums.size()))), nums.end());
    }
    
    void func1(vector<int> &nums, int k){
        int m=nums.size();
        k%=m;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        // int count=nums.size();
        // int K=k%count;
        // for(int i=0;i<K;i++){
        //     int tmp=nums.erase(nums.begin()+count-1);
        //     nums.insert(nums.begin(),tmp);
        // }
        func(nums,k);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6,7};
    Solution so=Solution();
    so.rotate(input, 3);
    for(auto item:input){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}
