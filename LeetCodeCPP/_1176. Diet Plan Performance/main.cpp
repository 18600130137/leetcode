//
//  main.cpp
//  _1176. Diet Plan Performance
//
//  Created by admin on 2019/9/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dietPlanPerformance1(vector<int>& calories, int k, int lower, int upper) {
        int m=calories.size();
        int accScore=0;
        int accValue=0;
        for(int i=0;i<k;i++){
            accValue+=calories[i];
        }
        
        if(accValue<lower){
            accScore--;
        }else if(accValue>upper){
            accScore++;
        }
        
        for(int i=k;i<m;i++){
            accValue+=calories[i];
            accValue-=calories[i-k];
            if(accValue<lower){
                accScore--;
            }else if(accValue>upper){
                accScore++;
            }
        }
        
        return accScore;
    }
    
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int m=calories.size();
        int accScore=0;
        int accValue=0;
        
        for(int i=0;i<m;i++){
            accValue+=calories[i];
            if(i>=k){
                accValue-=calories[i-k];
            }
            if(i>=k-1){
                if(accValue<lower){
                    accScore--;
                }else if(accValue>upper){
                    accScore++;
                }
            }
            
        }
        
        return accScore;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5};
    Solution so=Solution();
    int ret=so.dietPlanPerformance(input, 1, 3, 3);
    cout<<"The  ret score is:"<<ret<<endl;
    return 0;
}
