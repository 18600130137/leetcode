//
//  main.cpp
//  _1154. Day of the Year
//
//  Created by admin on 2019/8/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
private:
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    int dayOfYear(string date) {
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8));
        if(month>2 && year%4==0 && (year%100!=0 || year%400==0)){
            day++;
        }
        while(--month>0){
            day+=days[month-1];
        }
        
        return day;
    }
};
int main(int argc, const char * argv[]) {
    string  date="2020-05-09";
    Solution so=Solution();
    int ret=so.dayOfYear(date);
    cout<<"The day  of the year is:"<<ret<<endl;
    return 0;
}
