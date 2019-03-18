//
//  main.cpp
//  _1012. Complement of Base 10 Integer
//
//  Created by admin on 2019/3/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int N) {
        int ret=1;
        while(ret<N){
            ret=ret*2+1;
        }
        return ret-N;
    }
};



int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.bitwiseComplement(65534);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
