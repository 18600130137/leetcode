//
//  main.cpp
//  68. Text Justification
//
//  Created by admin on 2019/3/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> fullJustify1(vector<string>& words, int maxWidth) {
        int  words_count=words.size();
        int index=0;
        vector<string> ret;
        if(words_count==0){
            return  ret;
        }
        while(index<words_count){
            int word_len=words[index].length();
            int i=index+1;
            while(i<words_count){
                if(word_len+words[i].length()+1>maxWidth){
                    break;
                }
                word_len+=words[i].length()+1;
                i++;
            }
            int  realWords_len=0;
            for(int j=index;j<i;j++){
                realWords_len+=words[j].length();
            }
            int space_count=i-index-1;
            
            string tmp;
            if(i!=words_count){
                if(space_count!=0){
                    int *space_arr =new int[space_count];
                    int space_left=maxWidth-realWords_len;
                    int space_average=space_left/space_count;
                    int more_space=space_left%space_count;
                    for(int j=0;j<space_count;j++){
                        if(j<more_space){
                            space_arr[j]=space_average+1;
                        }else{
                            space_arr[j]=space_average;
                        }
                    }
                    for(int j=index,k=0;j<i-1,k<space_count;j++,k++){
                        tmp+=words[j];
                        tmp+=string(space_arr[k],' ');
                        // for(int d=0;d<space_arr[k];d++){
                        //     tmp+=" ";
                        // }
                    }
                    tmp+=words[i-1];
                }else{
                    tmp+=words[index];
                    while(tmp.length()<maxWidth){
                        tmp+=" ";
                    }
                }
            }else{
                for(int j=index;j<i-1;j++){
                    tmp+=words[j]+" ";
                }
                tmp+=words[i-1];
                while(tmp.length()<maxWidth){
                    tmp+=" ";
                }
                
            }
            ret.push_back(tmp);
            index=i;
        }
        
        return  ret;
        
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int m=words.size();
        vector<string> ret;
        for(int i=0,k,l;i<m;i+=k){
            for(k=0,l=0;i+k<m && l+words[i+k].size()<=maxWidth-k;k++){
                l+=words[i+k].size();
            }
            string tmp=words[i];
            for(int j=1;j<k;j++){
                if(i+k>=m) {
                    tmp+=' ';
                }else{
                    tmp+=string((maxWidth-l)/(k-1)+(j>(maxWidth-l)%(k-1)?0:1),' ');
                }
                tmp+=words[i+j];
            }
            while(tmp.size()<maxWidth){
                tmp.push_back(' ');
            }
            ret.push_back(tmp);
        }
        
        
        return  ret;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    Solution so=Solution();
    vector<string> ret=so.fullJustify(words, 16);
    for(auto s:ret){
        cout<<s<<endl;
    }
    return 0;
}
