//
//  main.cpp
//  _1093. Statistics from a Large Sample
//
//  Created by admin on 2019/6/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int m=count.size();
        //min and max
        double min_=0,max_=0;
        for(int i=0;i<m;i++){
            if(count[i]){
                min_=i;
                break;
            }
        }
        for(int i=m-1;i>=0;i--){
            if(count[i]){
                max_=i;
                break;
            }
        }
        
        //mean and mode
        double mean_=0,mode_=0,mode_value=0,sum_=0;
        int count_=0;
        for(int i=0;i<m;i++){
            if(count[i]){
                sum_+=i*count[i];
                count_+=count[i];
                if(count[i]>mode_value){
                    mode_value=count[i];
                    mode_=i;
                }
            }
        }
        mean_=sum_/count_;
        
        //median
        int mid1=(count_+1)/2,mid2=(count_+2)/2;
        //cout<<"mid1=="<<mid1<<" "<<mid2<<endl;
        double num1=-1,num2=-1;
        int acc=0;
        for(int i=0;i<m;i++){
            if(count[i]){
                acc+=count[i];
                if(acc>=mid1 && num1==-1){
                    num1=i;
                }
                if(acc>=mid2){
                    num2=i;
                    break;
                }
            }
        }
        //cout<<num1<<" "<<num2<<endl;
        double median_=(num1+num2)/2;
        
        return {min_,max_,mean_,median_,mode_};
        
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Solution so=Solution();
    vector<double> ret=so.sampleStats(input);
    cout<<"The ret is:"<<endl;
    for(auto  d:ret){
        cout<<d<<" ";
    }
    cout<<endl;
    return 0;
}
