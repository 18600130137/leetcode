//
//  main.cpp
//  223. Rectangle Area
//
//  Created by admin on 2019/6/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int square1=(C-A)*(D-B);
        int square2=(G-E)*(H-F);
        
        int left=max(A,E);
        int right=max(min(C,G),left);
        int bottom=max(B,F);
        int top=max(bottom,min(D,H));
        return square1-(right-left)*(top-bottom)+square2;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    int ret=so.computeArea(A, B, C, D, E, F, G, H);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
