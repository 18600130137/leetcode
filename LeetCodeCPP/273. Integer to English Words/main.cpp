//
//  main.cpp
//  273. Integer to English Words
//
//  Created by admin on 2019/7/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> Twentys={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string>  Tens={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> Thousands={"","Thousand","Million","Billion"};
    
    string helper(int num){
        if(num==0){
            return "";
        }else if(num<20){
            return Twentys[num]+" ";
        }else if(num<100){
            return Tens[num/10]+" "+helper(num%10);
        }else{
            return Twentys[num/100]+" Hundred "+helper(num%100);
        }
    }
    string  trim(string &input){
        if(input.empty()){
            return input;
        }
        input.erase(0,input.find_first_not_of(" "));
        input.erase(input.find_last_not_of(" ")+1);
        return input;
    }
    
    
public:
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        
        string ret="";
        int t_start=0;
        while(num>0){
            if(num%1000!=0){
                ret=helper(num%1000)+Thousands[t_start]+" "+ret;
            }
            num/=1000;
            t_start++;
        }
        return trim(ret);
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.numberToWords(50123);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
