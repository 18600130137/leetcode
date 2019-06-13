//
//  main.cpp
//  211. Add and Search Word - Data structure design
//
//  Created by admin on 2019/6/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class TrieNode{
public:
    TrieNode* next[26];
    bool  isLast;
    
    TrieNode(){
        isLast=false;
        memset(next,NULL,sizeof(next));
    }
};

class WordDictionary {
private:
    TrieNode * root;
    
    bool  match(const char* word,int index,TrieNode *cur,int len){
        if(len==index){
            return cur->isLast;
        }
        if(word[index]!='.'){
            return cur->next[word[index]-'a']!=NULL && match(word,index+1,cur->next[word[index]-'a'],len);
        }else{
            for(int i=0;i<26;i++){
                if(cur->next[i]!=NULL && match(word,index+1,cur->next[i],len)){
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur=root;
        for(auto c:word){
            if(!cur->next[c-'a']){
                cur->next[c-'a']=new TrieNode();
            }
            cur=cur->next[c-'a'];
        }
        cur->isLast=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(word.c_str(),0,root,word.size());
    }
};

int main(int argc, const char * argv[]) {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    bool param_2 = obj->search("b..");
    cout<<"The result is:"<<param_2<<endl;
    return 0;
}
