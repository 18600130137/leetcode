//
//  main.cpp
//  127. Word Ladder
//
//  Created by admin on 2019/4/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet;
        for(int i=0;i<wordList.size();i++){
            wordListSet.insert(wordList[i]);
        }
        queue<vector<string>> helper;
        helper.push({beginWord});
        
        int level=1;
        unordered_set<string> visited;
        while(!helper.empty()){
            vector<string> front=helper.front();
            helper.pop();
            if(level<front.size()){
                for(auto s:visited){
                    wordListSet.erase(s);
                }
                visited.clear();
                level=front.size();
            }
            string back=front.back();
            for(int i=0;i<back.size();i++){
                string  newWord(back);
                for(int j='a';j<='z';j++){
                    newWord[i]=j;
                    if(wordListSet.find(newWord)!=wordListSet.end()){
                        vector<string> newpath = front;
                        visited.insert(newWord);
                        newpath.push_back(newWord);
                        if(newWord==endWord){
                            return level+1;
                        }else{
                            helper.push(newpath);
                        }
                        
                    }
                    
                }
            }
            
            
        }
        
        return  0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordListV) {
        bool endExist=false;
        unordered_set<string> wordList;
        for(int i=0;i<wordListV.size();i++){
            if(wordListV[i]==endWord){
                endExist=true;
            }
            wordList.insert(wordListV[i]);
        }
        if(!endExist){
            return 0;
        }
        unordered_set<string> left;
        unordered_set<string> right;
        left.insert(beginWord);
        right.insert(endWord);
        int step=1;
        while(left.size()){
            step++;
            for(auto s:left){
                wordList.erase(s);
            }
            unordered_set<string> tmp;
            for(auto str:left){
                for(int i=0;i<str.size();i++){
                    string newStr(str);
                    for(int j='a';j<='z';j++){
                        newStr[i]=j;
                        if(wordList.find(newStr)!=wordList.end()){
                            if(right.find(newStr)!=right.end()){
                                return step;
                            }else{
                                tmp.insert(newStr);
                            }
                        }
                    }
                }
            }
            left=tmp.size()<right.size()?tmp:right;
            right=tmp.size()<right.size()?right:tmp;
        }
        
        return 0;
        
        
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<string> input={"hot","dot","dog","lot","log","cog"};
    Solution so=Solution();
    int ret=so.ladderLength("hit","cog", input);
    cout<<"The min len is:"<<ret<<endl;
    return 0;
}
