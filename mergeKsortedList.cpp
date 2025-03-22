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
    public: ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
                ListNode* tmplist1 = list1;
                ListNode* tmplist2 = list2;
                ListNode* lastEle = nullptr;
                while(tmplist1 != nullptr && tmplist2 != nullptr){
                    if( tmplist1->val  > tmplist2->val){
                        ListNode* tmphead = tmplist1;
                        tmplist1 = tmplist2;
                        tmplist2 = tmplist2->next;
                        tmplist1->next = tmphead;
                        if(lastEle != nullptr)
                            lastEle->next = tmplist1;
                        else
                            list1 = tmplist1;
                    }
                    lastEle = tmplist1;
                    tmplist1 = tmplist1->next;
                }

                if(tmplist2 != nullptr){
                    lastEle->next = tmplist2;
                }
                return list1;
            }

            ListNode* mergeKList(vector<ListNode*>& arr){
                int size = arr.size();
                if(size == 0)
                    return nullptr;
                int start =0;
                while(start < size && arr[start] == nullptr)
                    start++;
                for(int i=start+1;i<size;i++){
                    arr[start] = mergeTwoLists(arr[start],arr[i]);
                }

                print(arr[start]);
                return arr[start];
            }
};
int main(){
    int size; cin>>size;
    vector<ListNode*> arr;
    while(size--){
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
        arr.push_back(head);
        cout<<endl;
    }
    Solution sol;
    sol.mergeKList(arr);
    return 0;
}
