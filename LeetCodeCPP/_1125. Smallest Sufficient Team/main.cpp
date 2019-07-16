//
//  main.cpp
//  _1125. Smallest Sufficient Team
//
//  Created by admin on 2019/7/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m=req_skills.size(),n=people.size();
        unordered_map<string,int>  code_skills;
        for(int i=0;i<m;i++){
            code_skills[req_skills[i]]=i;
        }
        map<int,vector<int>>  helper;
        helper[0]={};
        for(int i=0;i<n;i++){
            int new_bin=0;
            for(int j=0;j<people[i].size();j++){
                new_bin |= (1<<code_skills[people[i][j]]);
            }
            for(auto item=helper.begin();item!=helper.end();item++){
                int cur_bin=item->first | new_bin;
                if(helper.find(cur_bin)==helper.end() || helper[cur_bin].size()>item->second.size()+1){
                    helper[cur_bin]=item->second;
                    helper[cur_bin].push_back(i);
                }
            }
            
        }
        return helper[(1<<m)-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<string> input1={"java","nodejs","reactjs"};
    vector<vector<string>> input2={{"java"},{"nodejs"},{"nodejs","reactjs"}};
    Solution so=Solution();
    vector<int> ret= so.smallestSufficientTeam(input1, input2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    
    return 0;
}
