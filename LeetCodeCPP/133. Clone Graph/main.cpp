//
//  main.cpp
//  133. Clone Graph
//
//  Created by admin on 2019/4/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*
 // Definition for a Node.
*/
 class Node {

    public:
        int val;
        vector<Node*> neighbors;
        Node(int x) : val(x){}
 };

Node *buildNode(){
    Node* node1=new Node(1);
    Node* node2=new Node(2);
    Node* node3=new Node(3);
    Node* node4=new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node3);
    node4->neighbors.push_back(node1);
    return node1;
}


class Solution {
private:
    unordered_map<int,Node*> helper;
    
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        
        if(helper.find(node->val)!=helper.end()){
            return helper[node->val];
        }
        
        Node* copy=new Node(node->val);
        helper[copy->val]=copy;
        for(auto item:node->neighbors){
            copy->neighbors.push_back(cloneGraph(item));
        }
        return copy;
    }
};

int main(int argc, const char * argv[]) {
    Node *root=buildNode();
    Solution so=Solution();
    Node* newNode=so.cloneGraph(root);
    queue<Node*> helper;
    unordered_set<int> visited;
    helper.push(newNode);
    visited.insert(newNode->val);
    while(!helper.empty()){
        Node* front=helper.front();
        helper.pop();
        cout<<"front:"<<front->val<<endl;
        
        for(auto item:front->neighbors){
            if(visited.find(item->val)==visited.end()){
                helper.push(item);
                visited.insert(item->val);
            }
        }
    }
    
    
    return 0;
}
