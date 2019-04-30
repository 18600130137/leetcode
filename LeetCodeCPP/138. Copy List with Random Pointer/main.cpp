//
//  main.cpp
//  138. Copy List with Random Pointer
//
//  Created by admin on 2019/4/30.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;


// Definition for a Node.
 class Node {
     public:
     int val;
     Node* next;
     Node* random;
     
     Node() {}
     
     Node(int _val) {
         val=_val;
     }
     
     Node(int _val, Node* _next, Node* _random) {
     val = _val;
     next = _next;
     random = _random;
     }
 };

Node * buildNode(){
    Node * node1=new Node(1);
    Node * node2=new Node(2);
    node1->next=node2;
    node1->random=node2;
    node2->next=0;
    node2->random=node2;
    return node1;
}


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        
        //链生长
        Node* iter=head;
        while(iter){
            Node* copy=new Node();
            copy->val=iter->val;
            
            copy->next=iter->next;
            iter->next=copy;
            iter=copy->next;
        }
        
        //random生长
        iter=head;
        while(iter){
            if(iter->random){
                iter->next->random=iter->random->next;
            }else{
                iter->next->random=NULL;
            }
            iter=iter->next->next;
        }
        
        //拆链
        iter=head;
        Node *dummy=new Node();
        Node *dummyIter=dummy;
        while(iter){
            Node* tmp=iter->next->next;
            dummyIter->next=iter->next;
            dummyIter=dummyIter->next;
            iter->next=tmp;
            iter=tmp;
        }
        
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    Node *input=buildNode();
    Solution so=Solution();
    Node* copy=so.copyRandomList(input);
    while (copy) {
        cout<<"copy->val:"<<copy->val<<" copy->random->val:"<<copy->random->val<<endl;
        copy=copy->next;
    }
    
    return 0;
}
