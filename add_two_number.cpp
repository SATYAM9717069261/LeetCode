#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};
void print(ListNode* list){
    if(list->next == NULL ){
        cout<<endl;
        return ;
    }else{
        cout<<" "<<list->val;
        print(list->next);
    }
}

class Solution{
        public: ListNode* solution(ListNode* l1, ListNode* l2){
                ListNode* startNode_l2 = new ListNode();
                ListNode* result = startNode_l2;
                int carry = 0;
                while(l1->next != NULL || l2->next != NULL){
                    int sum =carry;
                    if(l1->next != NULL){
                        sum += l1->val;
                        l1=l1->next;
                    }
                    if(l2->next != NULL){
                        sum += l2->val;
                        l2=l2->next;
                    }
                    startNode_l2->next=new ListNode();
                    startNode_l2->val = sum%10;
                    carry = sum/10;
                    startNode_l2=startNode_l2->next; 
                }
                if(carry == 1){
                    startNode_l2->next= new ListNode();
                    startNode_l2->val = 1;
                }
                return result;
            }
};

int main(){
    int size;cin>>size;
    ListNode* startNode = new ListNode();
    ListNode* l1 = startNode;
    for(int i=0;i<size;i++,startNode = startNode->next){
        int data; cin>>data;
        startNode->val = data;
        startNode->next = new ListNode();
    }
    ListNode* startNode_l2 = new ListNode();
    ListNode* l2 = startNode_l2;
    for(int i=0;i<size;i++,startNode_l2 = startNode_l2->next){
        int data; cin>>data;
        startNode_l2->val = data;
        startNode_l2->next = new ListNode();
    }
    Solution s;
    //print(l1);
    //print(l2);
    print(s.solution(l1,l2));

    return 0;
}
