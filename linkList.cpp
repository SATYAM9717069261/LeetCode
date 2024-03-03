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
    public: Node* solution(Node* head, int num){
                Node* tmp = head;
                Node* nthNode = head;
                int n = num;
                n++;
                while(--n && tmp->next != NULL)
                    tmp=tmp->next;
                while(tmp->next != NULL){ 
                    nthNode = nthNode -> next; 
                    tmp = tmp->next; 
                }

                cout<<"Nth Head =>"<<n<<endl;
                    cout<<"Nth  Node ";
                    Solution::Print(nthNode);
                    cout<<endl;
                    cout<<"tmp Node ";
                    Solution::Print(tmp);
                if( n == 1) // handle 1st Node deletion
                    head = head->next;
                if(n == 0 )
                    nthNode -> next = nthNode -> next -> next;
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
    sol.Print(sol.solution(head,delIndex));
    return 0;
}


