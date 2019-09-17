//
//  main.cpp
//  _1191. K-Concatenation Maximum Sum
//
//  Created by admin on 2019/9/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int MODE=1000000007;
    
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int m=arr.size();
        long long oneSum=0;
        for(auto  a:arr){
            oneSum+=a;
        }
        
        long long ans=0;
        
        if(oneSum>0 && k>=2){
            long long leftMaxAcc=0;
            long long leftCur=0;
            for(auto a:arr){
                leftCur+=a;
                leftMaxAcc=max(leftMaxAcc,leftCur);
            }
            
            long long rightMaxAcc=0;
            long long rightCur=0;
            for(int i=m-1;i>=0;i--){
                rightCur+=arr[i];
                rightMaxAcc=max(rightMaxAcc,rightCur);
            }
            
            ans=max(ans,leftMaxAcc+rightMaxAcc+(k-2)*oneSum);
        }
        
        if(k>1){
            for(int i=0;i<m;i++){
                arr.push_back(arr[i]);
            }
        }
        
        long long curAcc=0;
        for(auto a:arr){
            curAcc+=a;
            ans=max(ans,curAcc);
            if(curAcc<0){
                curAcc=0;
            }
        }
        
        return ans%MODE;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2};
    Solution so=Solution();
    int ret=so.kConcatenationMaxSum(input, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
