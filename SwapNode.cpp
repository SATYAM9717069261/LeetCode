#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int num){ 
        this->val = num;
        this->next = NULL;
    }
};
class Solution{
    public: Node* solution(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return head; // No need to swap if list is empty or has only one node
        
        Node* dummy = new Node(0); // Dummy node to handle head swapping
        dummy->next = head;
        Node* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            Node* first = prev->next;
            Node* second = first->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Moving to next pair
            prev = first;
        }

        head = dummy->next; // Update head in case it's changed
        delete dummy; // Delete dummy node

        return head;           
            }

            void Print(Node* head){
                 Node* tmp = head;
                 while(tmp->next != NULL){
                     cout<<tmp->val<<" ";
                     tmp = tmp->next;
                 }
                     cout<<tmp->val<<endl;
             }

};

int main(){
    int size; cin>>size;
    int num;
    cin>>num;
    Node* head = new Node(num);
    Node* tail = head;
    while(--size){
        cin>>num;
        Node* tmp = new Node(num);
        tail->next = tmp;
        tail = tmp;
    }
    int delIndex; cin>>delIndex;
    Solution sol;
    sol.solution(head);
    return 0;
}


