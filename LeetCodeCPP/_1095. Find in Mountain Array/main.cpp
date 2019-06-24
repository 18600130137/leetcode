//
//  main.cpp
//  _1095. Find in Mountain Array
//
//  Created by admin on 2019/6/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 */
 class MountainArray {
    private:
     vector<int> info;
     
    public:
     MountainArray(vector<int> &input){
         info=input;
     }
     
     int get(int index){
         if(index<info.size()){
             return info[index];
         }
         return -1;
     }
     
     int length(){
         return info.size();
     }
  };


class Solution {
private:
    int  search(MountainArray &mountainArr,int start,int end,int target,bool asc=true){
        while(start<=end){
            int mid=(start+end)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if( (mountainArr.get(mid)<target && asc) || (mountainArr.get(mid)>target && !asc)){
                start=mid+1;
            }else{
                end=mid-1;
            }
            
            
        }
        return -1;
    }
    
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left=0,right=mountainArr.length()-1;
        while(left<right){
            int m=(left+right)/2;
            if(mountainArr.get(m)<mountainArr.get(m+1)){
                left=m+1;
            }else{
                right=m;
            }
        }
        //cout<<"left==="<<left<<endl;
        int ret=search(mountainArr,0,left,target,true);
        return ret!=-1?ret:search(mountainArr,left+1,mountainArr.length()-1,target,false);
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,3,1};
    MountainArray arr=MountainArray(input);
    Solution so=Solution();
    int ret=so.findInMountainArray(5, arr);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
