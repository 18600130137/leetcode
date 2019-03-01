//
//  main.cpp
//  23. Merge k Sorted Lists
//
//  Created by admin on 2019/3/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


struct mycompare
{
    bool operator() (ListNode* a,ListNode* b)
    {
        return a->val > b->val; //小顶堆
    }
};


class Solution {
private:
    ListNode* merger(ListNode* n1,ListNode* n2){
        if(!n1){
            return n2;
        }
        if(!n2){
            return n1;
        }
        
        
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        dummy->next=n1;
        while(n1 && n2){
            if(n1->val<=n2->val){
                n1=n1->next;
            }else{
                ListNode* tmp1=cur->next;
                cur->next=n2;
                ListNode* tmp2=n2->next;
                n2->next=tmp1;
                n2=tmp2;
            }
            cur=cur->next;
        }
        if(n2){
            cur->next=n2;
        }
        
        return dummy->next;
        
    }
    

    
public:
         ListNode* mergeKLists1(vector<ListNode*>& lists) {
             ListNode * head=new ListNode(-1);
             ListNode * cur=head;
             int k=lists.size();
             int val_count=0;
             do{
                 val_count=0;
                 int cur_min=INT_MAX;
                 int index_min=0;
                 for(int i=0;i<k;i++)
                 {
                    if(lists[i]!=NULL)
                    {
                         val_count++;
                         if(lists[i]->val<cur_min){
                             cur_min=lists[i]->val;
                             index_min=i;
                         }
                     }
                 }
                 if(val_count>0){
                     cur->next=new ListNode(cur_min);
                     cur=cur->next;
                     lists[index_min]=lists[index_min]->next;
                 }
             }while(val_count>0);
    
             return head->next;
    
         }
    
          ListNode* mergeKLists2(vector<ListNode*>& lists) {
             if(lists.size()==0){
                 return NULL;
             }
    
             ListNode * dummy=new ListNode(-1);
             ListNode * cur=dummy;
             priority_queue<ListNode*, vector<ListNode*>,mycompare> q;
             for(int i=0;i<lists.size();i++){
                 if(lists[i]){
                     q.push(lists[i]);
                 }
             }
    
             while(!q.empty()){
                 ListNode * top=q.top();
                 q.pop();
                 cur->next=top;
                 cur=cur->next;
                 top=top->next;
                 if(top){
                     q.push(top);
                 }
             }
    
             return dummy->next;
         }
    
    
    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        while(lists.size()>=2){
            vector<ListNode*> helper;
            for(int i=0;i<lists.size();i+=2){
                if(i+1<lists.size()){
                    helper.push_back(merger(lists[i],lists[i+1]));
                }else{
                    helper.push_back(lists[i]);
                }
            }
            lists=helper;
        }
        
        return lists[0];
    }
};

ListNode *  buildListNode(vector<int> v){
    ListNode * head=new ListNode(-1);
    ListNode * cur=head;
    for(int i:v){
        cur->next=new ListNode(i);
        cur=cur->next;
    }
    return head->next;
}



void printListNode(ListNode * n){
    while (n) {
        cout<<n->val<<" ";
        n=n->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    vector<ListNode*> input;
    input.push_back(buildListNode({1,4,5}));
    input.push_back(buildListNode({1,3,4}));
    input.push_back(buildListNode({2,6}));
    
    Solution so=Solution();
    ListNode* ret=so.mergeKLists3(input);
    printListNode(ret);
    return 0;
}
