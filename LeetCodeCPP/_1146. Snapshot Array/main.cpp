//
//  main.cpp
//  _1146. Snapshot Array
//
//  Created by admin on 2019/8/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class SnapshotArray {
private:
    vector<vector<pair<int,int>>> helper;
    int snap_id=0;
    int len=0;
public:
    SnapshotArray(int length) {
        len=length;
        helper.resize(len);
    }
    
    void set(int index, int val) {
        if(index<len){
            if(helper[index].empty() || helper[index].back().first!=snap_id){
                helper[index].push_back(make_pair(snap_id,val));
            }else{
                helper[index].back().second=val;
            }
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        //cout<<index<<" "<<snap_id<<" "<<len<<endl;
        if(index>=len){
            return -1;
        }
        auto iter=upper_bound(helper[index].begin(),helper[index].end(),make_pair(snap_id,INT_MAX));
        return begin(helper[index])==iter?0:prev(iter)->second;
    }
};


int main(int argc, const char * argv[]) {
    SnapshotArray* obj = new SnapshotArray(3);
    obj->set(0,5);
    obj->snap();
    obj->set(0,6);
    int ret = obj->get(0,0);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
