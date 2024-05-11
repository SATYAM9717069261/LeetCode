#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head){
    if(head->next == nullptr){
        cout<<head->val<<" ";
        return;
    }else{
        cout<<head->val<<" ";
        print(head->next);
    }
    return;
}

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        if(curr->val > 4){
            head = new ListNode(1,head);
        }

        while(curr){
            int doubled = curr->val * 2;
            if(prev && doubled >= 10){
                prev->val++;
            }
            curr->val = doubled%10;
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};

/// class Solution{
///     private: void print(ListNode* head){
///                  if(head->next == nullptr){
///                      cout<<head->val<<" ";
///                      return;
///                  }else{
///                      cout<<head->val<<" ";
///                      print(head->next);
///                  }
///                  return;
///              }
///              int addition(ListNode* head){
///                  if(head->next == nullptr){
///                      int sum = head->val + head->val;
///                      head->val = sum%10;
///                      return sum/10; 
///                  }else{
///                      int carry = addition(head->next);
///                      int sum = carry + head->val + head->val;
///                      head->val = sum%10;
///                      return sum/10;
///                  }
///              }
///     public: ListNode* doubleIt(ListNode* head){
///                 int carry = addition(head);
///                 if(carry != 0){ 
///                     ListNode* newHead = new ListNode(carry);
///                     newHead->next = head;
///                     head = newHead;
///                 }
///                 cout<<"carry =>"<<carry<<endl;
///                 print(head);
///                 return head;
///             }
/// };


int main(){
    int element; cin>>element;
    int data; cin>>data;
    ListNode* head = new ListNode(data);
    ListNode* tmp = head;
    element--;
    element --;
    while(element--){
        cin>>data;
        tmp->next = new ListNode(data);
        tmp = tmp->next;
    }
    Solution sol;
    print(sol.doubleIt(head));
    return 0;
}

