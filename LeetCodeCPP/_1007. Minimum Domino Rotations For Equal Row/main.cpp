//
//  main.cpp
//  _1007. Minimum Domino Rotations For Equal Row
//
//  Created by admin on 2019/3/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int m=(int)A.size();
        for(int i=1;i<=6;i++){
            int c=0;
            for(int j=0;j<A.size();j++){
                if(A[j]==i or B[j]==i){
                    c++;
                }else{
                    break;
                }
            }
            if(c==m){
                return min(m-count(A.begin(),A.end(),i),m-count(B.begin(),B.end(),i));
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input1={2,1,2,4,2,2};
    vector<int> input2={5,2,6,2,3,2};
    Solution so=Solution();
    int ret=so.minDominoRotations(input1, input2);
    cout<<"The ret  is:"<<ret<<endl;
    return 0;
}
