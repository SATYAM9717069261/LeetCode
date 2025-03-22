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
    ListNode* tmp = head;
    while(tmp != nullptr){
        cout<<tmp->val <<" ";
        tmp = tmp->next;
    }
}
class Solution {
    public: ListNode* reverseBetween(ListNode* finalhead, int left, int right) {
                if (left == right) 
                    return finalhead;

                ListNode dummy(0);
                dummy.next = head;
                ListNode* prev = &dummy;

                // Move `prev` to the node before the `left`-th node
                for (int i = 1; i < left; ++i) {
                    prev = prev->next;
                }

                ListNode* start = prev->next; // `start` will be the `left`-th node
                ListNode* then = start->next; // `then` will be the node after `start`

                // Reverse the nodes between `left` and `right`
                for (int i = 0; i < right - left; ++i) {
                    start->next = then->next;
                    then->next = prev->next;
                    prev->next = then;
                    then = start->next;
                }

                return dummy.next;
            }
};
int main(){
    int num;cin>>num;
    ListNode* head = nullptr;
    ListNode* tail = head;
    while(num--){
        int tmp; cin>>tmp; 
        if(head == nullptr){
            head = new ListNode(tmp);
            tail = head;
        }else{
            tail -> next = new ListNode(tmp);
            tail = tail->next; 
        }
    }
    int left; cin>>left;
    int right; cin>>right;

    Solution sol;
    sol.reverseBetween(head,left,right);
    print(head);
    return 0;
}
