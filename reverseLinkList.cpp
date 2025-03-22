#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* list){
    ListNode* tmp = list;
    while(tmp != nullptr){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
}

class Solution{
    public: vector<ListNode> reverseList(ListNode* list, int count){
                ListNode* head = list;
                ListNode* first  = nullptr;
                ListNode* second = nullptr;
                ListNode* third = head;

                while(third != nullptr && count >= 0){
                    if(first != nullptr && second != nullptr){
                        first -> next = third;
                        second-> next = head;
                        head = second;

                        second = third;
                        third = third->next;
                    }else{
                        first = second;
                        second = third;
                        third = third -> next;
                    }
                    count--;
                }
                if(count == 0 && third == nullptr){
                    second -> next = head;
                    head = second;
                    first->next = nullptr;
                }
                return {head,third};
            }
            ListNode* reversePairList(ListNode* list, int count){
                ListNode* tmpList = list;
                ListNode* ans = new ListNode(nullptr);
                int tmp_count = 1;
                ListNode* start = nullptr;
                cout<<"Initial =>";
                print(list);
                cout<<endl;

                while(list != nullptr){
                    if(tmp_count == 1){
                       start = list; 
                    }
                    if(tmp_count == count){
                        tmpList = list->next;
                        list->next = nullptr;
                        cout<<"COUnt =>"<<list->val<<"  start => "<<tmpList->val << " ++> ";
                        ListNode* head ;
                        ListNode* tail;
                        vector<ListNode> returnList = reverseList(start, count);
                        head = returnList[0];
                        if(ans == nullptr)
                            ans = head;
                        else
                            tail = head;

                        tail = returnList[1];

                        print(ans);
                        cout<<endl;
                        tmp_count = 1;
                        list = tmpList;
                    }else{
                        tmp_count++;
                        list=list->next;
                    }
                }
                return list;
            }
};
int main(){
    int tmp; cin>>tmp;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while(tmp--){
        int num; cin>>num;
        if(head == nullptr){
            head = new ListNode(num);
            tail = head;
        }else{
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }
    Solution sol;
    int rev; cin>>rev;
    sol.reversePairList(head,rev);
    return 0;
}
