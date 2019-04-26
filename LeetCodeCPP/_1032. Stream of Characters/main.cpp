//
//  main.cpp
//  _1032. Stream of Characters
//
//  Created by admin on 2019/4/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;



class StreamChecker {
    
    struct TrieNode{
        bool isEnd=false;
        unordered_map<char,TrieNode*> next;
    };
    
private:
    TrieNode* root=new TrieNode();
    string buff;
    
    void insert(string word){
        TrieNode* tmp=root;
        for(int i=word.size()-1;i>=0;i--){
            if(tmp->next.find(word[i])==tmp->next.end()){
                tmp->next[word[i]]=new TrieNode();
            }
            tmp=tmp->next[word[i]];
        }
        tmp->isEnd=true;
    }
    
    
public:
    StreamChecker(vector<string>& words) {
        for(auto item:words){
            insert(item);
        }
    }
    
    bool query(char letter) {
        buff+=letter;
        TrieNode* tmp=root;
        for(int i=buff.size()-1;i>=0;i--){
            if(tmp->next.find(buff[i])==tmp->next.end()){
                return false;
            }else if(tmp->next[buff[i]]->isEnd){
                return true;
            }
            tmp=tmp->next[buff[i]];
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main(int argc, const char * argv[]) {
    vector<string> input1={"cd","f","kl"};
    string input2="abcdefghijkl";
    StreamChecker sc=StreamChecker(input1);
    for(auto c:input2){
        cout<<(sc.query(c)?"True":"False")<<" ";
    }
    cout<<endl;
    return 0;
}
