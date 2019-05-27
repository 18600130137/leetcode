//
//  main.cpp
//  _1052. Grumpy Bookstore Owner
//
//  Created by admin on 2019/5/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int X) {
        int base=0,add=0,m_add=0;
        
        for(int i=0;i<c.size();i++){
            base+=g[i]?0:c[i];
            add+=g[i]?c[i]:0;
            if(i>=X){
                add-=g[i-X]?c[i-X]:0;
            }
            m_add=max(m_add,add);
        }
        
        return base+m_add;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input1={1,0,1,2,1,1,7,5};
    vector<int> input2={0,1,0,1,0,1,0,1};
    Solution so=Solution();
    int ret=so.maxSatisfied(input1, input2, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
