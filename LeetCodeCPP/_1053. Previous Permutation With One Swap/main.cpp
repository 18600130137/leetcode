//
//  main.cpp
//  _1053. Previous Permutation With One Swap
//
//  Created by admin on 2019/5/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), left = n - 2, right = n - 1;
        while (left >= 0  && A[left] <= A[left + 1]) left--;
        if (left < 0) return A;
        while (A[left] <= A[right]) right--;
        while (A[right - 1] == A[right]) right--;
        swap(A[left], A[right]);
        return A;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={3,1,1,3};
    Solution so=Solution();
    vector<int> ret=so.prevPermOpt1(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
