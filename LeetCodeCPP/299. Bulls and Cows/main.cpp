//
//  main.cpp
//  299. Bulls and Cows
//
//  Created by admin on 2019/7/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int countA=0;
        int countB=0;
        int m=secret.size();
        vector<int> helper(10,0);
        for(int i=0;i<m;i++){
            if(secret[i]==guess[i]){
                countA++;
            }else{
                int num1=secret[i]-'0',num2=guess[i]-'0';
                if(helper[num1]<0) countB++;
                if(helper[num2]>0) countB++;
                helper[num1]++;
                helper[num2]--;
            }
        }
        return to_string(countA)+"A"+to_string(countB)+"B";
        
        
    }
};


int main(int argc, const char * argv[]) {
    string s1="1807";
    string s2="7810";
    Solution so=Solution();
    string ret=so.getHint(s1, s2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
