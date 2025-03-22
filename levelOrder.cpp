/**
 * Definition for a binary tree node.
 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private: void ans(TreeNode* root, vector<vector<int>>& data, int level){
                 if(root == nullptr){
                     data[level].push_back({});
                     return;
                 }
                 if(data.size() == level){
                     data.push_back({});
                 }

                 data[level].push_back(root->val);
                 ans(root->left,data,level+1);
                 ans(root->right,data,level+1);
                
             }
    public: vector<vector<int>> levelOrder(TreeNode* root) {
                vector<vector<int>> data;
                ans(root,data,0);

                int index = 0;
                for(vector<int> i: data){
                    index++;
                    if(index%2 != 0){
                        reverse(i.begin(),i.end());
                    }
                }

                for(vector<int> i: data){
                    cout<<"[";
                    for(int j: i){
                        cout<<j<<", ";
                    }
                    cout<<"]"<<endl;
                }
                return data;
            }
};


TreeNode* makeTree(vector<int>& arr, int ind = 0){
    if(ind < arr.size()){
        TreeNode* root = new TreeNode(arr[ind]);
        root->left = makeTree(arr,(2*ind)+1);
        root->right = makeTree(arr,(2*ind)+2);
        return root;
    }
    return nullptr;
}
void printTree(TreeNode* root){
    if(root == nullptr){
        cout<<" NULL "<<endl;
        return;
    }
    cout<<root->val;
    printTree(root->left);
    printTree(root->right);
}
int main(){ 
    int size; cin>>size;
    vector<int> arr;
    while(size--){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    TreeNode* root= makeTree(arr,0);
    Solution sol;
    sol.levelOrder(root);
    return 0;
}
