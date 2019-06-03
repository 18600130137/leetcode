//
//  main.cpp
//  _1073. Adding Two Negabinary Numbers
//
//  Created by admin on 2019/6/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size(),n=arr2.size();
        int i=m-1,j=n-1;
        int carry=0;
        vector<int> ret;
        while(i>=0 || j>=0 || carry){
            if(i>=0)  carry+=arr1[i--];
            if(j>=0)  carry+=arr2[j--];
            ret.push_back(carry&1);
            carry=-(carry>>1);
        }
        while(ret.size()>1 && ret.back()==0){
            ret.pop_back();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input1={1,1,1,1,1};
    vector<int>  input2={1,0,1};
    Solution so=Solution();
    vector<int> ret=so.addNegabinary(input1, input2);
    cout<<"The ret is:";
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
