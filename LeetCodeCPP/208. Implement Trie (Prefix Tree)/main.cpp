//
//  main.cpp
//  208. Implement Trie (Prefix Tree)
//
//  Created by admin on 2019/6/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
    
public:
    TrieNode *next[26];
    bool isTail=false;
    
    TrieNode(bool aIsTail=false){
        memset(next,0,sizeof(next));
        isTail=aIsTail;
    }
};


class Trie {
private:
    TrieNode *root;
    
    TrieNode * find(string target){
        TrieNode *p=root;
        for(int i=0;i<target.size() && p!=NULL;i++){
            p=p->next[target[i]-'a'];
        }
        return p;
    }
    
    
public:
    
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a']=new TrieNode();
            }
            p=p->next[word[i]-'a'];
        }
        p->isTail=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *f=find(word);
        
        return f!=NULL && f->isTail;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *f=find(prefix);
        return f!=NULL;
    }
};
int main(int argc, const char * argv[]) {
    Trie * trie=new Trie();
    trie->insert("apple");
    bool ret=trie->search("apple");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
