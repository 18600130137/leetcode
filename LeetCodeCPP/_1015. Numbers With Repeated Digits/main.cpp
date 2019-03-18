//
//  main.cpp
//  _1015. Numbers With Repeated Digits
//
//  Created by admin on 2019/3/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    int A(int m,int n){
        return n==0? 1:A(m,n-1)*(m-n+1);
    }
    
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> L;
        for(int x=N+1;x>0;x/=10){
            L.insert(L.begin(),x%10);
        }
        for(int i:L){
            cout<<i<<" ";
        }
        cout<<endl;
        int res=0,n=L.size();
        cout<<"The n is:"<<n<<endl;
        for(int i=1;i<n;i++){
            res+=9*A(9,i-1);
            cout<<"The res is:"<<res<<endl;
        }
        
        set<int>  seen;
        for(int i=0;i<n;++i){
            for(int j=i>0? 0:1;j<L[i];++j){
                cout<<"i=="<<i<<"  j=="<<j<<" L[i]=="<<L[i]<<endl;
                if(seen.count(j)==0){
                    res+=A(9-i,n-i-1);
                }
            }
            if(seen.count(L[i])>0)break;
            seen.insert(L[i]);
        }
        return N-res;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.numDupDigitsAtMostN(8865);
    cout<<endl<<"The ret is:"<<ret<<endl;
    return 0;
}
