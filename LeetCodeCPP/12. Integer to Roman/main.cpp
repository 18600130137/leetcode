//
//  main.cpp
//  12. Integer to Roman
//
//  Created by admin on 2019/2/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string>  grade4={"","M","MM","MMM"};
        vector<string>  grade3={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string>  grade2={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string>  grade1={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        return grade4[num/1000]+grade3[num%1000/100]+grade2[num%100/10]+grade1[num%10];
    }
    
    
    string intToRoman1(int num) {
        vector<int>  grades={1000,500,100,50,10,5,1};
        vector<string> names={"M","D","C","L","X","V","I"};
        int m=names.size();
        string ret="";
        for(int i=0;i<m;i+=2){
            if(num>=grades[i]){
                int cur=num/grades[i];
                if(cur>0 && cur<=3){
                    while(cur){
                        ret+=names[i];
                        cur--;
                    }
                }else if(cur==4){
                    ret+=names[i]+names[i-1];
                }else if(cur==5){
                    ret+=names[i-1];
                }else if(cur>5 && cur<=8){
                    ret+=names[i-1];
                    cur-=5;
                    while(cur){
                        ret+=names[i];
                        cur--;
                    }
                }else{
                    ret+=names[i]+names[i-2];
                }
                num%=grades[i];
            }
        }
        return ret;
        
    }
};



int main(int argc, const char * argv[]) {
    Solution  so=Solution();
    string ret=so.intToRoman1(1234);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
