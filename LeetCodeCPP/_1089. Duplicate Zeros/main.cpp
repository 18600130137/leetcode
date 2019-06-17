//
//  main.cpp
//  _1089. Duplicate Zeros
//
//  Created by admin on 2019/6/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0,sh=0,m=arr.size();
        for(i=0;i+sh<m;i++){
            sh+=(arr[i]==0);
        }
        //cout<<i<<" "<<sh<<endl;
        for(i=i-1;sh>0;i--){
            if(i+sh<m){
                arr[i+sh]=arr[i];
            }
            if(arr[i]==0){
                arr[i+ --sh]=0;
            }
            
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> input={1,0,2,3,0,4,5,0};
    Solution so=Solution();
    so.duplicateZeros(input);
    for(auto i:input){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
