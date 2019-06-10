//
//  main.cpp
//  _1079. Letter Tile Possibilities
//
//  Created by admin on 2019/6/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dfs(vector<int> &helper){
        int count=0;
        for(int i=0;i<26;i++){
            if(helper[i]>0){
                helper[i]--;
                count++;
                count+=dfs(helper);
                helper[i]++;
            }
        }
        return count;
    }
    
public:
    int numTilePossibilities(string tiles) {
        vector<int> helper(26);
        for(int i=0;i<tiles.size();i++){
            helper[tiles[i]-'A']++;
        }
        
        return dfs(helper);
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.numTilePossibilities("AAABBC");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
