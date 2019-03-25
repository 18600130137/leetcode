//
//  main.cpp
//  60. Permutation Sequence
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> helper1;
        for(int i=1;i<=n;i++){
            helper1.push_back(i);
        }
        vector<int> helper2(n);
        helper2[0]=1;
        for(int i=1;i<n;i++){
            helper2[i]=helper2[i-1]*i;
        }
        k--;
        stringstream s;
        for(int i=n-1;i>=0;i--){
            int idx=k/helper2[i];
            k=k%helper2[i];
            s<<helper1[idx];
            helper1.erase(helper1.begin()+idx);
        }
        
        return s.str();
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.getPermutation(3, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
