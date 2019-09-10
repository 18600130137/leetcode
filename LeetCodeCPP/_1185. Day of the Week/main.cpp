//
//  main.cpp
//  _1185. Day of the Week
//
//  Created by admin on 2019/9/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const vector<string> weeks={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    
public:
    string dayOfTheWeek(int day, int month, int year) {
        if(month<3){
            month+=12;
            year-=1;
        }
        
        int index=(day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
        return weeks[index];
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.dayOfTheWeek(10,9, 2019);
    cout<<"The week is:"<<ret<<endl;
    return 0;
}
