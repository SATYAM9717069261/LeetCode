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
    ListNode* tail = head;
    cout<<endl;
    while(tail != nullptr){
        cout<<tail->val;
        tail=tail->next;
        if(tail != nullptr)
            cout<<"->";
    }
    cout<<endl;
}
class Solution {
    public: ListNode* rotateRight(ListNode* head, int k) {
                int count = 0;
                ListNode* tail = head;
                while(tail != nullptr){
                    count++;
                    tail = tail->next;
                }
                int totalRotation = k%count; 
                tail = head;
                ListNode* right = head;
                ListNode* left = head;
                for(int i=0;i<totalRotation;i++){
                    right = right->next;
                }
                while(right->next != nullptr){
                    right = right->next;
                    left = left->next;
                }

                right ->next = head;
                head = left->next;
                left->next = nullptr;

                return head;
            }
};
int main(){
    int limit; cin>>limit;
    int num; cin>>num; limit--;
    ListNode* head = new ListNode(num);
    ListNode* tail = head;
    while(limit--){
        int tmpValue; cin>>tmpValue;
        ListNode* tmp = new ListNode(tmpValue);
        tail->next = tmp;
        tail = tail->next;
    }
    cout<<" Before =>";
    print(head);
    int rotate; cin>>rotate;
    Solution sol;
    head = sol.rotateRight(head,rotate);
    cout<< " After =>";
    print(head);
    return 0;
}
