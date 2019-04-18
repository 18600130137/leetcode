//
//  main.cpp
//  126. Word Ladder II
//
//  Created by admin on 2019/4/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    
    
public:
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>  ret;
        unordered_set<string> wordListSet;
        for(int i=0;i<wordList.size();i++){
            wordListSet.insert(wordList[i]);
        }
        //wordListSet.insert(endWord);
        queue<vector<string>> helper;
        helper.push({beginWord});
        
        int level=1;
        int minLevel=INT_MAX;
        unordered_set<string> visited;
        while(!helper.empty()){
            vector<string> front=helper.front();
            helper.pop();
            if(level<front.size()){
                for(auto s:visited){
                    wordListSet.erase(s);
                }
                visited.clear();
                if(level>minLevel){
                    break;
                }else{
                    level=front.size();
                }
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
                            minLevel=level;
                            ret.push_back(newpath);
                        }else{
                            helper.push(newpath);
                        }
                        
                    }
                    
                }
            }
            
            
        }
        
        return  ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<string> input={"hot","dot","dog","lot","log","cog"};
    Solution so=Solution();
    vector<vector<string>> ret=so.findLadders("hit","cog", input);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
