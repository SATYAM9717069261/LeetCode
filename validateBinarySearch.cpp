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
    private: bool check(TreeNode* root, int start = INT_MIN, int end = INT_MAX){
                 if(root == nullptr)
                     return true;
                 if( (root->val > start && root->val < end) && (root->left == nullptr || (root->left->val < root->val ) ) && (root->right == nullptr || (root->right->val > root->val))   ) {
                     return check(root->left,start,root->val) && check(root->right,root->val,end);
                 }
                 return false;
             }
    public: bool isValidBST(TreeNode* root) {
                return check(root);
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
   bool ans = sol.isValidBST(root);
   cout<<" asn =>"<<ans;

    return 0;
}
