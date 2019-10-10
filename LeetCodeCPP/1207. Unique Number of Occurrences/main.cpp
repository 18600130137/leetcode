//
//  main.cpp
//  1207. Unique Number of Occurrences
//
//  Created by admin on 2019/10/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> helper1;
        for(int i=0;i<arr.size();i++){
            helper1[arr[i]]++;
        }
        unordered_set<int>   helper2;
        for(auto  item:helper1){
            if(helper2.count(item.second)>0){
                return false;
            }
            helper2.insert(item.second);
        }
        return true;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,2,1,1,3};
    Solution so=Solution();
    int ret=so.uniqueOccurrences(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
