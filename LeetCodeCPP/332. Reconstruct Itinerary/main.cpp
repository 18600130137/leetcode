//
//  main.cpp
//  332. Reconstruct Itinerary
//
//  Created by admin on 2019/8/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
//刀枪刺  优先级 全部车票>字典序
class Solution {
private:
    unordered_map<string, multiset<string>> targets;
    vector<string> route;
    
    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        cout<<"push==="<<airport<<endl;
        route.push_back(airport);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>> tickets) {
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
    
    
};


int main(int argc, const char * argv[]) {
    vector<vector<string>>  input={{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    Solution so=Solution();
    vector<string> ret=so.findItinerary(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
