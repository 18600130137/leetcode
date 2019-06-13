//
//  main.cpp
//  212. Word Search II
//
//  Created by admin on 2019/6/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode{
public:
    TrieNode *next[26];
    string word;
    
    TrieNode(){
        word="";
        memset(next,NULL,sizeof(next));
    }
};


class Solution {
private:
    TrieNode * buildTrieNode(vector<string>& words){
        TrieNode* root=new TrieNode();
        for(string word:words){
            TrieNode* cur=root;
            for(char c:word){
                if(cur->next[c-'a']==NULL){
                    cur->next[c-'a']=new TrieNode();
                }
                cur=cur->next[c-'a'];
            }
            cur->word=word;
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board,int i,int j,TrieNode *cur,vector<string> &ret){
        const char  c=board[i][j];
        if(c=='#' || cur->next[c-'a']==NULL){
            return;
        }
        cur=cur->next[c-'a'];
        if(cur->word!=""){  //防止重复
            ret.push_back(cur->word);
            cur->word="";
        }
        
        board[i][j]='#';
        if(i>0)  dfs(board,i-1,j,cur,ret);
        if(j>0)  dfs(board,i,j-1,cur,ret);
        if(i<board.size()-1) dfs(board,i+1,j,cur,ret);
        if(j<board[0].size()-1) dfs(board,i,j+1,cur,ret);
        board[i][j]=c;
    }
    
    
public:
    vector<string> findWords(vector<vector<char>>& board,vector<string> &words) {
        int m=board.size();
        if(m==0){
            return {};
        }
        int n=board[0].size();
        if(n==0){
            return {};
        }
        TrieNode* root=buildTrieNode(words);
        vector<string> ret;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root,ret);
            }
        }
        return ret;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<char>>  input1={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> input2={"oath","pea","eat","rain"};
    Solution so=Solution();
    vector<string> ret=so.findWords(input1, input2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
