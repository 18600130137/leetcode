//
//  main.cpp
//  _1020. Partition Array Into Three Parts With Equal Sum
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(),A.end(),0);
        if(sum%3!=0){
            return false;
        }
        int target=sum/3;
        int left=0;
        bool first=false,second=false;
        for(int   i:A){
            left+=i;
            if(left==target){
                first=true;
            }
            if(first && left==2*target){
                second=true;
                break;
            }
        }
        return first&&second;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={0,2,1,-6,6,-7,9,1,2,0,1};
    Solution so=Solution();
    bool ret=so.canThreePartsEqualSum(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
