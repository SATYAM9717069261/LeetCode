#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    private: pair<int,int> dfs(TreeNode* root){ // [with root, without root ]
                 if(root == nullptr)
                     return {0,0};
                 pair<int,int>compDataleft = dfs(root->left);
                 pair<int,int>compDataright = dfs(root->right);
                 int withRoot = root->val + compDataleft.second + compDataright.second;
                 int withoutRoot =  max(compDataleft.first,compDataleft.second) + max(compDataright.first,compDataright.second);
                 return {withRoot,withoutRoot};
             }
    public:
             int rob(TreeNode* root) {
                 pair<int,int> ans = dfs(root);
                 return max(ans.first,ans.second);
             }

        TreeNode* insert(vector<int>& array, int size, int currentIndex){
            if(currentIndex >= size)
                return nullptr;
            TreeNode* root = new TreeNode(array[currentIndex]);
            root->left = insert(array,size,2*(currentIndex) + 1);
            root->right = insert(array,size,2*(currentIndex) + 2);
            return root;
        }
        void print(TreeNode* root){
            cout<<root->val;
            if(root->left != nullptr){
                print(root->left);
            }
            if(root->right != nullptr){
                print(root->right);
            }
        }
};

int main(){
    int num ; cin>>num; 
    TreeNode* root;
    vector<int> arr;
    while(num--){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    root = sol.insert(arr,arr.size(),0);
    int ans = sol.rob(root);
    cout<<" ANS =>"<<ans; 
    //sol.print(root);
    return 0; 
}
