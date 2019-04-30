//
//  main.cpp
//  _1033. Moving Stones Until Consecutive
//
//  Created by admin on 2019/4/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> in={a,b,c};
        sort(in.begin(),in.end());
        int diffLeft=in[1]-in[0];
        int diffRight=in[2]-in[1];
        if((diffLeft==1)&&(diffRight==1)){
            return {0,0};
        }else if((diffLeft<=2)||(diffRight<=2)){
            return {1,diffLeft+diffRight-2};
        }else{
            return {2,diffLeft+diffRight-2};
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> ret=so.numMovesStones(1, 2, 5);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
