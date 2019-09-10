//
//  main.cpp
//  _1184. Distance Between Bus Stops
//
//  Created by admin on 2019/9/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int m=distance.size();
        int way1=0,way2=0;
        int left=min(start,destination);
        int right=max(start,destination);
        
        for(int i=0;i<m;i++){
            if(i>=left && i<right){
                way1+=distance[i];
            }else{
                way2+=distance[i];
            }
        }
        return min(way1,way2);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4};
    Solution so=Solution();
    int ret=so.distanceBetweenBusStops(input, 0, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
