//
//  main.cpp
//  _1138. Alphabet Board Path
//
//  Created by admin on 2019/7/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        int lastX=0,lastY=0;
        string res;
        for(auto  c:target){
            int curX=(c-'a')%5,curY=(c-'a')/5;
            res+=string(max(0,lastX-curX),'L')+string(max(0,curY-lastY),'D')+
            string(max(0,lastY-curY),'U')+string(max(0,curX-lastX),'R')+"!";
            lastX=curX;
            lastY=curY;
        }
        
        return res;
        
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.alphabetBoardPath("leet");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
