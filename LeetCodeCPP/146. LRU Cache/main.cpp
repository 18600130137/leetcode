//
//  main.cpp
//  146. LRU Cache
//
//  Created by admin on 2019/5/9.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <unordered_map>
using namespace std;



struct DLinkedNode{
    int key;
    int value;
    DLinkedNode *pre;
    DLinkedNode *next;
};


class LRUCache {
private:
    int cap=0;
    int count=0;
    DLinkedNode *head;
    DLinkedNode *tail;
    unordered_map<int,DLinkedNode*> helper;
    
    void  addNode(DLinkedNode *node){
        node->pre=head;
        node->next=head->next;
        head->next->pre=node;
        head->next=node;
    }
    
    void  removeNode(DLinkedNode *node){
        DLinkedNode *pre=node->pre;
        DLinkedNode *next=node->next;
        pre->next=next;
        next->pre=pre;
    }
    
    void moveToHead(DLinkedNode *node){
        removeNode(node);
        addNode(node);
    }
    
    
    DLinkedNode* popTail(){
        DLinkedNode * res=tail->pre;
        removeNode(res);
        return res;
    }
    
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->pre=NULL;
        head->next=tail;
        tail->pre=head;
        tail->next=NULL;
    }
    

    int get(int key) {
        if(!helper.count(key)){
            return -1;
        }
        DLinkedNode *node=helper[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(helper.count(key)){
            DLinkedNode *node=helper[key];
            node->value=value;
            moveToHead(node);
        }else{
            DLinkedNode *add=new DLinkedNode();
            add->key=key;
            add->value=value;
            addNode(add);
            helper[key]=add;
            count++;
            if(count>cap){
                DLinkedNode *tail=popTail();
                helper.erase(tail->key);
                count--;
            }
            
        }
    }
};


int main(int argc, const char * argv[]) {
    LRUCache cach=LRUCache(2);
    cach.put(1, 1);
    cach.put(2,2);
    cout<<"get(1)"<<cach.get(1)<<endl;
    cach.put(3, 3);
    cout<<"get(2)"<<cach.get(2)<<endl;
    cach.put(4, 4);
     cout<<"get(1)"<<cach.get(1)<<endl;
     cout<<"get(3)"<<cach.get(3)<<endl;
     cout<<"get(4)"<<cach.get(4)<<endl;
    return 0;
}
